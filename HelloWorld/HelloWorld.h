//============================================================================
// Name        : HelloWorld.h
// Author      : Hiroyuki Nagata
// Version     : 1.0.0
// Copyright   : Copyright (C) 2012 Hiroyuki Nagata, All rights reserved.
// Description : Hello World in wxWidgets with Japanese
// Licence     : wxWindows Library Licence, Version 3.1
//============================================================================

#ifndef HELLOWORLD_H_
#define HELLOWORLD_H_

#include <wx/wx.h>
#include "LockedQueue.hpp"

class HelloWorld: public wxFrame {

public:
     HelloWorld(const wxString& title);

     void OnQuit(wxCommandEvent& event);
     void OnRestart(wxCommandEvent& event);
     void OnAbout(wxCommandEvent& event);
     void OnTestLockedQueue(wxCommandEvent& event);

     // 再起動処理のためのPID
     unsigned long pid;
     // 再起動処理のためのフラグ
     static bool doRestart;

     wxTextCtrl* m_tc1;
     wxTextCtrl* m_tc2;

private:
     DECLARE_EVENT_TABLE()
};

#endif /* HELLOWORLD_H_ */
