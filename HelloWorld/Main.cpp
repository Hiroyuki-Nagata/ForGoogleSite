//============================================================================
// Name        : Main.cpp
// Author      : http://nantonaku-shiawase.hatenablog.com/
// Version     : 1.0.0
// Copyright   : Common Public License
// Description : Hello World in wxWidgets with Japanese
//============================================================================

#include <wx/wx.h>
#include "HelloWorld.h"

/**
 * wxAppのクラス宣言
 */
class MyApp: public wxApp {
public:
	virtual bool OnInit();
};

IMPLEMENT_APP(MyApp)

/**
 * wxAppの実装
 */
bool MyApp::OnInit()
{
	HelloWorld* hello = new HelloWorld(wxT("wxWidgetsでHelloWorld!!"));
	hello->Show(true);

    return true;
}
