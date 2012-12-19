package jp.gr.java_conf.nagata;

import java.util.TimerTask;

public class DoSomethingObject extends TimerTask {

    // コンストラクタ
    public DoSomethingObject() {}

    // 内部のプロパティ
    private String message;
    private String startMessage;
    private long interval;

    @Override
    public void run() {
	// タイマー実行時に呼ばれるメソッド
	System.out.println(message);
    }

    public String getMessage() {
        return message;
    }

    public void setMessage(String message) {
        this.message = message;
    }

    public String getStartMessage() {
        return startMessage;
    }

    public void setStartMessage(String startMessage) {
        this.startMessage = startMessage;
    }

    public void setInterval(long interval) {
	this.interval = interval;
    }

    public long getInterval() {
	return interval;
    }

}
