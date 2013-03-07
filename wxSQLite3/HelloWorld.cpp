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
     Minimal_Quit = wxID_EXIT, Minimal_About = wxID_ABOUT
};

BEGIN_EVENT_TABLE(HelloWorld, wxFrame)
EVT_MENU(Minimal_Quit, HelloWorld::OnQuit)
EVT_MENU(Minimal_About, HelloWorld::OnAbout)
END_EVENT_TABLE()

/**
 * wxFrameクラスのコンストラクタ
 */
HelloWorld::HelloWorld(const wxString& title) :
wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(640, 480)) {

     // メニューバーの設置
     wxMenu *fileMenu = new wxMenu;

     wxMenu *helpMenu = new wxMenu;
     helpMenu->Append(Minimal_About, wxT("&ヘルプ...\tF1"), wxT("このプログラムについて"));
     fileMenu->Append(Minimal_Quit, wxT("&終了\tAlt-X"), wxT("このプログラムを終了します"));

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
 * 閉じるを押した際のイベント
 */
void HelloWorld::OnQuit(wxCommandEvent& event) {
     Close(true);
}
/**
 * ヘルプを押した際のイベント
 */
void HelloWorld::OnAbout(wxCommandEvent& event) {

     wxMessageBox(wxT("wxSQLite3を起動します"));

     const wxString dbFile = wxGetCwd() + wxT("/test.db");

     try {
	  // データベースの初期化
	  wxSQLite3Database::InitializeSQLite();

	  wxSQLite3Database db;

	  wxMessageBox(wxT("SQLite3 Version:      ") + db.GetVersion());
	  wxMessageBox(wxT("SQLite3 Source Id:    ") + db.GetSourceId());

	  // DBを開く
	  db.Open(dbFile);
	  db.Close();

     } catch (wxSQLite3Exception& e) {
	  std::cerr << e.GetErrorCode() << ":" << (const char*) (e.GetMessage().mb_str()) << std::endl;
     }

     wxMessageBox(wxT("wxSQLite3でデータベースファイルを作成します"));

     try {
	  // データベースの初期化
	  wxSQLite3Database::InitializeSQLite();

	  wxSQLite3Database db;

	  // DBを開く
	  db.Open(dbFile);

	  // テーブルが無ければテーブルを作る
	  if (!db.TableExists(wxT("DIARY_USERS"))) {
	       db.ExecuteQuery(wxT("CREATE TABLE DIARY_USERS(OID TEXT, NAME TEXT, KANANAME TEXT)"));
	  }

	  // テーブル内にデータがあれば削除する
	  db.ExecuteQuery(wxT("DELETE FROM DIARY_USERS"));

	  // データの元ネタ用配列
	  wxArrayString array;

	  array.Add(wxT("('1','天野雪輝','あまの ゆきてる')"));
	  array.Add(wxT("('2','我妻由乃','がさい ゆの')"));
	  array.Add(wxT("('3','火山高夫','ひやま たかお')"));
	  array.Add(wxT("('4','来栖圭吾','くるす けいご')"));
	  array.Add(wxT("('5','豊穣礼佑','ほうじょう れいすけ')"));
	  array.Add(wxT("('6','春日野椿','かすがの つばき')"));
	  array.Add(wxT("('7','戦場マルコ','いくさば マルコ')"));
	  array.Add(wxT("('8','上下かまど','うえした かまど')"));
	  array.Add(wxT("('9','雨流みねね','うりゅう みねね')"));
	  array.Add(wxT("('10','月島狩人','つきしま かりゅうど')"));
	  array.Add(wxT("('11','ジョン・バックス','ジョン・バックス')"));
	  array.Add(wxT("('12','平坂黄泉','ひらさか よもつ')"));

	  // 12回繰り返す
	  for(int i=0;i < array.GetCount();i++)
	  {
	       wxString SQL_QUERY = wxT("INSERT INTO DIARY_USERS VALUES");
	       SQL_QUERY += array[i];

	       // デバッグ用文字列
	       std::cout << SQL_QUERY << std::endl;
	       db.ExecuteQuery(SQL_QUERY);
	  }

	  db.Close();

     } catch (wxSQLite3Exception& e) {
	  std::cerr << e.GetErrorCode() << ":" << (const char*) (e.GetMessage().mb_str()) << std::endl;
     }
}

