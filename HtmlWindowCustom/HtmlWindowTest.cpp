//============================================================================
// Name        : HtmlWindowTest.cpp
// Author      : Hiroyuki Nagata
// Version     : 1.0.0
// Copyright   : Copyright (C) 2012 Hiroyuki Nagata, All rights reserved.
// Description : wxHtmlWindow test in wxWidgets with Japanese
// Licence     : wxWindows licence
//============================================================================

#include "HtmlWindowTest.h"

enum {
	Minimal_Quit = wxID_EXIT, Minimal_About = wxID_ABOUT, wxID_ComboBox
};

BEGIN_EVENT_TABLE(HtmlWindowTest, wxFrame)
EVT_MENU(Minimal_Quit, HtmlWindowTest::OnQuit)
EVT_MENU(Minimal_About, HtmlWindowTest::OnAbout)
EVT_TEXT(wxID_ComboBox, HtmlWindowTest::OnChangeHtmlSource)
EVT_HTML_CELL_HOVER(wxID_ANY, HtmlWindowTest::CellHover)
EVT_HTML_CELL_CLICKED(wxID_ANY, HtmlWindowTest::OnCellClicked)
EVT_HTML_LINK_CLICKED(wxID_ANY, HtmlWindowTest::OnLinkClicked)
END_EVENT_TABLE()

/**
 * wxFrameクラスのコンストラクタ
 */
HtmlWindowTest::HtmlWindowTest(const wxString& title) :
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

	// ウィンドウにウィジェットを敷き詰める
	wxPanel *panel = new wxPanel(this, -1);
	wxBoxSizer *vbox = new wxBoxSizer(wxVERTICAL);

	// 説明とコンボボックス
	wxBoxSizer *hbox = new wxBoxSizer(wxHORIZONTAL);
	wxStaticText *st = new wxStaticText(panel, wxID_ANY, wxT("右のトグルボタンでHTMLファイル切り替え　　"));
	hbox->Add(st, 0);
	const wxString choices[] = {wxT("sample01.html"), wxT("sample02.html"), wxT("sample03.html")};
	combo = new wxComboBox(panel, wxID_ComboBox, wxEmptyString, wxDefaultPosition, wxDefaultSize, 3, choices, wxCB_DROPDOWN, wxDefaultValidator, wxT("combobox"));
	hbox->Add(combo, 0);
	vbox->Add(hbox, 0, wxEXPAND | wxLEFT | wxRIGHT | wxTOP, 10);
	vbox->Add(-1, 10);

	// HtmlWindow
	htmlWin = new HtmlContentWindow(panel, wxT("sample01.html"));
	vbox->Add(htmlWin, 1, wxEXPAND | wxLEFT | wxRIGHT, 10);

	panel->SetSizer(vbox);

	// ステータスバーを設置する
	CreateStatusBar(2);
	SetStatusText(wxT("wxHtmlWindowのテスト用アプリケーションです"));

	Centre();
}
/**
 * 閉じるを押した際のイベント
 */
void HtmlWindowTest::OnQuit(wxCommandEvent& event) {
	Close(true);
}
/**
 * ヘルプを押した際のイベント
 */
void HtmlWindowTest::OnAbout(wxCommandEvent& event) {

wxMessageBox(wxString::Format(wxT("%sにようこそ!\n\n")
				wxT("これはwxHtmlWindowの動作検証用アプリケーションです\n")
				wxT("%s環境で動作しています"), wxVERSION_STRING, wxGetOsDescription()),
		wxT("このアプリケーションについて"), wxOK | wxICON_INFORMATION, this);
}
/**
 * コンボボックス変更時イベント処理
 */
void HtmlWindowTest::OnChangeHtmlSource(wxCommandEvent& event) {

	if (combo->GetValue() != wxEmptyString) {
		htmlWin->ReloadHtmlPage(combo->GetValue());
	}
}
/**
 * セル上をマウスカーソルがホバーしている時のイベント処理
 */
void HtmlWindowTest::CellHover(wxHtmlCellEvent& event) {
	wxHtmlCell* cell = event.GetCell();
	wxHtmlLinkInfo* linkInfo = cell->GetLink(cell->GetPosX(), cell->GetPosY());

	if (linkInfo) {
		if (linkInfo->GetHref() != wxEmptyString) {
			wxMessageBox(wxT("href:") + linkInfo->GetHref());
		}
	}
}
/**
 * 特定のセルがクリックされた時のイベント処理
 */
void HtmlWindowTest::OnCellClicked(wxHtmlCellEvent& event) {
	wxHtmlCell* cell = event.GetCell();
}
/**
 * リンクがクリックされた時のイベント処理
 */
void HtmlWindowTest::OnLinkClicked(wxHtmlLinkEvent& event) {

	const wxHtmlLinkInfo linkInfo = event.GetLinkInfo();
	if (linkInfo.GetHref() != wxEmptyString) {
		wxMessageBox(wxT("href:") + linkInfo.GetHref());
	}
}

