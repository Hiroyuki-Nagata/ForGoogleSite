/*
 * main.cpp
 *
 *  Created on: 2013/02/17
 *      Author: Hiroyuki Nagata
 */

#include <wx/image.h>
#include "treectrltest.hpp"


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
    TreeCtrlTest* treeCtrlTest = new TreeCtrlTest(NULL, wxID_ANY, wxEmptyString);
    //SetTopWindow(virtualListTest);
    treeCtrlTest->Show();
    return true;
}
