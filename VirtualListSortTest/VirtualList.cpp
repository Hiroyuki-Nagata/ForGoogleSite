//============================================================================
// Name        : VirtualList.cpp
// Author      : Hiroyuki Nagata
// Version     : 1.0.0
// Copyright   : Copyright (C) 2012 Hiroyuki Nagata, All rights reserved.
// Description : virtual list sort test program in wxWidgets
// Licence     : wxWindows Library Licence, Version 3.1
//============================================================================

#include "VirtualList.hpp"

/**
 * コンストラクタ：
 * 構造体のリストをカラムとしてListCtrlに仕込む
 */
VirtualList::VirtualList(wxWindow* parent) :
     wxListCtrl(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize,
		wxLC_REPORT | wxLC_VIRTUAL) {

     // 文字列を用意して詰め込んでいく
     m_chars.push_back(CharacterInfo(wxT("1"), wxT("ハクオロ"), wxT("箱根のみなさ～ん")));
     m_chars.push_back(CharacterInfo(wxT("2"), wxT("エルルゥ"), wxT("好きって言ってにゃん")));
     m_chars.push_back(CharacterInfo(wxT("3"), wxT("アルルゥ"), wxT("くり")));
     m_chars.push_back(CharacterInfo(wxT("4"), wxT("クロウ"), wxT("浪川、頑張ってるよ、俺")));
     m_chars.push_back(CharacterInfo(wxT("5"), wxT("トウカ"), wxT("二次元が初恋じゃダメですか！？")));

     SetItemCount(m_chars.size());
     InsertColumn(COL_NUM, wxT("番号"));
     InsertColumn(COL_NAME, wxT("名前"));
     InsertColumn(COL_COMMENT, wxT("コメント"));

     // フラグの管理
     m_number_f = true;
}
/**
 * wxListCtrl備え付きの仮想関数 ： wxListCtrlを継承したクラスで仮想関数を実装することで使えるようになる
 * 指定されたアイテムとカラムに存在するテキストを返すことができる
 */
wxString VirtualList::OnGetItemText(long item, long column) const {

     wxString result = wxEmptyString;

     switch (column) {
     case COL_NUM:
	  result = m_chars[item].getNumber();
	  break;
     case COL_NAME:
	  result = m_chars[item].getName();
	  break;
     case COL_COMMENT:
	  result = m_chars[item].getComment();
	  break;
     default:
	  wxFAIL_MSG("Invalid column index in MyListCtrl::OnGetItemText");
     }

     return result;
}

void VirtualList::SortVector(long item, long column) {

     // ソートをかける
     wxMessageBox(wxT("ソートをかけます"));
     DeleteAllItems();

     this->m_number_f ? std::sort(m_chars.begin(), m_chars.end(), CharacterInfo::PredicateReverse)
                      : std::sort(m_chars.begin(), m_chars.end(), CharacterInfo::PredicateForward);
     this->m_number_f ? this->m_number_f = false
                      : this->m_number_f = true;

     SetItemCount(m_chars.size());
}
