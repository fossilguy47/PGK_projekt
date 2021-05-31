#include "GUIMyFrame.h"
#include "ConfigClass.h"
#include "ChartClass.h"

GUIMyFrame::GUIMyFrame( wxWindow* parent )
:
MyFrame( parent )
{
	cfg = std::make_shared<ConfigClass>(this);
}

void GUIMyFrame::drawing_panelUpdate( wxUpdateUIEvent& event )
{
	Repaint();
}

void GUIMyFrame::function_choiceOnChoice( wxCommandEvent& event )
{
// TODO: Implement function_choiceOnChoice
}

void GUIMyFrame::load_buttonOnButtonClick( wxCommandEvent& event )
{
// TODO: Implement load_buttonOnButtonClick
}

void GUIMyFrame::draw_buttonOnButtonClick( wxCommandEvent& event )
{
	Repaint();
}

void GUIMyFrame::contour_checkBoxOnCheckBox( wxCommandEvent& event )
{
// TODO: Implement contour_checkBoxOnCheckBox
}

void GUIMyFrame::zoom_sliderOnScroll( wxScrollEvent& event )
{
	Repaint();
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
	wxClientDC dc_client(drawing_panel);
	wxBufferedDC dc_buffered(&dc_client);

	int w, h;
	drawing_panel->GetSize(&w, &h);
	ChartClass MyChart(cfg, w, h);
	MyChart.Draw(&dc_buffered);
}

