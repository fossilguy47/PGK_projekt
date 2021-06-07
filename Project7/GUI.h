///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct 26 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/panel.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/choice.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/button.h>
#include <wx/spinctrl.h>
#include <wx/checkbox.h>
#include <wx/slider.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// Class MyFrame
///////////////////////////////////////////////////////////////////////////////
class MyFrame : public wxFrame
{
	private:

	protected:
		wxPanel* drawing_panel;
		wxStaticText* m_staticText1;
		wxChoice* function_choice;
		wxButton* load_button;
		wxStaticText* m_staticText22;
		wxSpinCtrlDouble* x0_SpinCtrlDouble;
		wxStaticText* m_staticText8;
		wxSpinCtrlDouble* y0_SpinCtrlDouble;
		wxStaticText* m_staticText9;
		wxSpinCtrlDouble* z0_SpinCtrlDouble;
		wxStaticText* m_staticText221;
		wxSpinCtrlDouble* x1_SpinCtrlDouble;
		wxStaticText* m_staticText81;
		wxSpinCtrlDouble* y1_SpinCtrlDouble;
		wxStaticText* m_staticText91;
		wxSpinCtrlDouble* z1_SpinCtrlDouble;
		wxStaticText* m_staticText39;
		wxStaticText* f_min_txt;
		wxStaticText* m_staticText41;
		wxStaticText* f_max_txt;
		wxButton* draw_button;
		wxCheckBox* contour_checkBox;
		wxStaticText* m_staticText2313;
		wxSlider* zoom_slider;
		wxStaticText* m_staticText25;
		wxStaticText* m_staticText231;
		wxSlider* x_slider;
		wxStaticText* m_staticText2311;
		wxSlider* y_slider;
		wxStaticText* m_staticText2312;
		wxSlider* z_slider;
		wxButton* save_button;
		wxButton* print_button;

		// Virtual event handlers, overide them in your derived class
		virtual void drawing_panelUpdate( wxUpdateUIEvent& event ) { event.Skip(); }
		virtual void function_choiceOnChoice( wxCommandEvent& event ) { event.Skip(); }
		virtual void load_buttonOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void x0_update( wxCommandEvent& event ) { event.Skip(); }
		virtual void y0_update( wxCommandEvent& event ) { event.Skip(); }
		virtual void z0_update( wxCommandEvent& event ) { event.Skip(); }
		virtual void x1_update( wxCommandEvent& event ) { event.Skip(); }
		virtual void y1_update( wxCommandEvent& event ) { event.Skip(); }
		virtual void z1_update( wxCommandEvent& event ) { event.Skip(); }
		virtual void draw_buttonOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void contour_checkBoxOnCheckBox( wxCommandEvent& event ) { event.Skip(); }
		virtual void zoom_sliderOnScroll( wxScrollEvent& event ) { event.Skip(); }
		virtual void x_sliderOnScroll( wxScrollEvent& event ) { event.Skip(); }
		virtual void y_sliderOnScroll( wxScrollEvent& event ) { event.Skip(); }
		virtual void z_sliderOnScroll( wxScrollEvent& event ) { event.Skip(); }
		virtual void save_buttonOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void print_buttonOnButtonClick( wxCommandEvent& event ) { event.Skip(); }


	public:

		MyFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Wykresy 3D"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 1000,600 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~MyFrame();

};

