#include "GUIMyFrame.h"
#include "ConfigClass.h"
#include "ChartClass.h"
#include "Printout.h"

GUIMyFrame::GUIMyFrame( wxWindow* parent )
:
MyFrame( parent )
{
	m_staticText1->SetLabel(_(L"Wyb\u00F3r funkcji oraz parametr\u00F3w"));
	load_button->SetLabel(_(L"Za\u0142aduj"));
	cfg = std::make_shared<ConfigClass>(this);
}

void GUIMyFrame::drawing_panelUpdate( wxUpdateUIEvent& event )
{
	if (!cfg->Get_contour()) Repaint();
}

void GUIMyFrame::function_choiceOnChoice( wxCommandEvent& event )
{
	cfg->Set_f_type(function_choice->GetSelection());
}

void GUIMyFrame::load_buttonOnButtonClick( wxCommandEvent& event )
{
	// TODO
}

void GUIMyFrame::x0_update( wxCommandEvent& event )
{
if (x0_SpinCtrlDouble->GetValue() < x1_SpinCtrlDouble->GetValue())
{
cfg->Set_x0(x0_SpinCtrlDouble->GetValue());
}
else
{
x0_SpinCtrlDouble->SetValue(cfg->Get_x0());
wxBell();
}
}

void GUIMyFrame::y0_update( wxCommandEvent& event )
{
if (y0_SpinCtrlDouble->GetValue() < y1_SpinCtrlDouble->GetValue())
{
cfg->Set_y0(y0_SpinCtrlDouble->GetValue());
}
else
{
y0_SpinCtrlDouble->SetValue(cfg->Get_y0());
wxBell();
}
}

void GUIMyFrame::z0_update( wxCommandEvent& event )
{
if (z0_SpinCtrlDouble->GetValue() < z1_SpinCtrlDouble->GetValue())
{
cfg->Set_z0(z0_SpinCtrlDouble->GetValue());
}
else
{
z0_SpinCtrlDouble->SetValue(cfg->Get_z0());
wxBell();
}
}

void GUIMyFrame::x1_update( wxCommandEvent& event )
{
if (x1_SpinCtrlDouble->GetValue() > x0_SpinCtrlDouble->GetValue())
{
cfg->Set_x1(x1_SpinCtrlDouble->GetValue());
}
else
{
x1_SpinCtrlDouble->SetValue(cfg->Get_x1());
wxBell();
}
}

void GUIMyFrame::y1_update( wxCommandEvent& event )
{
if (y1_SpinCtrlDouble->GetValue() > y0_SpinCtrlDouble->GetValue())
{
cfg->Set_y1(y1_SpinCtrlDouble->GetValue());
}
else
{
y1_SpinCtrlDouble->SetValue(cfg->Get_y1());
wxBell();
}
}

void GUIMyFrame::z1_update( wxCommandEvent& event )
{
if (z1_SpinCtrlDouble->GetValue() > z0_SpinCtrlDouble->GetValue())
{
cfg->Set_z1(z1_SpinCtrlDouble->GetValue());
}
else
{
z1_SpinCtrlDouble->SetValue(cfg->Get_z1());
wxBell();
}
}

void GUIMyFrame::draw_buttonOnButtonClick( wxCommandEvent& event )
{
	Repaint();
}

void GUIMyFrame::contour_checkBoxOnCheckBox( wxCommandEvent& event )
{
if (contour_checkBox->IsChecked())
{
cfg->Set_contour(true);
zoom_slider->Disable();
x_slider->Disable();
y_slider->Disable();
z_slider->Disable();
}
else
{
cfg->Set_contour(false);
zoom_slider->Enable();
x_slider->Enable();
y_slider->Enable();
z_slider->Enable();
}
Repaint();
}

void GUIMyFrame::x_step_update( wxCommandEvent& event )
{
	cfg->Set_x_step(x_step_spinCtrl->GetValue());
}

void GUIMyFrame::y_step_update( wxCommandEvent& event )
{
	cfg->Set_y_step(y_step_spinCtrl->GetValue());
}

void GUIMyFrame::zoom_sliderOnScroll( wxScrollEvent& event )
{
	cfg->Set_zoom(zoom_slider->GetValue());
}

void GUIMyFrame::x_sliderOnScroll( wxScrollEvent& event )
{
	cfg->Set_x_rot(x_slider->GetValue());
}

void GUIMyFrame::y_sliderOnScroll( wxScrollEvent& event )
{
	cfg->Set_y_rot(y_slider->GetValue());
}

void GUIMyFrame::z_sliderOnScroll( wxScrollEvent& event )
{
	cfg->Set_z_rot(z_slider->GetValue());
}

void GUIMyFrame::save_buttonOnButtonClick( wxCommandEvent& event ){
	::wxInitAllImageHandlers();
	wxClientDC* my_wxclientdc = new wxClientDC(drawing_panel);
	wxMemoryDC* my_wxmemorydc = new wxMemoryDC();
	wxBitmap my_bitmap_tmp(drawing_panel->GetSize(), wxBITMAP_SCREEN_DEPTH);
	my_wxmemorydc->SelectObject(my_bitmap_tmp);
	my_wxmemorydc->Blit(wxPoint(0, 0), drawing_panel->GetSize(), my_wxclientdc, wxPoint(-1, -1), wxCOPY, true, wxDefaultPosition);
	wxFileDialog* FileDialog2;
	FileDialog2 = new wxFileDialog(this, _("Select file"), wxEmptyString, wxEmptyString, _(".bmp|*.bmp|.jpeg|*.jpeg|.png|*.png"), wxFD_SAVE | wxFD_OVERWRITE_PROMPT, wxDefaultPosition, wxDefaultSize, _T("wxFileDialog"));
	int dlg = FileDialog2->ShowModal();
	if (dlg == wxID_OK){
		wxFileName my_file(FileDialog2->GetPath());
		wxString my_file_ext = my_file.GetExt().Lower();

		if (my_file_ext == wxT("png"))my_bitmap_tmp.SaveFile(FileDialog2->GetPath(), wxBITMAP_TYPE_PNG, NULL);
		else if (my_file_ext == wxT("jpeg"))my_bitmap_tmp.SaveFile(FileDialog2->GetPath(), wxBITMAP_TYPE_JPEG, NULL);
		else if (my_file_ext == wxT("bmp"))my_bitmap_tmp.SaveFile(FileDialog2->GetPath(), wxBITMAP_TYPE_BMP, NULL);

	}
	delete my_wxclientdc;
	delete my_wxmemorydc;
	delete FileDialog2;
}

void GUIMyFrame::print_buttonOnButtonClick( wxCommandEvent& event )
{

wxPrinter Printer;
Printout MyPrintout;
Printer.Print(this, &MyPrintout, true);
}


void GUIMyFrame::Repaint()
{
	int w, h;
	drawing_panel->GetSize(&w, &h);
	wxClientDC dc_client(drawing_panel);
	wxBufferedDC dc_buffered(&dc_client);
	ChartClass MyChart(cfg, w, h);
	MyChart.Draw(&dc_buffered);
	MyChart.drawValueBar(&dc_buffered);
}