//============================================================================
// Name        : HelloWorld.h
// Author      : http://nantonaku-shiawase.hatenablog.com/
// Version     : 1.0.0
// Copyright   : Common Public License
// Description : Hello World in wxWidgets with Japanese
//============================================================================

#ifndef HELLOWORLD_H_
#define HELLOWORLD_H_

#include <wx/wx.h>

class HelloWorld: public wxFrame {
public:
	HelloWorld(const wxString& title);

	void OnQuit(wxCommandEvent& event);
	void OnAbout(wxCommandEvent& event);

private:
	DECLARE_EVENT_TABLE()
};

#endif /* HELLOWORLD_H_ */
