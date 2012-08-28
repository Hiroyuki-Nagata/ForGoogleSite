//============================================================================
// Name        : HtmlWindowTest.h
// Author      : Hiroyuki Nagata
// Version     : 1.0.0
// Copyright   : Copyright (C) 2012 Hiroyuki Nagata, All rights reserved.
// Description : wxHtmlWindow test in wxWidgets with Japanese
// Licence     : wxWindows licence
//============================================================================

#ifndef HTMLWINDOWTEST_H_
#define HTMLWINDOWTEST_H_

#include <wx/wx.h>
#include <wx/combobox.h>
#include "HtmlContentWindow.h"

class HtmlWindowTest: public wxFrame {
public:
	HtmlWindowTest(const wxString& title);

	void OnQuit(wxCommandEvent& event);
	void OnAbout(wxCommandEvent& event);
	void OnChangeHtmlSource(wxCommandEvent& event);

private:
	wxComboBox* combo;
	HtmlContentWindow* htmlWin;

	DECLARE_EVENT_TABLE()
};

#endif /* HTMLWINDOWTEST_H_ */
