package jp.gr.java_conf.nagata;

import java.util.ArrayList;
import java.util.Date;
import java.util.Timer;
import java.util.concurrent.TimeUnit;

import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

public class ObjectFactory {

    public static void main(String args[]) {
	// アプリケーションコンテキストの取得
	ApplicationContext contxt = new ClassPathXmlApplicationContext("applicationContext.xml");

	// Beanの取得
	ArrayList<DoSomethingObject> somethingList = new ArrayList<DoSomethingObject>();
	somethingList = (ArrayList<DoSomethingObject>)contxt.getBean("somethings");
	System.out.println("タイマー始まるお～：" + new Date());

	// タイマーオブジェクトの配列
	ArrayList<Timer> timers = new ArrayList<Timer>();

	// オブジェクトの数だけタイマー起動する
	for (int i = 0; i < somethingList.size(); i++) {
	    System.out.println(somethingList.get(i).getStartMessage());
	    System.out.println(somethingList.get(i).getInterval());
	    Timer t = new Timer();
	    t.schedule(somethingList.get(i), 0, somethingList.get(i).getInterval());
	    timers.add(t);
        }

	// 3分間待ってやろう
	System.out.println("10秒待ってやろう：" + new Date());
	try {
	    TimeUnit.SECONDS.sleep(10);
	} catch (InterruptedException e) {
	    e.printStackTrace();
	}

	// オブジェクトの数だけタイマーを止める
	for (int i = 0; i < somethingList.size(); i++) {
	    System.out.println(somethingList.get(i).getStartMessage());
        }

	for (int i = 0; i < timers.size(); i++) {
	    timers.get(i).cancel();
	}

	System.out.println("タイマーやめる。。。人間にはできることとできないことがある：" + new Date());
    }
}
