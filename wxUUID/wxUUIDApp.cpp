/*
 *	wxUUIDApp.cpp
 *	wxUUID
 *
 *	Created by Casey O'Donnell on Tue Mar 30 2004.
 *	Copyright (c) 2004 Casey O'Donnell. All rights reserved.
 *
 */

// wxUUIDApp.cpp: implementation of the wxUUIDApp class.
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

#include "wxUUIDApp.h"
#include "wxUUIDDlg.h"
#include "resource.h"

// Create a new application object: this macro will allow wxWindows to create
// the application object during program execution (it's better than using a
// static object for many reasons) and also declares the accessor function
// wxGetApp() which will return the reference of the right type (i.e. wxUUIDApp and
// not wxApp)
IMPLEMENT_APP(wxUUIDApp)

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

wxUUIDApp::wxUUIDApp()
{
}

wxUUIDApp::~wxUUIDApp()
{
}

//////////////////////////////////////////////////////////////////////
// 'Main Program' Equivalent - The App Starts Here
//////////////////////////////////////////////////////////////////////

bool wxUUIDApp::OnInit()
{
	wxXmlResource::Get()->InitAllHandlers();
	wxXmlResource::Get()->Load("resource/main_dialog.xrc");

	// create the main application window
	wxUUIDDialog *dialog = new	wxUUIDDialog(_("wxUUID"),
								wxPoint(50, 50), wxSize(400, 300));

	// and show it (the frames, unlike simple controls, are not shown when
	// created initially)
	dialog->Show(TRUE);
	SetTopWindow(dialog);

	// success: wxApp::OnRun() will be called which will enter the main message
	// loop and the application will run. If we returned FALSE here, the
	// application would exit immediately.
	return TRUE;
}

