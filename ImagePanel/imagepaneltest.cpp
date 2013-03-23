/**
 * ImagePanelTest.cpp - use ImagePanel with wxAuiNotebook
 *
 * Copyright (c) 2013 Hiroyuki Nagata <newserver002@gmail.com>
 * 
 * wxWindows Library Licence, Version 3.1
 */
#include "ImagePanelTest.hpp"

/**
 * Default constructor
 */
ImagePanelTest::ImagePanelTest(wxWindow* parent, int id, const wxString& title, 
			       const wxPoint& pos, const wxSize& size, long style):
     wxFrame(parent, id, title, pos, size, wxDEFAULT_FRAME_STYLE) {

     // wxAuiManagerの初期化
     m_mgr.SetManagedWindow(this);

     // Auiのペインを配置する
     wxSize client_size = GetClientSize();
     wxAuiNotebook* ctrl1 = new wxAuiNotebook(this, wxID_ANY,
					      wxPoint(client_size.x, client_size.y), wxSize(430, 200), 
					      wxAUI_NB_TOP | wxAUI_NB_TAB_SPLIT | wxAUI_NB_TAB_MOVE | wxAUI_NB_SCROLL_BUTTONS);
     ctrl1->Freeze();

     // 画像パネルのインスタンスを作成しペインに配置する
     wxImagePanel* img = new wxImagePanel(ctrl1, wxT("sample.jpg"), wxBITMAP_TYPE_JPEG);
     ctrl1->AddPage(img, wxT("画像パネル"), false);
     ctrl1->Thaw();

     // wxAuiManagerに全ての変更を「コミットする」
     m_mgr.Update();
}

/**
 * Default destructor
 */
ImagePanelTest::~ImagePanelTest() {
     // wxAuiManagerはデストラクタで破棄しなければいけない
     m_mgr.UnInit();
}

/**
 * Copy constructor
 */
ImagePanelTest::ImagePanelTest(const ImagePanelTest& rhs) {
}

/**
 * Assignment operator
 */
ImagePanelTest& ImagePanelTest::operator=(const ImagePanelTest& rhs) {
    if (this != &rhs) {
        // TODO: implement copy
    }
    return *this;
}
