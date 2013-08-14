//============================================================================
// Name        : VirtualList.hpp
// Author      : Hiroyuki Nagata
// Version     : 1.0.0
// Copyright   : Copyright (C) 2012 Hiroyuki Nagata, All rights reserved.
// Description : virtual list sort test program in wxWidgets
// Licence     : wxWindows Library Licence, Version 3.1
//============================================================================

#ifndef VIRTUALLIST_HPP_
#define VIRTUALLIST_HPP_

#include <vector>
#include <algorithm>
#include <wx/wx.h>
#include <wx/listctrl.h>
#include <wx/imaglist.h>

class CharacterInfo;

class CharacterInfo {

public:

     CharacterInfo(const wxString& number, const wxString& name, const wxString comment):
	  m_number(number), m_name(name), m_comment(comment) {};

     wxString getNumber() const {
	  return m_number;
     };
     
     wxString getName() const {
	  return m_name;
     };

     wxString getComment() const {
	  return m_comment;	       
     };

     int getNumberInt() const {
	  return wxAtoi(m_number);
     };
     
     int getNameSize() const {
	  return m_name.Len();
     };
     
     int getCommentSize() const {
	  return m_comment.Len();
     };

     static bool PredicateForward(const CharacterInfo& ci1, const CharacterInfo& ci2) {
	  return ci1.getNumberInt() < ci2.getNumberInt();
     }

     static bool PredicateReverse(const CharacterInfo& ci1, const CharacterInfo& ci2) {
	  return ci1.getNumberInt() > ci2.getNumberInt();
     }

private:
     wxString m_number;
     bool m_number_f;
     wxString m_name;
     wxString m_comment;
     wxListItem* m_listItem;
};

typedef std::vector<CharacterInfo> CharacterList;

class VirtualList: public wxListCtrl {

     enum Columns {
	  COL_NUM = 0,
	  COL_NAME,
	  COL_COMMENT
     };

public:
     VirtualList(wxWindow* parent);
     ~VirtualList();
     wxString OnGetItemText(long item, long column) const;
     void SortVector(long item, long column);
     virtual int OnGetItemColumnImage(long item, long column) const;

private:
     wxImageList* threadImage;
     CharacterList m_chars;
     bool m_number_f;
};

#endif /* VIRTUALLIST_HPP_ */
