/**
 * ImagePanelTest.hpp - use ImagePanel with wxAuiNotebook
 *
 * Copyright (c) 2013 Hiroyuki Nagata <newserver002@gmail.com>
 * 
 * wxWindows Library Licence, Version 3.1
 */

#ifndef IMAGEPANELTEST_HPP_
#define IMAGEPANELTEST_HPP_

#include <wx/wx.h>
#include <wx/aui/auibook.h>
#include "imagepanel.hpp"

class ImagePanelTest : public wxFrame {

public:
    /// Default constructor
    ImagePanelTest(wxWindow* parent, int id, const wxString& title,
		   const wxPoint& pos = wxDefaultPosition, const wxSize& size =
		   wxDefaultSize, long style = wxDEFAULT_FRAME_STYLE);
    /// Destructor
    ~ImagePanelTest();
    /// Copy constructor
    ImagePanelTest(const ImagePanelTest& rhs);
    /// Assignment operator
    ImagePanelTest& operator=(const ImagePanelTest& rhs);

private:
     wxAuiManager m_mgr;
     //wxImagePanel* imgPanel;
     //DECLARE_EVENT_TABLE()
};


#endif /* IMAGEPANELTEST_HPP_ */
