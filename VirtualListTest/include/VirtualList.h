/*
 * VirtualList.h
 *
 *  Created on: 2012/06/15
 *      Author: learning
 */

#ifndef VIRTUALLIST_H_
#define VIRTUALLIST_H_

#include <wx/wx.h>
#include <wx/listctrl.h>

class VirtualList: public wxListCtrl{
	public:
		VirtualList(wxWindow* parent);
		wxString OnGetItemText(long item, long column) const;
};

#endif /* VIRTUALLIST_H_ */
