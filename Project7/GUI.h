///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __GUI_H__
#define __GUI_H__

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
#include <wx/button.h>
#include <wx/textctrl.h>
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
		wxTextCtrl* x0_textCtrl;
		wxStaticText* m_staticText8;
		wxTextCtrl* y0_textCtrl;
		wxStaticText* m_staticText9;
		wxTextCtrl* z0_textCtrl;
		wxStaticText* m_staticText221;
		wxTextCtrl* x1_textCtrl;
		wxStaticText* m_staticText81;
		wxTextCtrl* y1_textCtrl;
		wxStaticText* m_staticText91;
		wxTextCtrl* z1_textCtrl;
		wxStaticText* m_staticText2;
		wxTextCtrl* xMin_textCtrl;
		wxStaticText* m_staticText21;
		wxTextCtrl* yMin_textCtrl;
		wxStaticText* m_staticText39;
		wxStaticText* m_staticText40;
		wxStaticText* m_staticText23;
		wxTextCtrl* xMax_textCtrl;
		wxStaticText* m_staticText211;
		wxTextCtrl* yMax_textCtrl;
		wxStaticText* m_staticText41;
		wxStaticText* m_staticText42;
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
		virtual void function_choiceOnChoice( wxCommandEvent& event ) { event.Skip(); }
		virtual void load_buttonOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void draw_buttonOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void contour_checkBoxOnCheckBox( wxCommandEvent& event ) { event.Skip(); }
		virtual void zoom_sliderOnScroll( wxScrollEvent& event ) { event.Skip(); }
		virtual void x_sliderOnScroll( wxScrollEvent& event ) { event.Skip(); }
		virtual void y_sliderOnScroll( wxScrollEvent& event ) { event.Skip(); }
		virtual void z_sliderOnScroll( wxScrollEvent& event ) { event.Skip(); }
		virtual void save_buttonOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void print_buttonOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		MyFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 650,460 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		
		~MyFrame();
	
};

#endif //__GUI_H__
