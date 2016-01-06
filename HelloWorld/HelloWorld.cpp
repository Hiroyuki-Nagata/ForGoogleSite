//============================================================================
// Name        : HelloWorld.cpp
// Author      : Hiroyuki Nagata
// Version     : 1.0.0
// Copyright   : Copyright (C) 2012 Hiroyuki Nagata, All rights reserved.
// Description : Hello World in wxWidgets with Japanese
// Licence     : wxWindows Library Licence, Version 3.1
//============================================================================

#include "HelloWorld.h"

enum {
     Minimal_Quit = 1,
     Minimal_About,
     Minimal_Restart
};

BEGIN_EVENT_TABLE(HelloWorld, wxFrame)
EVT_MENU(wxID_EXIT, HelloWorld::OnQuit)
EVT_MENU(Minimal_Quit, HelloWorld::OnQuit)
EVT_MENU(Minimal_Restart, HelloWorld::OnRestart)
EVT_MENU(Minimal_About, HelloWorld::OnAbout)
END_EVENT_TABLE()

bool HelloWorld::doRestart = false;

/**
 * wxFrameクラスのコンストラクタ
 */
HelloWorld::HelloWorld(const wxString& title) :
wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(640, 480)) {

     // メニューバーの設置
     wxMenu *fileMenu = new wxMenu;
     wxMenu *helpMenu = new wxMenu;
     helpMenu->Append(Minimal_About, wxT("&ヘルプ..."), wxT("このプログラムについて"));
     fileMenu->Append(Minimal_Restart, wxT("&再起動"), wxT("このプログラムを再起動します"));
     fileMenu->Append(Minimal_Quit, wxT("&終了"), wxT("このプログラムを終了します"));

     wxMenuBar *menuBar = new wxMenuBar();
     menuBar->Append(fileMenu, wxT("&ファイル"));
     menuBar->Append(helpMenu, wxT("&ヘルプ"));

     SetMenuBar(menuBar);

     // ステータスバーを設置する
     CreateStatusBar(2);
     SetStatusText(wxT("wxWidgetsにようこそ!"));

     Centre();
}
/**
 * 終了
 */
void HelloWorld::OnQuit(wxCommandEvent& event) {
     Close(true);
}
/**
 * 再起動
 */
void HelloWorld::OnRestart(wxCommandEvent& event) {
     doRestart = true;
     Close(true);
}
/**
 * ヘルプを押した際のイベント
 */
void HelloWorld::OnAbout(wxCommandEvent& event) {

     wxString message = wxVERSION_STRING;
     message += wxT("にようこそ!\n\nこれはwxWidgetsの最小アプリです\n");
     message += wxGetOsDescription();
     message += wxT("環境で動作しています\n\n");
     message += wxGetHomeDir();

     wxMessageBox(message, wxT("このアプリケーションについて"), wxOK | wxICON_INFORMATION, this);
}
