///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct 26 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "GUI.h"

///////////////////////////////////////////////////////////////////////////

MyFrame::MyFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( -1,-1 ), wxDefaultSize );

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

	wxString function_choiceChoices[] = { wxT("Funkcja0"), wxT("Funkcja1"), wxT("Funkcja2"), wxT("Funkcja3"), wxT("Funkcja4") };
	int function_choiceNChoices = sizeof( function_choiceChoices ) / sizeof( wxString );
	function_choice = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxSize( 90,-1 ), function_choiceNChoices, function_choiceChoices, 0 );
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

	x0_SpinCtrlDouble = new wxSpinCtrlDouble( this, wxID_ANY, wxT("-50"), wxDefaultPosition, wxSize( 70,30 ), wxSP_ARROW_KEYS, -999, 999, 0.000000, 1 );
	x0_SpinCtrlDouble->SetDigits( 0 );
	bSizer712->Add( x0_SpinCtrlDouble, 0, wxALL, 5 );

	m_staticText8 = new wxStaticText( this, wxID_ANY, wxT("y0:"), wxDefaultPosition, wxSize( -1,20 ), 0 );
	m_staticText8->Wrap( -1 );
	bSizer712->Add( m_staticText8, 0, wxALL, 5 );

	y0_SpinCtrlDouble = new wxSpinCtrlDouble( this, wxID_ANY, wxT("-50"), wxDefaultPosition, wxSize( 70,30 ), wxSP_ARROW_KEYS, -999, 999, 0, 1 );
	y0_SpinCtrlDouble->SetDigits( 0 );
	bSizer712->Add( y0_SpinCtrlDouble, 0, wxALL, 5 );

	m_staticText9 = new wxStaticText( this, wxID_ANY, wxT("z0:"), wxDefaultPosition, wxSize( -1,20 ), 0 );
	m_staticText9->Wrap( -1 );
	bSizer712->Add( m_staticText9, 0, wxALL, 5 );

	z0_SpinCtrlDouble = new wxSpinCtrlDouble( this, wxID_ANY, wxT("-50"), wxDefaultPosition, wxSize( 70,30 ), wxSP_ARROW_KEYS, -999, 999, 0, 1 );
	z0_SpinCtrlDouble->SetDigits( 0 );
	bSizer712->Add( z0_SpinCtrlDouble, 0, wxALL, 5 );


	bSizer7->Add( bSizer712, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer7121;
	bSizer7121 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText221 = new wxStaticText( this, wxID_ANY, wxT("x1:"), wxDefaultPosition, wxSize( -1,20 ), 0 );
	m_staticText221->Wrap( -1 );
	bSizer7121->Add( m_staticText221, 0, wxALL, 5 );

	x1_SpinCtrlDouble = new wxSpinCtrlDouble( this, wxID_ANY, wxT("50"), wxDefaultPosition, wxSize( 70,30 ), wxSP_ARROW_KEYS, -999, 999, 0, 1 );
	x1_SpinCtrlDouble->SetDigits( 0 );
	bSizer7121->Add( x1_SpinCtrlDouble, 0, wxALL, 5 );

	m_staticText81 = new wxStaticText( this, wxID_ANY, wxT("y1:"), wxDefaultPosition, wxSize( -1,20 ), 0 );
	m_staticText81->Wrap( -1 );
	bSizer7121->Add( m_staticText81, 0, wxALL, 5 );

	y1_SpinCtrlDouble = new wxSpinCtrlDouble( this, wxID_ANY, wxT("50"), wxDefaultPosition, wxSize( 70,30 ), wxSP_ARROW_KEYS, -999, 999, 0, 1 );
	y1_SpinCtrlDouble->SetDigits( 0 );
	bSizer7121->Add( y1_SpinCtrlDouble, 0, wxALL, 5 );

	m_staticText91 = new wxStaticText( this, wxID_ANY, wxT("z1:"), wxDefaultPosition, wxSize( -1,20 ), 0 );
	m_staticText91->Wrap( -1 );
	bSizer7121->Add( m_staticText91, 0, wxALL, 5 );

	z1_SpinCtrlDouble = new wxSpinCtrlDouble( this, wxID_ANY, wxT("50"), wxDefaultPosition, wxSize( 70,30 ), wxSP_ARROW_KEYS, -999, 999, 0, 1 );
	z1_SpinCtrlDouble->SetDigits( 0 );
	bSizer7121->Add( z1_SpinCtrlDouble, 0, wxALL, 5 );


	bSizer7->Add( bSizer7121, 1, wxEXPAND, 5 );

	draw_button = new wxButton( this, wxID_ANY, wxT("Rysuj"), wxDefaultPosition, wxSize( 60,-1 ), 0 );
	bSizer7->Add( draw_button, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	contour_checkBox = new wxCheckBox( this, wxID_ANY, wxT("konturowa"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer7->Add( contour_checkBox, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	wxWrapSizer* wSizer1;
	wSizer1 = new wxWrapSizer( wxHORIZONTAL, wxWRAPSIZER_DEFAULT_FLAGS );

	x_step_staticText = new wxStaticText( this, wxID_ANY, wxT("krok_x:"), wxDefaultPosition, wxDefaultSize, 0 );
	x_step_staticText->Wrap( -1 );
	wSizer1->Add( x_step_staticText, 0, wxALIGN_CENTER|wxALL, 5 );

	x_step_spinCtrl = new wxSpinCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 70,30 ), wxSP_ARROW_KEYS, 1, 999, 10 );
	wSizer1->Add( x_step_spinCtrl, 0, wxALIGN_CENTER|wxALL, 5 );

	y_step_staticText = new wxStaticText( this, wxID_ANY, wxT("krok_y:"), wxDefaultPosition, wxDefaultSize, 0 );
	y_step_staticText->Wrap( -1 );
	wSizer1->Add( y_step_staticText, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	y_step_spinCtrl = new wxSpinCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 70,30 ), wxSP_ARROW_KEYS, 1, 999, 10 );
	wSizer1->Add( y_step_spinCtrl, 0, wxALL, 5 );


	bSizer7->Add( wSizer1, 1, wxALIGN_CENTER_HORIZONTAL|wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer10114;
	bSizer10114 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText2313 = new wxStaticText( this, wxID_ANY, wxT("Zoom:"), wxDefaultPosition, wxSize( -1,20 ), 0 );
	m_staticText2313->Wrap( -1 );
	bSizer10114->Add( m_staticText2313, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	zoom_slider = new wxSlider( this, wxID_ANY, 50, 0, 100, wxDefaultPosition, wxSize( -1,20 ), wxSL_HORIZONTAL );
	bSizer10114->Add( zoom_slider, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer7->Add( bSizer10114, 1, wxALL|wxEXPAND, 5 );

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


	bSizer1->Add( bSizer7, 1, wxALL|wxEXPAND, 5 );


	this->SetSizer( bSizer1 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	drawing_panel->Connect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( MyFrame::drawing_panelUpdate ), NULL, this );
	function_choice->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( MyFrame::function_choiceOnChoice ), NULL, this );
	load_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame::load_buttonOnButtonClick ), NULL, this );
	x0_SpinCtrlDouble->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MyFrame::x0_update ), NULL, this );
	y0_SpinCtrlDouble->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MyFrame::y0_update ), NULL, this );
	z0_SpinCtrlDouble->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MyFrame::z0_update ), NULL, this );
	x1_SpinCtrlDouble->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MyFrame::x1_update ), NULL, this );
	y1_SpinCtrlDouble->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MyFrame::y1_update ), NULL, this );
	z1_SpinCtrlDouble->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MyFrame::z1_update ), NULL, this );
	draw_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame::draw_buttonOnButtonClick ), NULL, this );
	contour_checkBox->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MyFrame::contour_checkBoxOnCheckBox ), NULL, this );
	x_step_spinCtrl->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MyFrame::x_step_update ), NULL, this );
	y_step_spinCtrl->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MyFrame::y_step_update ), NULL, this );
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
	x0_SpinCtrlDouble->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MyFrame::x0_update ), NULL, this );
	y0_SpinCtrlDouble->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MyFrame::y0_update ), NULL, this );
	z0_SpinCtrlDouble->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MyFrame::z0_update ), NULL, this );
	x1_SpinCtrlDouble->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MyFrame::x1_update ), NULL, this );
	y1_SpinCtrlDouble->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MyFrame::y1_update ), NULL, this );
	z1_SpinCtrlDouble->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MyFrame::z1_update ), NULL, this );
	draw_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame::draw_buttonOnButtonClick ), NULL, this );
	contour_checkBox->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MyFrame::contour_checkBoxOnCheckBox ), NULL, this );
	x_step_spinCtrl->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MyFrame::x_step_update ), NULL, this );
	y_step_spinCtrl->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MyFrame::y_step_update ), NULL, this );
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
