//============================================================================
// Name        : VirtualListTest.hpp
// Author      : Hiroyuki Nagata
// Version     : 1.0.0
// Copyright   : Copyright (C) 2012 Hiroyuki Nagata, All rights reserved.
// Description : virtual list sort test program in wxWidgets
// Licence     : wxWindows Library Licence, Version 3.1
//============================================================================

#ifndef VIRTUALLISTTEST_HPP_
#define VIRTUALLISTTEST_HPP_

#include <wx/wx.h>
#include <wx/aui/aui.h>
#include <wx/listctrl.h>
#include "VirtualList.hpp"

class VirtualListTest: public wxFrame {
public:
     VirtualListTest(wxWindow* parent, int id, const wxString& title,
		     const wxPoint& pos = wxDefaultPosition, const wxSize& size =
		     wxDefaultSize, long style = wxDEFAULT_FRAME_STYLE);

     ~VirtualListTest();

     // 左クリックイベント
     void OnLeftClickAtListCtrl(wxListEvent& event);
     // リストのヘッダ部分でのクリック
     void OnLeftClickAtListHeader(wxListEvent& event);

private:
     wxAuiManager m_mgr;
     VirtualList* virtualList;

     DECLARE_EVENT_TABLE()
};

#endif /* VIRTUALLISTTEST_HPP_ */
