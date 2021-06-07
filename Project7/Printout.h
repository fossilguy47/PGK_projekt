#ifndef __Printout__
#define __Printout__

#include <wx/print.h>
#include <wx/printdlg.h>
#include "GUIMyFrame.h"

class Printout : public wxPrintout, public GUIMyFrame
{
public:
	Printout(const wxChar* title = (const wxChar*)"Mój wydruk") :wxPrintout(title), GUIMyFrame(NULL) {};
	bool OnPrintPage(int page);
	bool OnBeginDocument(int startPage, int endPage);
	void GetPageInfo(int* minPage, int* maxPage, int* selPageFrom, int* selPageTo);
};

#endif
