//============================================================================
// Name        : HtmlContentWindow.h
// Author      : Hiroyuki Nagata
// Version     : 1.0.0
// Copyright   : Copyright (C) 2012 Hiroyuki Nagata, All rights reserved.
// Description : wxHtmlWindow test in wxWidgets with Japanese
// Licence     : wxWindows licence
//============================================================================

#ifndef HTMLCONTENTWINDOW_H_
#define HTMLCONTENTWINDOW_H_

#include <wx/combobox.h>
#include <wx/button.h>
#include <wx/textctrl.h>
#include <wx/textfile.h>
#include <wx/file.h>
#include <wx/filename.h>
#include <wx/filefn.h>
#include <wx/html/htmlwin.h>
#include <wx/html/winpars.h>
#include <wx/valgen.h>
#include <wx/msgdlg.h>

// 読み込みに失敗した場合に表示するページ
static const wxString FAIL_TO_READ_PAGE =
		wxT("<html><head><meta http-equiv=\"Content-Type\" content=\"text/html; \
			charset=UTF-8\"><title></title></head><body><span>ファイルの読み込みに失敗しました</span></body></html>");

class HtmlContentWindow : public wxHtmlWindow {

 public:
  /**
   * 通常のコンストラクタ
   */
  HtmlContentWindow(wxWindow* parent, const wxString& htmlContentPath);
  /**
   * HTMLファイルを再読み込みする
   */
  void ReloadHtmlPage(const wxString& htmlContentPath);
  /**
   * ウィンドウを強制的にスクロールさせる
   */
  void ForceScrollWindow(int& x, int& y);

 private:
  /**
   * HTMLファイルを読み込んでwxString型に変換する
   */
  wxString GetHtmlFile(const wxString& htmlContentPath);
  /**
   * 指定されたパスにファイルがあればファイルサイズを返す処理
   */
  static size_t GetFileSize(const wxString& htmlContentPath);
  /**
   * ウィンドウのサイズ変更時処理
   */
  void OnSize(wxSizeEvent& event);

  DECLARE_EVENT_TABLE()
};

#endif /* HTMLCONTENTWINDOW_H_ */
