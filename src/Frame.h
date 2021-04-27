#include <wx/wx.h>

enum {
  ID_Exit = wxID_EXIT,
  ID_About = wxID_ABOUT,

  ID_Hello = 1
};

class Frame : public wxFrame {
 public:
  Frame(const wxString& title, const wxPoint& ps, const wxSize& size);

 private:
  void OnHello(wxCommandEvent& event);
  void OnExit(wxCommandEvent& event);
  void OnAbout(wxCommandEvent& event);

  wxDECLARE_EVENT_TABLE();
};
