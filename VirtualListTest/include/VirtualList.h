/*
 * VirtualList.h
 *
 *  Created on: 2012/06/15
 *      Author: learning
 */

#ifndef VIRTUALLIST_H_
#define VIRTUALLIST_H_

#include <wx/wx.h>
#include <wx/listctrl.h>
#include <vector>
#include <algorithm>

struct CharacterInfo {
  wxString number;
  wxString name;
  wxString comment;
};

typedef std::vector<CharacterInfo> CountryList;

class VirtualList: public wxListCtrl {

  enum Columns {
    COL_NUM = 0, COL_NAME, COL_COMMENT
  };

 public:
  VirtualList(wxWindow* parent);
  wxString OnGetItemText(long item, long column) const;
  void Sort();

 private:
  CountryList m_chars;
};

#endif /* VIRTUALLIST_H_ */
