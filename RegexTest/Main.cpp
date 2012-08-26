//============================================================================
// Name        : Main.cpp
// Author      : http://nantonaku-shiawase.hatenablog.com/
// Version     : 1.0.0
// Copyright   : Common Public License
// Description : regex test in wxWidgets with Japanese
//============================================================================

#include <wx/wx.h>
#include "RegexTest.h"

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
	RegexTest* regex = new RegexTest(wxT("wxRegExを使うテスト"));
	regex->Show(true);

    return true;
}
