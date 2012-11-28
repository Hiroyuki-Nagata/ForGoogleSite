/*
 * VirtualList.cpp
 *
 *  Created on: 2012/06/15
 *      Author: learning
 */

#include "VirtualList.h"

/**
 * コンストラクタ：
 * 構造体のリストをカラムとしてListCtrlに仕込む
 */
VirtualList::VirtualList(wxWindow* parent) :
		wxListCtrl(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize,
				wxLC_REPORT | wxLC_VIRTUAL) {

	CharacterInfo ci;

	ci.number = wxT("１");
	ci.name = wxT("ハクオロ");
	ci.comment = wxT("箱根のみなさ～ん");
	m_chars.push_back(ci);
	ci.number = wxT("２");
	ci.name = wxT("エルルゥ");
	ci.comment = wxT("好きって言ってにゃん");
	m_chars.push_back(ci);
	ci.number = wxT("３");
	ci.name = wxT("アルルゥ");
	ci.comment = wxT("くり");
	m_chars.push_back(ci);
	ci.number = wxT("４");
	ci.name = wxT("クロウ");
	ci.comment = wxT("浪川、頑張ってるよ、俺");
	m_chars.push_back(ci);
	ci.number = wxT("５");
	ci.name = wxT("トウカ");
	ci.comment = wxT("二次元が初恋じゃダメですか！？");
	m_chars.push_back(ci);

	SetItemCount(m_chars.size());
	InsertColumn(COL_NUM, wxT("番号"));
	InsertColumn(COL_NAME, wxT("名前"));
	InsertColumn(COL_COMMENT, wxT("コメント"));
}
/**
 * wxListCtrl備え付きの仮想関数 ： wxListCtrlを継承したクラスで仮想関数を実装することで使えるようになる
 * 指定されたアイテムとカラムに存在するテキストを返すことができる
 */
wxString VirtualList::OnGetItemText(long item, long column) const {

	switch (column) {
	case COL_NUM:
		return m_chars[item].number;
	case COL_NAME:
		return m_chars[item].name;
	case COL_COMMENT:
		return m_chars[item].comment;
	default:
		wxFAIL_MSG("Invalid column index in MyListCtrl::OnGetItemText");
	}
	return "";
}
/**
 *  ラベル部分でのクリックイベント
 */
void VirtualList::Sort () {

     // 中身をソートする
     std::sort(m_chars.begin(),m_chars.end());
     
}

