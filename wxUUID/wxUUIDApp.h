/*
 *	wxUUIDApp.h
 *	wxUUID
 *
 *	Created by Casey O'Donnell on Tue Mar 30 2004.
 *	Copyright (c) 2004 Casey O'Donnell. All rights reserved.
 *
 */

// wxUUIDApp.h: interface for the wxUUIDApp class.
//
//////////////////////////////////////////////////////////////////////

#ifndef _WXUUIDAPP_H__INCLUDED_
#define _WXUUIDAPP_H__INCLUDED_

#include <wx/app.h>

class wxUUIDApp : public wxApp
{
public:
	wxUUIDApp();
	virtual ~wxUUIDApp();

	// Override Base Class Virtuals

	// this one is called on application startup and is a good place for the app
	// initialization (doing it here and not in the ctor allows to have an error
	// return: if OnInit() returns false, the application terminates)
	virtual bool OnInit();

protected:

private:

};

DECLARE_APP(wxUUIDApp)

#endif // _WXUUIDAPP_H__INCLUDED_


