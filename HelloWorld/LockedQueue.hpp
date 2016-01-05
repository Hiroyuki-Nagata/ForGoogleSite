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


template <class T>
struct wxLockedQueue {
     // Specify queue size at constructor
     explicit wxLockedQueue(int capacity)
	  :  capacity(capacity)
	  {}

     // Add x to queue
     void Enqueue(const T& x) {
	  m.Lock();
	  // Wait and blocking until somethings call #Broadcast or #Signal
	  // But, if the queue is full when called, wait and blocking
	  cEnq.Wait([this] { return data.size() != capacity; });
	  data.push_back(x);
	  // Broadcast finish preparing dequeue
	  cDeq.Broadcast();
     }

     // Take a element from queue
     T Dequeue() {
	  m.Lock();
	  // Wait and blocking until somethings call #Broadcast or #Signal
	  // But, if the queue is full when called, wait and blocking
	  cDeq.Wait([this] { return !data.empty(); });
	  T ret = data.front();
	  data.pop_front();
	  // Broadcast finish preparing enqueue
	  cEnq.Broadcast();
	  return ret;
     }

private:
     wxMutex m;
     std::deque<T> data;
     size_t capacity;
     wxCondition cEnq;
     wxCondition cDeq;
};
