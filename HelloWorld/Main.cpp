//============================================================================
// Name        : Main.cpp
// Author      : Hiroyuki Nagata
// Version     : 1.0.0
// Copyright   : Copyright (C) 2012 Hiroyuki Nagata, All rights reserved.
// Description : Hello World in wxWidgets with Japanese
// Licence     : wxWindows Library Licence, Version 3.1
//============================================================================

#include <wx/wx.h>
#include <wx/cmdline.h>
#include "HelloWorld.h"

/** 再起動処理のために引数が与えられた場合使用する */
static const wxCmdLineEntryDesc gCmdLineDesc[] =
{
     // コマンドラインオプションに -p or pid=xxx と入力された場合
     { wxCMD_LINE_OPTION, wxT("p"), wxT("pid"), wxT("past worked JaneClone pid"), 
       wxCMD_LINE_VAL_NUMBER, wxCMD_LINE_PARAM_OPTIONAL },
     { wxCMD_LINE_NONE }
};

/**
 * wxAppのクラス宣言
 */
class MyApp: public wxApp {

public:
     HelloWorld* wxHelloWorld;
     virtual bool OnInit();
     virtual int OnExit();

     // 再起動時のコマンドライン読み込み用
     virtual void OnInitCmdLine(wxCmdLineParser& parser);
     virtual bool OnCmdLineParsed(wxCmdLineParser& parser);
private:
     long m_pid;
};

IMPLEMENT_APP(MyApp)

/**
 * wxAppの実装
 */
bool MyApp::OnInit() {

     // コマンドラインで与えられた引数を取得する
     if ((m_pid != 0) && (m_pid == wxGetProcessId())) {
	  wxMessageBox(wxT("wait wait"));
     }

     wxHelloWorld = new HelloWorld(wxT("wxWidgetsでHelloWorld!!"));
     wxHelloWorld->Show(true);

     return true;
}
/**
 * 終了後の後始末
 */
int MyApp::OnExit() {

     unsigned long pid = wxHelloWorld->pid;
     wxMessageBox(wxString::Format(wxT("pid: %lu"), pid));

     if (pid != 0) {
	  // 0でなければ再起動処理を行う & このプロセスは殺す
	  wxString execute = wxGetCwd() + wxT("/JaneClone");
	  ::wxExecute(execute + wxString::Format(_(" -p %lu"), pid), wxEXEC_ASYNC, NULL);
     }

     return 0;
}
/**
 * コマンドライン読み取りを初期化する
 */
void MyApp::OnInitCmdLine(wxCmdLineParser& parser) {
     // オプションの始まりはハイフン
     parser.SetDesc(gCmdLineDesc);
     parser.SetSwitchChars(wxT("-"));
}
/**
 * コマンドラインからパラメーターを読み取る
 */
bool MyApp::OnCmdLineParsed(wxCmdLineParser& parser) {
     parser.Found(wxT("p"), &m_pid);
     return true;
}
