#include "GUIMyFrame.h"
#include "ConfigClass.h"
#include "ChartClass.h"

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
	cfg->set_f_type(function_choice->GetSelection());
}

void GUIMyFrame::load_buttonOnButtonClick( wxCommandEvent& event )
{
	// TODO
}

void GUIMyFrame::x0_update(wxCommandEvent& event)
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

void GUIMyFrame::zoom_sliderOnScroll( wxScrollEvent& event )
{
// TODO
}

void GUIMyFrame::x_sliderOnScroll( wxScrollEvent& event )
{
// TODO: Implement x_sliderOnScroll
}

void GUIMyFrame::y_sliderOnScroll( wxScrollEvent& event )
{
// TODO: Implement y_sliderOnScroll
}

void GUIMyFrame::z_sliderOnScroll( wxScrollEvent& event )
{
// TODO: Implement z_sliderOnScroll
}

void GUIMyFrame::save_buttonOnButtonClick( wxCommandEvent& event )
{
// TODO: Implement save_buttonOnButtonClick
}

void GUIMyFrame::print_buttonOnButtonClick( wxCommandEvent& event )
{
// TODO: Implement print_buttonOnButtonClick
}


void GUIMyFrame::Repaint()
{
	int w, h;
	drawing_panel->GetSize(&w, &h);
	wxClientDC dc_client(drawing_panel);
	wxBufferedDC dc_buffered(&dc_client);
	ChartClass MyChart(cfg, w, h);
	MyChart.Draw(&dc_buffered);
}

