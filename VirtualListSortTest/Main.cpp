//============================================================================
// Name        : Main.cpp
// Author      : Hiroyuki Nagata
// Version     : 1.0.0
// Copyright   : Copyright (C) 2012 Hiroyuki Nagata, All rights reserved.
// Description : virtual list sort test program in wxWidgets
// Licence     : wxWindows Library Licence, Version 3.1
//============================================================================

#include <wx/image.h>
#include "VirtualListTest.hpp"


// OnInitが呼ばれる前にロケールのクラスを継承しておく
class wxMain: public wxApp {
	wxLocale m_Locale;
public:
	wxMain() : m_Locale(wxLANGUAGE_DEFAULT){}
    bool OnInit();
};

IMPLEMENT_APP(wxMain)

bool wxMain::OnInit()
{
    wxInitAllImageHandlers();
    VirtualListTest* virtualListTest = new VirtualListTest(NULL, wxID_ANY, wxEmptyString);
    SetTopWindow(virtualListTest);
    virtualListTest->Show();
    return true;
}
