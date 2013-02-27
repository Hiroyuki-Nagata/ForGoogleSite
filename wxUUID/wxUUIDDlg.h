/*
 *	wxUUIDDlg.h
 *	wxUUID
 *
 *	Created by Casey O'Donnell on Tue Mar 30 2004.
 *	Copyright (c) 2004 Casey O'Donnell. All rights reserved.
 *
 */

// wxUUIDDlg.h: interface for the wxUUIDDialog class.
//
//////////////////////////////////////////////////////////////////////

#ifndef _WXUUIDDIALOG_H__INCLUDED_
#define _WXUUIDDIALOG_H__INCLUDED_

#include <wx/dialog.h>
#include <wx/utils.h>

class wxUUIDDialog : public wxDialog
{
public:
	wxUUIDDialog(const wxString& title, const wxPoint& pos, const wxSize& size);
	virtual ~wxUUIDDialog();

	// Event Handlers (These Functions Should NOT be Virtual)
	void OnButtonClose(wxCommandEvent& event);
	void OnQuit(wxCloseEvent& event);
	void OnAbout(wxCommandEvent& event);

	void OnVersion1(wxCommandEvent& event);
	void OnVersion2(wxCommandEvent& event);
	void OnVersion3(wxCommandEvent& event);

	void OnStress(wxCommandEvent& event);

protected:

private:
	DECLARE_CLASS(wxUUIDDialog)
	// any class wishing to process wxWindows events must use this macro
	DECLARE_EVENT_TABLE()
};

#endif // _WXUUIDDIALOG_H__INCLUDED_
