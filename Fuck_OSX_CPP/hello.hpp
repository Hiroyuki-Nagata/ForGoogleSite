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
#include <iostream>
#include <sstream>
#include <iostream>
#include <fstream>
 
#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>
#include <curlpp/Infos.hpp>

class HelloWorld: public wxFrame {
public:
	HelloWorld(const wxString& title);

	void OnQuit(wxCommandEvent& event);
	void OnAbout(wxCommandEvent& event);

private:
	DECLARE_EVENT_TABLE()
};

#endif /* HELLOWORLD_H_ */
