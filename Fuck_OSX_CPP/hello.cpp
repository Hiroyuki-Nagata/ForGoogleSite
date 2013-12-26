//============================================================================
// Name        : HelloWorld.cpp
// Author      : Hiroyuki Nagata
// Version     : 1.0.0
// Copyright   : Copyright (C) 2012 Hiroyuki Nagata, All rights reserved.
// Description : Hello World in wxWidgets with Japanese
// Licence     : wxWindows Library Licence, Version 3.1
//============================================================================

#include "hello.hpp"

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

     try

     {
 
	  const std::string userAgent = "Monazilla/1.00 Unknown";
	  const std::string outputPath = "./list.gzip";
	  const std::string url = "http://menu.2ch.net/bbsmenu.html";
 
	  std::list<std::string> headers;
	  headers.push_back("Accept-Encoding: gzip");
	  headers.push_back("Host: menu.2ch.net");
	  headers.push_back("Accept: ");
	  headers.push_back("Referer: http://menu.2ch.net/");
	  headers.push_back("Accept-Language: ja");
	  headers.push_back("User-Agent: " + userAgent);
 
	  curlpp::Cleanup myCleanup;
	  curlpp::Easy myRequest;
	  myRequest.setOpt(new curlpp::options::Url(url));
	  myRequest.setOpt(new curlpp::options::HttpHeader(headers));
	  myRequest.setOpt(new curlpp::options::Timeout(5));
	  myRequest.setOpt(new curlpp::options::Verbose(true));
 
	  // メインのデータ出力
	  std::ofstream ofs(outputPath, std::ios::out | std::ios::trunc | std::ios::binary );
	  curlpp::options::WriteStream ws(&ofs);
	  myRequest.setOpt(ws);
	  myRequest.perform();
 
     }
 
     catch( curlpp::RuntimeError &e )
     {
	  std::cout << e.what() << std::endl;
     }
 
     catch( curlpp::LogicError &e )
     {
	  std::cout << e.what() << std::endl;
     }
}

