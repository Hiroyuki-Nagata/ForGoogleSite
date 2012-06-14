/*
 * VirtualList.cpp
 *
 *  Created on: 2012/06/15
 *      Author: learning
 */

#include "VirtualList.h"

VirtualList::VirtualList(wxWindow* parent):
wxListCtrl(parent,wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_REPORT|wxLC_VIRTUAL){

	// Add first column
	wxListItem col0;
	col0.SetId(0);
	col0.SetText( wxT("番号") );
	col0.SetWidth(300);
	InsertColumn(0, col0);

	// Add second column
	wxListItem col1;
	col1.SetId(1);
	col1.SetText( wxT("名前") );
	col1.SetWidth(50);
	InsertColumn(1, col1);

	// Add third column
	wxListItem col2;
	col2.SetId(2);
	col2.SetText( wxT("座右の銘") );
	col2.SetWidth(100);
	InsertColumn(2, col2);

	SetItemCount(0);
}

wxString VirtualList::OnGetItemText(long item, long column) const {
}



