//============================================================================
// Name        : HtmlContentWindow.cpp
// Author      : Hiroyuki Nagata
// Version     : 1.0.0
// Copyright   : Copyright (C) 2012 Hiroyuki Nagata, All rights reserved.
// Description : wxHtmlWindow test in wxWidgets with Japanese
// Licence     : wxWindows licence
//============================================================================

#include "HtmlContentWindow.h"
#include "wx/html/m_templ.h"

// <form> tags
TAG_HANDLER_BEGIN(FORM, "FORM")
TAG_HANDLER_CONSTR(FORM)
{
}
TAG_HANDLER_PROC(tag)
{
     m_WParser->CloseContainer();
     m_WParser->OpenContainer();
     ParseInner(tag);
     return true;
}
TAG_HANDLER_END(FORM)

// <select> tags
TAG_HANDLER_BEGIN(SELECT, "SELECT, OPTION")
     TAG_HANDLER_CONSTR(SELECT)
{
     m_pComboBox = NULL;
     m_iNumber = 0;
}

TAG_HANDLER_VARS
wxComboBox *m_pComboBox;
int m_iNumber;


TAG_HANDLER_PROC(tag)
{
     if (m_pComboBox && tag.GetName() == wxT("OPTION"))
     {
	  if (tag.HasParam(wxT("VALUE")))
	  {
	       wxString strValue = tag.GetParam(wxT("VALUE"));
	       wxString strName;
	       strName = m_WParser->GetSource()->Mid(
		    tag.GetBeginPos(),
		    tag.GetEndPos1()-tag.GetBeginPos());
#if !wxUSE_UNICODE
	       wxCSConv conv(m_WParser->GetInputEncoding());
	       strName = wxString(strName.wc_str(conv), wxConvLocal);
#endif

	       m_WParser->GetEntitiesParser()->Parse(strName);

	       m_pComboBox->Append(strName, &strValue);
	       if (!m_iNumber) m_pComboBox->SetValue(strName);
	       m_iNumber++;
	  }
	  return true;
     }
     else if (tag.GetName() == wxT("SELECT"))
     {
	  int fl = 0;
	  wxComboBox *pOldBox = m_pComboBox;
	  int iOldNumber = m_iNumber;

	  m_pComboBox = new wxComboBox(m_WParser->GetWindowInterface()->GetHTMLWindow(), wxID_ANY, "", wxPoint(0,0), wxDefaultSize, 0, NULL, wxCB_READONLY  | wxCB_DROPDOWN);
	  m_pComboBox->Show(true);

	  //m_Parser->PushTagHandler(this, "OPTION");
	  ParseInner(tag);
	  //m_Parser->PopTagHandler();


	  m_WParser->GetContainer()->InsertCell(new wxHtmlWidgetCell(m_pComboBox, fl));

	  m_pComboBox = pOldBox;
	  m_iNumber = iOldNumber;
	  return true;

     }
     return false;
}

TAG_HANDLER_END(SELECT)

// <input> tags
TAG_HANDLER_BEGIN(INPUT, "INPUT")
     TAG_HANDLER_CONSTR(INPUT)
{
}

TAG_HANDLER_PROC(tag)
{
     if (tag.HasParam(wxT("TYPE")))
     {
	  if (!tag.GetParam(wxT("TYPE")).CmpNoCase(wxT("SUBMIT")))
	  {
	       int fl = 0;
	       wxButton *pButton;

	       pButton = new wxButton(m_WParser->GetWindowInterface()->GetHTMLWindow(), wxID_ANY, tag.GetParam(wxT("VALUE")), wxPoint(0,0), wxDefaultSize);
	       pButton->Show(true);

	       m_WParser->GetContainer()->InsertCell(new wxHtmlWidgetCell(pButton, fl));
	  }
	  else if (!tag.GetParam(wxT("TYPE")).CmpNoCase(wxT("TEXT")))
	  {
	       int fl = 0;
	       wxTextCtrl *pText;

	       pText = new wxTextCtrl(m_WParser->GetWindowInterface()->GetHTMLWindow(), wxID_ANY, tag.GetParam(wxT("VALUE")), wxPoint(0,0), wxDefaultSize);
	       pText->Show(true);

	       m_WParser->GetContainer()->InsertCell(new wxHtmlWidgetCell(pText, fl));
	  }
     }
     return true;
}

TAG_HANDLER_END(SELECT)

// <form> tags
TAGS_MODULE_BEGIN(Form)

     TAGS_MODULE_ADD(FORM)
     TAGS_MODULE_ADD(SELECT)
     TAGS_MODULE_ADD(INPUT)

     TAGS_MODULE_END(Form)

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
