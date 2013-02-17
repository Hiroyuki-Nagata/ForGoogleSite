/*
 * treectrltest.cpp
 *
 *  Created on: 2013/02/17
 *      Author: Hiroyuki Nagata
 */

#include "treectrltest.hpp"

BEGIN_EVENT_TABLE(TreeCtrlTest, wxFrame)
EVT_TREE_ITEM_ACTIVATED(wxID_ANY, TreeCtrlTest::OnDoubleClick)
END_EVENT_TABLE()

/**
 * フレームクラスのコンストラクタ
 */
TreeCtrlTest::TreeCtrlTest(wxWindow* parent, int id, const wxString& title, const wxPoint& pos, const wxSize& size, long style):
wxFrame(parent, id, title, pos, size, wxDEFAULT_FRAME_STYLE) {

     // 各種設定
     SetProperties();
     // wxAuiManagerの初期化
     m_mgr.SetManagedWindow(this);

     // Auiのペインを配置する
     wxSize client_size = GetClientSize();
     wxAuiNotebook* ctrl1 = new wxAuiNotebook(this, wxID_ANY,
					      wxPoint(client_size.x, client_size.y), 
					      wxSize(430, 200), 
					      wxAUI_NB_TOP | wxAUI_NB_TAB_SPLIT | wxAUI_NB_TAB_MOVE | wxAUI_NB_SCROLL_BUTTONS);
     // TreCtrlの設定
     SetTreeCtrl(ctrl1);
     ctrl1->AddPage(m_tree_ctrl, wxT("ツリーコントロール"), false);

     // wxAuiManagerに全ての変更を「コミットする」
     m_mgr.Update();
}
/**
 * TreeCtrlの設定
 */
void TreeCtrlTest::SetTreeCtrl(wxWindow* ctrl1) {
     /**
      * インスタンスの準備
      */
     m_tree_ctrl = new wxTreeCtrl(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 
				  wxTR_HAS_BUTTONS|wxTR_DEFAULT_STYLE|wxSUNKEN_BORDER);
     m_treeData = new wxTreeItemData();
     m_rootId = m_tree_ctrl->AddRoot(wxT("ルートフォルダ"), 0, 0, m_treeData);
}
/**
 * フレームクラスのデストラクタ
 */
TreeCtrlTest::~TreeCtrlTest() {
     // wxAuiManagerはデストラクタで破棄しなければいけない
     m_mgr.UnInit();
}
/**
 * 各種プロパティの設定
 */
void TreeCtrlTest::SetProperties() {

     // タイトルとサイズ
     SetTitle(_("TreeCtrlTest"));
     SetSize(wxSize(960, 640));

// アイコンの設定
#ifdef __WXMSW__
     SetIcon(wxICON(wxicon));
#else
     SetIcon(wxICON(wxicon));
#endif
}
/**
 * ダブルクリックされたら動く
 */
void TreeCtrlTest::OnDoubleClick(wxTreeEvent& event) {
     // ArtProviderを使うと、アイコンを読みこまなくても基本的なアイコンは使えるようになる
     wxImageList *treeImage = new wxImageList(16, 16);
     wxBitmap idx1 = wxArtProvider::GetBitmap(wxART_FOLDER,wxART_OTHER );
     wxBitmap idx2 = wxArtProvider::GetBitmap(wxART_NEW,wxART_OTHER);
     treeImage->Add(idx1);
     treeImage->Add(idx2);
     m_tree_ctrl->AssignImageList(treeImage);

     // 親要素
     wxArrayString array;
     array.Add(wxT("親要素１"));
     array.Add(wxT("親要素２"));
     array.Add(wxT("親要素３"));
     array.Add(wxT("親要素４"));
     array.Add(wxT("親要素５"));
     array.Add(wxT("親要素６"));

     // 子要素
     wxArrayString chArray;
     chArray.Add(wxT("子要素１"));
     chArray.Add(wxT("子要素２"));
     chArray.Add(wxT("子要素３"));
     chArray.Add(wxT("子要素４"));
     chArray.Add(wxT("子要素５"));

     for(int i=0;i < array.size();i++) {
	  wxTreeItemId test = m_tree_ctrl->AppendItem(m_rootId,array[i], 0, 0, m_treeData);
	  for (int j=0; j < chArray.size();j++) {
	       m_tree_ctrl->AppendItem(test, chArray[j], 1, 1, m_treeData);
	  }
     }
}
