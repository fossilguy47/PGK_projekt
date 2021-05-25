#include <wx/wx.h>
#include "GUI.h"

class MyApp : public wxApp {

public:

	virtual bool OnInit();
	virtual int OnExit() { return 0; }

};

IMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
	MyFrame* mainFrame = new MyFrame(NULL);
	mainFrame->Show(true);
	SetTopWindow(mainFrame);

	wxImage::AddHandler(new wxJPEGHandler);

	return true;
}