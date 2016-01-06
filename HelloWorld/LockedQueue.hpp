// コードは以下のサイトから取得
// https://github.com/cpp-pocketref/sample-code/blob/master/008_thread/014_condition_variable.cpp

// Copyright (c) 2012-2013
// Akira Takahashi, Toshihiko Ando, Kohsuke Yuasa,
// Yusuke Ichinohe, Masaya Kusuda, wraith.
// Released under the CC0 1.0 Universal license.
#include <iostream>
#include <deque>
#include <thread>
#include <mutex>
#include <condition_variable>

template <class T>
struct LockedQueue {
     // コンストラクタに、キューの大きさを指定
     explicit LockedQueue(int capacity)
	  :  capacity(capacity)
	  {}

     // キューにxを加える
     void enqueue(const T& x) {
	  std::unique_lock<std::mutex> lock(m);
	  // 外からnotify_all()またはnotify_one()によって起こされるまでブロックして待つ
	  // ただし、起こされた時にキューが満杯だった場合は、またブロックして待つ
	  c_enq.wait(lock, [this] { return data.size() != capacity; });
	  data.push_back(x);
	  // dequeueの準備ができたことを通知
	  c_deq.notify_one();
     }

     // キューから要素を取り出す
     T dequeue() {
	  std::unique_lock<std::mutex> lock(m);
	  // 外からnotify_all()またはnotify_one()によって起こされるまでブロックして待つ
	  // ただし、起こされた時にキューが空である場合は、またブロックして待つ
	  c_deq.wait(lock, [this] { return !data.empty(); });
	  T ret = data.front();
	  data.pop_front();
	  // enqueueの準備ができたことを通知
	  c_enq.notify_one();
	  return ret;
     }

private:
     std::mutex m;
     std::deque<T> data;
     size_t capacity;
     std::condition_variable c_enq;
     std::condition_variable c_deq;
};

//
// ここからwxThreadを使ってみる
//
#include <wx/thread.h>

template <class T>
class wxLockedQueue {

public:
     // Specify queue size at constructor
     wxLockedQueue(int capacity, wxMutex* mutex, wxCondition* e, wxCondition* d) : capacity(capacity)
	  {
	       m = mutex;
	       cEnq = e;
	       cDeq = d;
	  }

     // Add x to queue
     void Enqueue(const T& x) {
	  m->Lock();
	  // Wait and blocking until somethings call #Broadcast or #Signal
	  // But, if the queue is full when called, wait and blocking
	  cEnq->Wait([this] { return data.size() != capacity; });
	  data.push_back(x);
	  // Broadcast finish preparing dequeue
	  cDeq->Broadcast();
     }

     // Take a element from queue
     T Dequeue() {
	  m->Lock();
	  // Wait and blocking until somethings call #Broadcast or #Signal
	  // But, if the queue is full when called, wait and blocking
	  cDeq->Wait([this] { return !data.empty(); });
	  T ret = data.front();
	  data.pop_front();
	  // Broadcast finish preparing enqueue
	  cEnq->Broadcast();
	  return ret;
     }

private:
     wxMutex* m;
     wxCondition* cEnq;
     wxCondition* cDeq;
     std::deque<T> data;
     size_t capacity;
};


//
// ワーカースレッド: キューに0, 1, 2, 3, 4を順番に入れる
//
template <class T>
class WorkerThread : public wxThread
{
public:
     WorkerThread(): wxThread(wxTHREAD_JOINABLE){};
     WorkerThread(wxLockedQueue<T> lq): wxThread(wxTHREAD_JOINABLE) { m_lq = lq; };
     ~WorkerThread();

     void worker(wxLockedQueue<T> lq) {
	  for (int i = 0; i < 5; ++i) {
	       lq.enqueue(i);
	       wxThread::This()->Sleep(1);
	  }
     }

protected:
     virtual ExitCode Entry();
     wxLockedQueue<T> m_lq;
};

// impl
template <class T>
wxThread::ExitCode WorkerThread<T>::Entry()
{
     while (!TestDestroy())
     {
	  // ... do a bit of work...
	  worker(m_lq);
     }

     return (wxThread::ExitCode)0;
}
