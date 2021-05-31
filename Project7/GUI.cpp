///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "GUI.h"

///////////////////////////////////////////////////////////////////////////

MyFrame::MyFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 260,460 ), wxDefaultSize );
	
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxVERTICAL );
	
	drawing_panel = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	drawing_panel->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOW ) );
	drawing_panel->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_3DLIGHT ) );
	
	bSizer3->Add( drawing_panel, 1, wxEXPAND | wxALL, 5 );
	
	
	bSizer1->Add( bSizer3, 3, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText1 = new wxStaticText( this, wxID_ANY, wxT("Wybór funkcji oraz parametrów:"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	m_staticText1->Wrap( -1 );
	bSizer7->Add( m_staticText1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxBoxSizer* bSizer7122;
	bSizer7122 = new wxBoxSizer( wxHORIZONTAL );
	
	wxArrayString function_choiceChoices;
	function_choice = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxSize( 90,-1 ), function_choiceChoices, 0 );
	function_choice->SetSelection( 0 );
	bSizer7122->Add( function_choice, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	load_button = new wxButton( this, wxID_ANY, wxT("Załaduj"), wxDefaultPosition, wxSize( 70,-1 ), 0 );
	bSizer7122->Add( load_button, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer7->Add( bSizer7122, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer712;
	bSizer712 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText22 = new wxStaticText( this, wxID_ANY, wxT("x0:"), wxDefaultPosition, wxSize( -1,20 ), 0 );
	m_staticText22->Wrap( -1 );
	bSizer712->Add( m_staticText22, 0, wxALL, 5 );
	
	x0_textCtrl = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 30,20 ), 0 );
	bSizer712->Add( x0_textCtrl, 0, wxALL, 5 );
	
	m_staticText8 = new wxStaticText( this, wxID_ANY, wxT("y0:"), wxDefaultPosition, wxSize( -1,20 ), 0 );
	m_staticText8->Wrap( -1 );
	bSizer712->Add( m_staticText8, 0, wxALL, 5 );
	
	y0_textCtrl = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 30,20 ), 0 );
	bSizer712->Add( y0_textCtrl, 0, wxALL, 5 );
	
	m_staticText9 = new wxStaticText( this, wxID_ANY, wxT("z0:"), wxDefaultPosition, wxSize( -1,20 ), 0 );
	m_staticText9->Wrap( -1 );
	bSizer712->Add( m_staticText9, 0, wxALL, 5 );
	
	z0_textCtrl = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 30,20 ), 0 );
	bSizer712->Add( z0_textCtrl, 0, wxALL, 5 );
	
	
	bSizer7->Add( bSizer712, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer7121;
	bSizer7121 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText221 = new wxStaticText( this, wxID_ANY, wxT("x1:"), wxDefaultPosition, wxSize( -1,20 ), 0 );
	m_staticText221->Wrap( -1 );
	bSizer7121->Add( m_staticText221, 0, wxALL, 5 );
	
	x1_textCtrl = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 30,20 ), 0 );
	bSizer7121->Add( x1_textCtrl, 0, wxALL, 5 );
	
	m_staticText81 = new wxStaticText( this, wxID_ANY, wxT("y1:"), wxDefaultPosition, wxSize( -1,20 ), 0 );
	m_staticText81->Wrap( -1 );
	bSizer7121->Add( m_staticText81, 0, wxALL, 5 );
	
	y1_textCtrl = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 30,20 ), 0 );
	bSizer7121->Add( y1_textCtrl, 0, wxALL, 5 );
	
	m_staticText91 = new wxStaticText( this, wxID_ANY, wxT("z1:"), wxDefaultPosition, wxSize( -1,20 ), 0 );
	m_staticText91->Wrap( -1 );
	bSizer7121->Add( m_staticText91, 0, wxALL, 5 );
	
	z1_textCtrl = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 30,20 ), 0 );
	bSizer7121->Add( z1_textCtrl, 0, wxALL, 5 );
	
	
	bSizer7->Add( bSizer7121, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer10;
	bSizer10 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText2 = new wxStaticText( this, wxID_ANY, wxT("x_min:"), wxDefaultPosition, wxSize( -1,20 ), 0 );
	m_staticText2->Wrap( -1 );
	bSizer10->Add( m_staticText2, 0, wxALL, 5 );
	
	xMin_textCtrl = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 30,20 ), 0 );
	bSizer10->Add( xMin_textCtrl, 0, wxALL, 5 );
	
	m_staticText21 = new wxStaticText( this, wxID_ANY, wxT("y_min:"), wxDefaultPosition, wxSize( -1,20 ), 0 );
	m_staticText21->Wrap( -1 );
	bSizer10->Add( m_staticText21, 0, wxALL, 5 );
	
	yMin_textCtrl = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 30,20 ), 0 );
	bSizer10->Add( yMin_textCtrl, 0, wxALL, 5 );
	
	m_staticText39 = new wxStaticText( this, wxID_ANY, wxT("z_min:"), wxDefaultPosition, wxSize( -1,20 ), 0 );
	m_staticText39->Wrap( -1 );
	bSizer10->Add( m_staticText39, 0, wxALL, 5 );
	
	m_staticText40 = new wxStaticText( this, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize( -1,20 ), 0 );
	m_staticText40->Wrap( -1 );
	bSizer10->Add( m_staticText40, 0, wxALL, 5 );
	
	
	bSizer7->Add( bSizer10, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer101;
	bSizer101 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText23 = new wxStaticText( this, wxID_ANY, wxT("x_max:"), wxDefaultPosition, wxSize( -1,20 ), 0 );
	m_staticText23->Wrap( -1 );
	bSizer101->Add( m_staticText23, 0, wxALL, 5 );
	
	xMax_textCtrl = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 30,20 ), 0 );
	bSizer101->Add( xMax_textCtrl, 0, wxALL, 5 );
	
	m_staticText211 = new wxStaticText( this, wxID_ANY, wxT("y_max:"), wxDefaultPosition, wxSize( -1,20 ), 0 );
	m_staticText211->Wrap( -1 );
	bSizer101->Add( m_staticText211, 0, wxALL, 5 );
	
	yMax_textCtrl = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 30,20 ), 0 );
	bSizer101->Add( yMax_textCtrl, 0, wxALL, 5 );
	
	m_staticText41 = new wxStaticText( this, wxID_ANY, wxT("z_max:"), wxDefaultPosition, wxSize( -1,20 ), 0 );
	m_staticText41->Wrap( -1 );
	bSizer101->Add( m_staticText41, 0, wxALL, 5 );
	
	m_staticText42 = new wxStaticText( this, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize( -1,20 ), 0 );
	m_staticText42->Wrap( -1 );
	bSizer101->Add( m_staticText42, 0, wxALL, 5 );
	
	
	bSizer7->Add( bSizer101, 1, wxEXPAND, 5 );
	
	draw_button = new wxButton( this, wxID_ANY, wxT("Rysuj"), wxDefaultPosition, wxSize( 60,-1 ), 0 );
	bSizer7->Add( draw_button, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	contour_checkBox = new wxCheckBox( this, wxID_ANY, wxT("konturowa"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer7->Add( contour_checkBox, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxBoxSizer* bSizer10114;
	bSizer10114 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText2313 = new wxStaticText( this, wxID_ANY, wxT("Zoom:"), wxDefaultPosition, wxSize( -1,20 ), 0 );
	m_staticText2313->Wrap( -1 );
	bSizer10114->Add( m_staticText2313, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	zoom_slider = new wxSlider( this, wxID_ANY, 50, 0, 100, wxDefaultPosition, wxSize( -1,20 ), wxSL_HORIZONTAL );
	bSizer10114->Add( zoom_slider, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer7->Add( bSizer10114, 1, wxEXPAND, 5 );
	
	m_staticText25 = new wxStaticText( this, wxID_ANY, wxT("Rotacje:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText25->Wrap( -1 );
	bSizer7->Add( m_staticText25, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxBoxSizer* bSizer1011;
	bSizer1011 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText231 = new wxStaticText( this, wxID_ANY, wxT("OX:"), wxDefaultPosition, wxSize( -1,20 ), 0 );
	m_staticText231->Wrap( -1 );
	bSizer1011->Add( m_staticText231, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	x_slider = new wxSlider( this, wxID_ANY, 50, 0, 100, wxDefaultPosition, wxSize( -1,20 ), wxSL_HORIZONTAL );
	bSizer1011->Add( x_slider, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer7->Add( bSizer1011, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer10111;
	bSizer10111 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText2311 = new wxStaticText( this, wxID_ANY, wxT("OY:"), wxDefaultPosition, wxSize( -1,20 ), 0 );
	m_staticText2311->Wrap( -1 );
	bSizer10111->Add( m_staticText2311, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	y_slider = new wxSlider( this, wxID_ANY, 50, 0, 100, wxDefaultPosition, wxSize( -1,20 ), wxSL_HORIZONTAL );
	bSizer10111->Add( y_slider, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer7->Add( bSizer10111, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer10112;
	bSizer10112 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText2312 = new wxStaticText( this, wxID_ANY, wxT("OZ:"), wxDefaultPosition, wxSize( -1,20 ), 0 );
	m_staticText2312->Wrap( -1 );
	bSizer10112->Add( m_staticText2312, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	z_slider = new wxSlider( this, wxID_ANY, 50, 0, 100, wxDefaultPosition, wxSize( -1,20 ), wxSL_HORIZONTAL );
	bSizer10112->Add( z_slider, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer7->Add( bSizer10112, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer10113;
	bSizer10113 = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer44;
	bSizer44 = new wxBoxSizer( wxVERTICAL );
	
	save_button = new wxButton( this, wxID_ANY, wxT("Zapisz"), wxDefaultPosition, wxSize( 55,-1 ), 0 );
	bSizer44->Add( save_button, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	
	bSizer10113->Add( bSizer44, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer46;
	bSizer46 = new wxBoxSizer( wxVERTICAL );
	
	print_button = new wxButton( this, wxID_ANY, wxT("Drukuj"), wxDefaultPosition, wxSize( 55,-1 ), 0 );
	bSizer46->Add( print_button, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	
	bSizer10113->Add( bSizer46, 1, wxEXPAND, 5 );
	
	
	bSizer7->Add( bSizer10113, 1, wxEXPAND, 5 );
	
	
	bSizer1->Add( bSizer7, 1, wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer1 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	drawing_panel->Connect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( MyFrame::drawing_panelUpdate ), NULL, this );
	function_choice->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( MyFrame::function_choiceOnChoice ), NULL, this );
	load_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame::load_buttonOnButtonClick ), NULL, this );
	draw_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame::draw_buttonOnButtonClick ), NULL, this );
	contour_checkBox->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MyFrame::contour_checkBoxOnCheckBox ), NULL, this );
	zoom_slider->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MyFrame::zoom_sliderOnScroll ), NULL, this );
	zoom_slider->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MyFrame::zoom_sliderOnScroll ), NULL, this );
	zoom_slider->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MyFrame::zoom_sliderOnScroll ), NULL, this );
	zoom_slider->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MyFrame::zoom_sliderOnScroll ), NULL, this );
	zoom_slider->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MyFrame::zoom_sliderOnScroll ), NULL, this );
	zoom_slider->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MyFrame::zoom_sliderOnScroll ), NULL, this );
	zoom_slider->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MyFrame::zoom_sliderOnScroll ), NULL, this );
	zoom_slider->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MyFrame::zoom_sliderOnScroll ), NULL, this );
	zoom_slider->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MyFrame::zoom_sliderOnScroll ), NULL, this );
	x_slider->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MyFrame::x_sliderOnScroll ), NULL, this );
	x_slider->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MyFrame::x_sliderOnScroll ), NULL, this );
	x_slider->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MyFrame::x_sliderOnScroll ), NULL, this );
	x_slider->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MyFrame::x_sliderOnScroll ), NULL, this );
	x_slider->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MyFrame::x_sliderOnScroll ), NULL, this );
	x_slider->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MyFrame::x_sliderOnScroll ), NULL, this );
	x_slider->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MyFrame::x_sliderOnScroll ), NULL, this );
	x_slider->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MyFrame::x_sliderOnScroll ), NULL, this );
	x_slider->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MyFrame::x_sliderOnScroll ), NULL, this );
	y_slider->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MyFrame::y_sliderOnScroll ), NULL, this );
	y_slider->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MyFrame::y_sliderOnScroll ), NULL, this );
	y_slider->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MyFrame::y_sliderOnScroll ), NULL, this );
	y_slider->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MyFrame::y_sliderOnScroll ), NULL, this );
	y_slider->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MyFrame::y_sliderOnScroll ), NULL, this );
	y_slider->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MyFrame::y_sliderOnScroll ), NULL, this );
	y_slider->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MyFrame::y_sliderOnScroll ), NULL, this );
	y_slider->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MyFrame::y_sliderOnScroll ), NULL, this );
	y_slider->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MyFrame::y_sliderOnScroll ), NULL, this );
	z_slider->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MyFrame::z_sliderOnScroll ), NULL, this );
	z_slider->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MyFrame::z_sliderOnScroll ), NULL, this );
	z_slider->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MyFrame::z_sliderOnScroll ), NULL, this );
	z_slider->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MyFrame::z_sliderOnScroll ), NULL, this );
	z_slider->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MyFrame::z_sliderOnScroll ), NULL, this );
	z_slider->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MyFrame::z_sliderOnScroll ), NULL, this );
	z_slider->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MyFrame::z_sliderOnScroll ), NULL, this );
	z_slider->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MyFrame::z_sliderOnScroll ), NULL, this );
	z_slider->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MyFrame::z_sliderOnScroll ), NULL, this );
	save_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame::save_buttonOnButtonClick ), NULL, this );
	print_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame::print_buttonOnButtonClick ), NULL, this );
}

