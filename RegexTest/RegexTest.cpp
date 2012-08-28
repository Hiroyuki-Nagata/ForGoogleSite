//============================================================================
// Name        : RegexTest.cpp
// Author      : Hiroyuki Nagata
// Version     : 1.0.0
// Copyright   : Copyright (C) 2012 Hiroyuki Nagata, All rights reserved.
// Description : regex test in wxWidgets with Japanese
// Licence     : wxWindows Library Licence, Version 3.1
//============================================================================

#include "RegexTest.h"

enum {
	wxID_TestRegex
};

BEGIN_EVENT_TABLE(RegexTest, wxFrame)
EVT_BUTTON(wxID_TestRegex, RegexTest::OnButtonTestRegex)
END_EVENT_TABLE()

RegexTest::RegexTest(const wxString& title) :
wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(940, 640)) {

	// フレームにパネルを載せる
	wxPanel *panel = new wxPanel(this, -1);
	wxBoxSizer *vbox = new wxBoxSizer(wxVERTICAL);

	m_tc1 = new wxTextCtrl(panel, wxID_ANY);
	vbox->Add(m_tc1, 1, wxEXPAND | wxLEFT | wxRIGHT | wxTOP, 10);

	m_tc2 = new wxTextCtrl(panel, wxID_ANY);
	vbox->Add(m_tc2, 1, wxEXPAND | wxLEFT | wxRIGHT, 10);

	// 説明とボタン
	wxBoxSizer *hbox = new wxBoxSizer(wxHORIZONTAL);
	wxStaticText *st = new wxStaticText(panel, wxID_ANY, wxT("URLにマッチするテキストを置換します：") + regexText);
	hbox->Add(st, 0);
	wxButton *btn = new wxButton(panel, wxID_TestRegex, wxT("正規表現のテスト"));
	hbox->Add(btn, 0);
	vbox->Add(hbox, 0, wxALIGN_RIGHT | wxRIGHT, 10);

	panel->SetSizer(vbox);

	// ステータスバーを設置する
	CreateStatusBar(2);
	SetStatusText(wxT("wxRegExクラスのテスト用アプリです"));

	// 初期文字列を設定する
	*m_tc1 << wxT(">>236<br>");
	*m_tc1 << wxT("あるやん<br>");
	*m_tc1 << wxT("http://up.null-x.me/poverty/img/poverty20830.jpg <br>");
	*m_tc1 << wxT("http://up.null-x.me/poverty/img/ <br>");
	*m_tc1 << wxT("http://up.null-x.me/poverty/img/poverty20832.jpg <br>");

	Centre();
}

void RegexTest::OnButtonTestRegex(wxCommandEvent& event) {
	wxMessageBox(wxT("変換対象テキスト：\n") + m_tc1->GetValue());
	wxRegEx ax;
	wxString text = m_tc1->GetValue();
	wxString tmp, result;
	size_t start, len;

	if (ax.Compile(regexText, wxRE_ADVANCED + wxRE_ICASE)) {
		for (tmp = text; ax.Matches(tmp); tmp = tmp.SubString(start+len, tmp.Len())) {
			ax.GetMatch(&start, &len, 0);
			result+=tmp.SubString(0, start-1);
			result+=wxT("<a href=\"");
			result+=tmp.SubString(start, start+len);
			result+=wxT("\"/>");
			result+=tmp.SubString(start, start+len);
			result+=wxT("</a>");

			wxMessageBox(wxT("マッチした部分：\n") + tmp.SubString(start, start+len));
		}
		result+=tmp;

	} else {
		wxMessageBox(wxT("有効な正規表現ではありません"));
	}

	// 結果を表示する
	m_tc2->SetValue(result);
}
