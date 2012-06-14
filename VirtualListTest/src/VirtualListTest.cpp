/*
 * VirtualListTest.cpp
 *
 *  Created on: 2012/06/15
 *      Author: learning
 */

#include "VirtualListTest.h"

VirtualListTest::VirtualListTest(wxWindow* parent, int id, const wxString& title, const wxPoint& pos, const wxSize& size, long style):
wxFrame(parent, id, title, pos, size, wxDEFAULT_FRAME_STYLE) {
	// wxAuiManagerの初期化
	m_mgr.SetManagedWindow(this);

	// Auiのペインを配置する
	wxSize client_size = GetClientSize();
	wxAuiNotebook* ctrl1 = new wxAuiNotebook(this, wxID_ANY,
			wxPoint(client_size.x, client_size.y), wxSize(430, 200));
	ctrl1->Freeze();

	// 仮想リストのインスタンスを作成しペインに配置する
	virtualList = new VirtualList(ctrl1);
	ctrl1->AddPage(virtualList, wxT("仮想リスト"), false);

	ctrl1->Thaw();

	// wxAuiManagerに全ての変更を「コミットする」
	m_mgr.Update();
}

VirtualListTest::~VirtualListTest() {
	// wxAuiManagerはデストラクタで破棄しなければいけない
	m_mgr.UnInit();
}

