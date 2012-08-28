//============================================================================
// Name        : HtmlContentWindow.cpp
// Author      : Hiroyuki Nagata
// Version     : 1.0.0
// Copyright   : Copyright (C) 2012 Hiroyuki Nagata, All rights reserved.
// Description : wxHtmlWindow test in wxWidgets with Japanese
// Licence     : wxWindows licence
//============================================================================

#include "HtmlContentWindow.h"

/**
 * 通常のコンストラクタ
 */
HtmlContentWindow::HtmlContentWindow(wxWindow* parent,
		const wxString& htmlContentPath) :
		wxHtmlWindow(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize,
				wxHW_SCROLLBAR_AUTO) {

	// 指定されたパスからHTMLファイルを読み出す
	const wxString htmlSource = GetHtmlFile(htmlContentPath);
	// メモリに読み込んだHTMLを表示する
	this->SetPage(htmlSource);
}
/**
 * HTMLファイルを再読み込みする
 */
void HtmlContentWindow::ReloadHtmlPage(const wxString& htmlContentPath) {
	// 指定されたパスからHTMLファイルを読み出す
	const wxString htmlSource = GetHtmlFile(htmlContentPath);
	// メモリに読み込んだHTMLを表示する
	this->SetPage(htmlSource);
}
/**
 * HTMLファイルを読み込んでwxString型に変換する
 */
wxString HtmlContentWindow::GetHtmlFile(const wxString& htmlContentPath) {

	// wxStringにバッファするサイズを計測する
	size_t fileSize = GetFileSize(htmlContentPath);

	if (fileSize == 0)
		// 読み込みに失敗した場合
		return FAIL_TO_READ_PAGE;

	// 取得サイズ分だけwxStringを確保する
	wxString htmlSource;
	htmlSource.Alloc(fileSize);

	// テキストファイルの読み込み
	wxTextFile datfile;
	datfile.Open(htmlContentPath, wxConvUTF8);
	wxString str;

	if (datfile.IsOpened()) {
		for (str = datfile.GetFirstLine(); !datfile.Eof();
				str = datfile.GetNextLine()) {
			htmlSource += str;
		}
	}

	datfile.Close();

	return htmlSource;
}
/**
 * 指定されたパスにファイルがあればファイルサイズを返す処理
 */
size_t HtmlContentWindow::GetFileSize(const wxString& htmlContentPath) {

	if (wxFileName::FileExists (htmlContentPath)) {

		wxULongLong fileSize = wxFileName::GetSize(htmlContentPath);

		if (fileSize == wxInvalidSize) {
			// ファイルが正常に開けなかった場合
			return 0;
		} else {
			// unsigned long型で返却
			return (size_t) fileSize.GetLo();
		}
	} else {
		// ファイルが存在しなかった場合
		return 0;
	}
}
