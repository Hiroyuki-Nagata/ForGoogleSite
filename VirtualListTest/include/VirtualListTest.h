/*
 * VirtualListTest.h
 *
 *  Created on: 2012/06/15
 *      Author: learning
 */

#ifndef VIRTUALLISTTEST_H_
#define VIRTUALLISTTEST_H_

#include <wx/wx.h>
#include <wx/aui/aui.h>
#include <wx/listctrl.h>
#include "VirtualList.h"

/**
int wxCALLBACK
MyCompareFunction(wxIntPtr item1, wxIntPtr item2, wxIntPtr WXUNUSED(sortData))
{
    // inverse the order
    if (item1 < item2)
        return 1;
    if (item1 > item2)
        return -1;

    return 0;
}
*/

class VirtualListTest: public wxFrame {
 public:
  VirtualListTest(wxWindow* parent, int id, const wxString& title,
		  const wxPoint& pos = wxDefaultPosition, const wxSize& size =
		  wxDefaultSize, long style = wxDEFAULT_FRAME_STYLE);

  ~VirtualListTest();

  // 左クリックイベント
  void OnLeftClickAtListCtrl(wxListEvent& event);
  // ラベル部分でのクリックイベント
  void OnLeftClickAtListCtrlCol(wxListEvent& event);

 private:
  wxAuiManager m_mgr;
	
  VirtualList* virtualList;

  DECLARE_EVENT_TABLE()
    };

#endif /* VIRTUALLISTTEST_H_ */
