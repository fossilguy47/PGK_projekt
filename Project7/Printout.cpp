#include "Printout.h"
#include "ChartClass.h"

bool Printout::OnBeginDocument(int startPage, int endPage)
{
	if (wxPrintout::OnBeginDocument(startPage, endPage)) return true;
	return false;
}

bool Printout::OnPrintPage(int pageNum)
{
	std::shared_ptr<wxPageSetupDialogData> PageSetupData = std::shared_ptr<wxPageSetupDialogData>(new wxPageSetupDialogData);
	wxPageSetupDialog PageSetupDlg(this, PageSetupData.get());
	PageSetupDlg.ShowModal();
	*PageSetupData = PageSetupDlg.GetPageSetupData();
	//jest ladniej po odkomentowaniu ale zmiany tam poczynione nic nie daja
	//PageSetupDlg.ShowModal();
	wxDC* dc = GetDC();
	int w, h;
	drawing_panel->GetSize(&w, &h);
	FitThisSizeToPageMargins(wxSize(w, h), *PageSetupData);
	wxClientDC dc_client(drawing_panel);
	wxBufferedDC dc_buffered(&dc_client);
	ChartClass MyChart(cfg, w, h);
	MyChart.Draw(dc);
	return true;
}

void Printout::GetPageInfo(int* minPage, int* maxPage, int* selPageFrom, int* selPageTo)
{
	*minPage = 1;
	*maxPage = 1;
	*selPageFrom = 1;
	*selPageTo = 1;
}