MyFrame::~MyFrame()
{
	// Disconnect Events
	drawing_panel->Disconnect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( MyFrame::drawing_panelUpdate ), NULL, this );
	function_choice->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( MyFrame::function_choiceOnChoice ), NULL, this );
	load_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame::load_buttonOnButtonClick ), NULL, this );
	draw_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame::draw_buttonOnButtonClick ), NULL, this );
	contour_checkBox->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MyFrame::contour_checkBoxOnCheckBox ), NULL, this );
	zoom_slider->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MyFrame::zoom_sliderOnScroll ), NULL, this );
	zoom_slider->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MyFrame::zoom_sliderOnScroll ), NULL, this );
	zoom_slider->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MyFrame::zoom_sliderOnScroll ), NULL, this );
	zoom_slider->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MyFrame::zoom_sliderOnScroll ), NULL, this );
	zoom_slider->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MyFrame::zoom_sliderOnScroll ), NULL, this );
	zoom_slider->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MyFrame::zoom_sliderOnScroll ), NULL, this );
	zoom_slider->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MyFrame::zoom_sliderOnScroll ), NULL, this );
	zoom_slider->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MyFrame::zoom_sliderOnScroll ), NULL, this );
	zoom_slider->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MyFrame::zoom_sliderOnScroll ), NULL, this );
	x_slider->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MyFrame::x_sliderOnScroll ), NULL, this );
	x_slider->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MyFrame::x_sliderOnScroll ), NULL, this );
	x_slider->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MyFrame::x_sliderOnScroll ), NULL, this );
	x_slider->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MyFrame::x_sliderOnScroll ), NULL, this );
	x_slider->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MyFrame::x_sliderOnScroll ), NULL, this );
	x_slider->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MyFrame::x_sliderOnScroll ), NULL, this );
	x_slider->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MyFrame::x_sliderOnScroll ), NULL, this );
	x_slider->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MyFrame::x_sliderOnScroll ), NULL, this );
	x_slider->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MyFrame::x_sliderOnScroll ), NULL, this );
	y_slider->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MyFrame::y_sliderOnScroll ), NULL, this );
	y_slider->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MyFrame::y_sliderOnScroll ), NULL, this );
	y_slider->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MyFrame::y_sliderOnScroll ), NULL, this );
	y_slider->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MyFrame::y_sliderOnScroll ), NULL, this );
	y_slider->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MyFrame::y_sliderOnScroll ), NULL, this );
	y_slider->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MyFrame::y_sliderOnScroll ), NULL, this );
	y_slider->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MyFrame::y_sliderOnScroll ), NULL, this );
	y_slider->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MyFrame::y_sliderOnScroll ), NULL, this );
	y_slider->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MyFrame::y_sliderOnScroll ), NULL, this );
	z_slider->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MyFrame::z_sliderOnScroll ), NULL, this );
	z_slider->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MyFrame::z_sliderOnScroll ), NULL, this );
	z_slider->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MyFrame::z_sliderOnScroll ), NULL, this );
	z_slider->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MyFrame::z_sliderOnScroll ), NULL, this );
	z_slider->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MyFrame::z_sliderOnScroll ), NULL, this );
	z_slider->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MyFrame::z_sliderOnScroll ), NULL, this );
	z_slider->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MyFrame::z_sliderOnScroll ), NULL, this );
	z_slider->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MyFrame::z_sliderOnScroll ), NULL, this );
	z_slider->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MyFrame::z_sliderOnScroll ), NULL, this );
	save_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame::save_buttonOnButtonClick ), NULL, this );
	print_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame::print_buttonOnButtonClick ), NULL, this );
	
}
