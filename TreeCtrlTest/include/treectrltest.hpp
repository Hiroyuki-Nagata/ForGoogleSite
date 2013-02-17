/*
 * treectrltest.hpp
 *
 *  Created on: 2013/02/17
 *      Author: Hiroyuki Nagata
 */

#ifndef TREECTRLTEST_HPP_
#define TREECTRLTEST_HPP_

#include <wx/wx.h>
#include <wx/treectrl.h>
#include <wx/artprov.h>
#include <wx/aui/aui.h>

class TreeCtrlTest : public wxFrame {


public:
     TreeCtrlTest(wxWindow* parent, int id, const wxString& title,
		     const wxPoint& pos = wxDefaultPosition, const wxSize& size =
		     wxDefaultSize, long style = wxDEFAULT_FRAME_STYLE);
     ~TreeCtrlTest();

private:

     void SetProperties();
     void SetTreeCtrl(wxWindow* parent);
     void OnDoubleClick(wxTreeEvent& event);

     // aui
     wxAuiManager m_mgr;

     // treectrl
     wxTreeCtrl* m_tree_ctrl;
     wxTreeItemData* m_treeData;
     wxTreeItemId m_rootId;

     DECLARE_EVENT_TABLE()
};

#endif /* TREECTRLTEST_HPP_ */
