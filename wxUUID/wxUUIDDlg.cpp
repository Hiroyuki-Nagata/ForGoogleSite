/*
 *	wxUUIDDlg.cpp
 *	wxUUID
 *
 *	Created by Casey O'Donnell on Tue Mar 30 2004.
 *	Copyright (c) 2004 Casey O'Donnell. All rights reserved.
 *
 */

// wxUUIDDlg.cpp: implementation of the wxUUIDDialog class.
//
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
// Headers
//////////////////////////////////////////////////////////////////////
#include "wx/wxprec.h"

#ifndef WX_PRECOMP
	#include "wx/wx.h"
#endif
#include <wx/xrc/xmlres.h>

#include <math.h>
#include <wx/progdlg.h>
#include <wx/textctrl.h>

#include "wxUUIDApp.h"
#include "wxUUIDDlg.h"

#include "wxUUID.h"
#include "wxGUID.h"

//////////////////////////////////////////////////////////////////////
// Resources
//////////////////////////////////////////////////////////////////////
// the application icon
#if defined(__WXGTK__) || defined(__WXMOTIF__)
	#include "wxUUID.xpm"
#endif

//////////////////////////////////////////////////////////////////////
// Constants
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
// Event Tables and Other Macros for wxWindows
//////////////////////////////////////////////////////////////////////

// the event tables connect the wxWindows events with the functions (event
// handlers) which process them. It can be also done at run-time, but for the
// simple menu events like this the static method is much simpler.
IMPLEMENT_CLASS(wxUUIDDialog, wxDialog)
BEGIN_EVENT_TABLE(wxUUIDDialog, wxDialog)
	EVT_BUTTON(XRCID("file_menu_exit"), wxUUIDDialog::OnButtonClose)
	EVT_BUTTON(XRCID("help_menu_about"), wxUUIDDialog::OnAbout)
	EVT_BUTTON(XRCID("version1_button"), wxUUIDDialog::OnVersion1)
	EVT_BUTTON(XRCID("version2_button"), wxUUIDDialog::OnVersion2)
	EVT_BUTTON(XRCID("version3_button"), wxUUIDDialog::OnVersion3)
	EVT_BUTTON(XRCID("stress_button"), wxUUIDDialog::OnStress)
	EVT_CLOSE(wxUUIDDialog::OnQuit)
END_EVENT_TABLE()

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

wxUUIDDialog::wxUUIDDialog(const wxString& title, const wxPoint& pos, const wxSize& size)
{
	wxXmlResource::Get()->LoadDialog(this, NULL, "main_dialog");
	SetTitle(title);

	// set the Dialog icon
	SetIcon(wxICON(wxUUID));
}

// Dialog destructor
wxUUIDDialog::~wxUUIDDialog()
{
}

//////////////////////////////////////////////////////////////////////
// Event Handlers
//////////////////////////////////////////////////////////////////////

void wxUUIDDialog::OnQuit(wxCloseEvent& event)
{
	Destroy();
}

void wxUUIDDialog::OnButtonClose(wxCommandEvent& event)
{
	Destroy();
}

void wxUUIDDialog::OnAbout(wxCommandEvent& event)
{
}

void wxUUIDDialog::OnVersion1(wxCommandEvent& event)
{
	wxTextCtrl* pText = XRCCTRL(*this, "uuid_text_ctrl", wxTextCtrl);

	if(pText)
	{
		pText->SetValue(wxUUID::GetUUID());
	}
}

void wxUUIDDialog::OnVersion2(wxCommandEvent& event)
{
	wxTextCtrl* pText = XRCCTRL(*this, "uuid_text_ctrl", wxTextCtrl);

	if(pText)
	{
		wxGUID guid;
		pText->SetValue(guid.ToString());
	}
}

void wxUUIDDialog::OnVersion3(wxCommandEvent& event)
{
}

void wxUUIDDialog::OnStress(wxCommandEvent& event)
{
	int iCOUNT = 1000;
	int iCompare = (iCOUNT * (iCOUNT + 1))/2;
	int iVal = 0;

	wxProgressDialog dlg(_T("wxUUID Stress Test"), _T("Generating GUIDs..."), iCOUNT + iCompare, this);

	wxArrayString arrGUID;

	arrGUID.Alloc(iCOUNT);

	bool bEqual = false;

	for(int i = 0; i < iCOUNT; i++)
	{
		wxString szGUID = wxUUID::GetUUID();

		arrGUID.Add(szGUID);

		wxMilliSleep(2);

		dlg.Update(iVal++);
	}

	dlg.Update(iVal, _T("Comparing GUIDs..."));

	for(int j = 0; j < iCOUNT; j++)
	{
		for(int k = j+1; k < iCOUNT; k++)
		{
			wxString szGUID1 = arrGUID[j];
			wxString szGUID2 = arrGUID[k];

			if(arrGUID[j] == arrGUID[k])
			{
				bEqual = true;
				break;
			}

			dlg.Update(iVal++);
		}
	}

	if(bEqual)
		wxMessageBox(_T("We had two equal GUIDs...\n\nUh, oh!"), _T("GUID F*CKUP"), wxICON_ERROR|wxOK, this);
}
