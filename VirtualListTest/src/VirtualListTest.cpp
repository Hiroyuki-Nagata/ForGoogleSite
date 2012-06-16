/*
 * VirtualListTest.cpp
 *
 *  Created on: 2012/06/15
 *      Author: learning
 */

#include "VirtualListTest.h"

// イベントテーブル
BEGIN_EVENT_TABLE(VirtualListTest, wxFrame)
// リストでのクリック
EVT_LIST_ITEM_FOCUSED(wxID_ANY, VirtualListTest::OnLeftClickAtListCtrl)
END_EVENT_TABLE()

/**
 * フレームクラスのコンストラクタ
 */
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
	// リストのカラムの幅を最大化する
	for (int i = 0; i < virtualList->GetColumnCount(); i++) {
		virtualList->SetColumnWidth(i, wxLIST_AUTOSIZE);
	}
	ctrl1->AddPage(virtualList, wxT("仮想リスト"), false);
	ctrl1->Thaw();

	// wxAuiManagerに全ての変更を「コミットする」
	m_mgr.Update();
}

/**
 * フレームクラスのデストラクタ
 */
VirtualListTest::~VirtualListTest() {
	// wxAuiManagerはデストラクタで破棄しなければいけない
	m_mgr.UnInit();
}

/**
 * リストコントロール上でクリックした時そのセルの値をとってくる
 */
void VirtualListTest::OnLeftClickAtListCtrl(wxListEvent& event) {

	// wxListCtrlはクリックしたインデックスの位置はわかっても、カラムの位置はわからない
	// よってマウスがクリックされた場所を割り出す必要がある
    wxPoint click_point=::wxGetMousePosition();
    wxPoint list_point=virtualList->GetScreenPosition();

    // delta x
    int dx=click_point.x - list_point.x;

    // work out the column
    int ex=0; // cumulative sum of column widths
    int col;
    for (col=0; col < virtualList->GetColumnCount(); col++) {
            ex += virtualList->GetColumnWidth(col);
            if (ex > dx) break;
    }

    // インデックスはイベントからすぐに割り出せる
	long index = event.GetIndex();
	wxString response = virtualList->OnGetItemText(index, (long)col);

	wxMessageBox(response);
}

