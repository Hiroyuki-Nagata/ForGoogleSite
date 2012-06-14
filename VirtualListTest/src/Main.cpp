/*
 * Main.cpp
 *
 *  Created on: 2012/06/14
 *      Author: learning
 */

#include <wx/image.h>
#include "VirtualListTest.h"


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

