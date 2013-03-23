#include <wx/wx.h>
#include "imagepanel.hpp"
 
// ----------------------------------------
// how-to-use example
 
class MyApp: public wxApp
{
    
     wxFrame* frame;
     wxImagePanel* drawPane;
private:
     //wxAuiManager m_mgr;

public:
     bool OnInit()
	  {
	       // make sure to call this first
	       wxInitAllImageHandlers();

	       wxBoxSizer* sizer = new wxBoxSizer(wxHORIZONTAL);
	       frame = new wxFrame(NULL, wxID_ANY, wxT("Hello wxDC"), wxPoint(50,50), wxSize(800,600));

               // Auiのペインを配置する
	       //wxSize client_size = frame->GetClientSize();
	       //wxAuiNotebook* ctrl1 = new wxAuiNotebook(frame, wxID_ANY,
	       //wxPoint(client_size.x, client_size.y), wxSize(430, 200), 
	       //    wxAUI_NB_TOP | wxAUI_NB_TAB_SPLIT | wxAUI_NB_TAB_MOVE | wxAUI_NB_SCROLL_BUTTONS);
	       //ctrl1->Freeze();

        
	       // then simply create like this
	       drawPane = new wxImagePanel( frame, wxT("sample.jpg"), wxBITMAP_TYPE_JPEG);
	       sizer->Add(drawPane, 1, wxEXPAND);

	       //ctrl1->Thaw();
	       // wxAuiManagerに全ての変更を「コミットする」
	       //m_mgr.Update();        

	       frame->SetSizer(sizer);        
	       frame->Show();
	       return true;
	  } 
    
};
 
IMPLEMENT_APP(MyApp)
