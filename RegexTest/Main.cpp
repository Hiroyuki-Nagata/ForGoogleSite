//============================================================================
// Name        : Main.cpp
// Author      : Hiroyuki Nagata
// Version     : 1.0.0
// Copyright   : Copyright (C) 2012 Hiroyuki Nagata, All rights reserved.
// Description : regex test in wxWidgets with Japanese
// Licence     : wxWindows Library Licence, Version 3.1
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
