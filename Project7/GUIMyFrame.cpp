#include "GUIMyFrame.h"
#include "ConfigClass.h"
#include "ChartClass.h"

float shepard(float d[100][3], int N, float x, float y)
{

	float a = 0;
	float b = 0;
	for (int i = 0; i < N; ++i)
	{
		const float w_b = (x - d[i][0]) * (x - d[i][0]) + (y - d[i][1]) * (y - d[i][1]);
		const float w = 1.f / w_b;

		b += w;
		a += w * d[i][2];
	}

	return a / b;
}

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
	Repaint();
}

void GUIMyFrame::function_choiceOnChoice( wxCommandEvent& event )
{
// TODO: Implement function_choiceOnChoice
}

void GUIMyFrame::load_buttonOnButtonClick( wxCommandEvent& event )
{
	// TODO
}

void GUIMyFrame::draw_buttonOnButtonClick( wxCommandEvent& event )
{
	// TODO
}

void GUIMyFrame::contour_checkBoxOnCheckBox( wxCommandEvent& event )
{
	if (contour_checkBox->IsChecked()) cfg->Set_contour(true);
	else cfg->Set_contour(false);
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
	wxClientDC dc_client(drawing_panel);
	wxBufferedDC dc_buffered(&dc_client);
	int w, h;
	drawing_panel->GetSize(&w, &h);
	ChartClass MyChart(cfg, w, h);
	MyChart.Draw(&dc_buffered);
}

