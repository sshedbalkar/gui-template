#include "Frame.h"

#include "Application.h"

// Event Table
wxBEGIN_EVENT_TABLE(Frame, wxFrame) EVT_MENU(ID_Hello, Frame::OnHello)
    EVT_MENU(wxID_EXIT, Frame::OnExit) EVT_MENU(wxID_ABOUT, Frame::OnAbout)
        wxEND_EVENT_TABLE()

    // Initialize Application
    wxIMPLEMENT_APP(Application);

Frame::Frame(const wxString& title, const wxPoint& pos, const wxSize& size)
    : wxFrame(NULL, wxID_ANY, title, pos, size) {
  wxMenu* menuFile = new wxMenu;
  menuFile->Append(ID_Hello, "&Hello...\tCtrl-H",
                   "Help string shown in status bar for this menu item");
  menuFile->AppendSeparator();
  menuFile->Append(wxID_EXIT);
  wxMenu* menuHelp = new wxMenu;
  menuHelp->Append(wxID_ABOUT);
  wxMenuBar* menuBar = new wxMenuBar;
  menuBar->Append(menuFile, "&File");
  menuBar->Append(menuHelp, "&Help");
  SetMenuBar(menuBar);
  CreateStatusBar();
  SetStatusText("Welcome to wxWidgets!");
}

void Frame::OnExit(wxCommandEvent& event) { Close(true); }

void Frame::OnHello(wxCommandEvent& event) {
  wxLogMessage("Hello world from wxWidgets!");
}

void Frame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox( "This is a wxWidgets' Hello world sample",
                  "About Hello World", wxOK | wxICON_INFORMATION );
}
