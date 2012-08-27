//============================================================================
// Name        : RegexTest.h
// Author      : http://nantonaku-shiawase.hatenablog.com/
// Version     : 1.0.0
// Copyright   : Common Public License
// Description : regex test in wxWidgets with Japanese
//============================================================================

#ifndef REGEXTEST_H_
#define REGEXTEST_H_

#include <wx/wx.h>
#include <wx/regex.h>

// URL検出用正規表現（かなりいい加減かも）
static const wxString regexText = _T("(http|https|ttp|ftp)://([[:alnum:]]|[[:punct:]])*");

class RegexTest : public wxFrame {
public:
	RegexTest(const wxString& title);

	void OnButtonTestRegex(wxCommandEvent& event);

private:

	wxTextCtrl* m_tc1;
	wxTextCtrl* m_tc2;

	DECLARE_EVENT_TABLE()
};

#endif /* REGEXTEST_H_ */
