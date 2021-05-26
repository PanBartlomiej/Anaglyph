///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.9.0 Apr  7 2021)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "GUI.h"

///////////////////////////////////////////////////////////////////////////

MyFrame1::MyFrame1( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );

	m_textCtrl1 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE|wxTE_READONLY );
	bSizer2->Add( m_textCtrl1, 1, wxALL|wxEXPAND, 5 );


	bSizer1->Add( bSizer2, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxVERTICAL );

	wczytaj = new wxButton( this, wxID_ANY, wxT("Wczytaj Plik"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( wczytaj, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );

	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxVERTICAL );

	bSizer4->SetMinSize( wxSize( 100,-1 ) );
	obrtot_x = new wxStaticText( this, wxID_ANY, wxT("Obrót X:"), wxDefaultPosition, wxDefaultSize, 0 );
	obrtot_x->Wrap( -1 );
	bSizer4->Add( obrtot_x, 0, wxALL, 5 );

	obrot_x_slider = new wxSlider( this, wxID_ANY, 0, -180, 180, wxDefaultPosition, wxSize( 100,-1 ), wxSL_HORIZONTAL );
	bSizer4->Add( obrot_x_slider, 0, wxALL|wxEXPAND, 5 );

	m_staticText2 = new wxStaticText( this, wxID_ANY, wxT("Obrót Y:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	bSizer4->Add( m_staticText2, 0, wxALL, 5 );

	obrot_y_slider = new wxSlider( this, wxID_ANY, 0, -180, 180, wxDefaultPosition, wxSize( 100,-1 ), wxSL_HORIZONTAL );
	bSizer4->Add( obrot_y_slider, 0, wxALL|wxEXPAND, 5 );

	m_staticText3 = new wxStaticText( this, wxID_ANY, wxT("Obrót Z:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3->Wrap( -1 );
	bSizer4->Add( m_staticText3, 0, wxALL, 5 );

	obrot_z_slider = new wxSlider( this, wxID_ANY, 0, -180, 180, wxDefaultPosition, wxSize( 100,-1 ), wxSL_HORIZONTAL );
	bSizer4->Add( obrot_z_slider, 0, wxALL|wxEXPAND, 5 );

	m_staticText4 = new wxStaticText( this, wxID_ANY, wxT("Przybliż:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText4->Wrap( -1 );
	bSizer4->Add( m_staticText4, 0, wxALL, 5 );

	focus_slider = new wxSlider( this, wxID_ANY, 50, 0, 100, wxDefaultPosition, wxSize( 100,-1 ), wxSL_HORIZONTAL );
	bSizer4->Add( focus_slider, 0, wxALL|wxEXPAND, 5 );

	m_staticText5 = new wxStaticText( this, wxID_ANY, wxT("Rozdzielczość"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText5->Wrap( -1 );
	bSizer4->Add( m_staticText5, 0, wxALL, 5 );

	wxString m_choice1Choices[] = { wxT("800x650") };
	int m_choice1NChoices = sizeof( m_choice1Choices ) / sizeof( wxString );
	m_choice1 = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choice1NChoices, m_choice1Choices, 0 );
	m_choice1->SetSelection( 0 );
	bSizer4->Add( m_choice1, 0, wxALL|wxEXPAND, 5 );

	m_staticText6 = new wxStaticText( this, wxID_ANY, wxT("Szerokość:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText6->Wrap( -1 );
	bSizer4->Add( m_staticText6, 0, wxALL, 5 );

	m_spinCtrl1 = new wxSpinCtrl( this, wxID_ANY, wxT("800"), wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 1, 4096, 0 );
	bSizer4->Add( m_spinCtrl1, 0, wxALL, 5 );

	m_staticText7 = new wxStaticText( this, wxID_ANY, wxT("Wysokość:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText7->Wrap( -1 );
	bSizer4->Add( m_staticText7, 0, wxALL, 5 );

	m_spinCtrl2 = new wxSpinCtrl( this, wxID_ANY, wxT("650"), wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 1, 4096, 0 );
	bSizer4->Add( m_spinCtrl2, 0, wxALL, 5 );

	m_button3 = new wxButton( this, wxID_ANY, wxT("Uruchom podgląd"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( m_button3, 0, wxALL|wxEXPAND, 5 );


	bSizer3->Add( bSizer4, 1, wxEXPAND, 5 );

	zapisz = new wxButton( this, wxID_ANY, wxT("zapisz"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( zapisz, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );


	bSizer1->Add( bSizer3, 0, wxEXPAND, 5 );


	this->SetSizer( bSizer1 );
	this->Layout();
	sfmlTimer.SetOwner( this, wxID_ANY );
	sfmlTimer.Start( 20 );


	this->Centre( wxBOTH );

	// Connect Events
	wczytaj->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::wczytajOnButtonClick ), NULL, this );
	obrot_x_slider->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MyFrame1::obrot_x_sliderOnScroll ), NULL, this );
	obrot_x_slider->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MyFrame1::obrot_x_sliderOnScroll ), NULL, this );
	obrot_x_slider->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MyFrame1::obrot_x_sliderOnScroll ), NULL, this );
	obrot_x_slider->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MyFrame1::obrot_x_sliderOnScroll ), NULL, this );
	obrot_x_slider->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MyFrame1::obrot_x_sliderOnScroll ), NULL, this );
	obrot_x_slider->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MyFrame1::obrot_x_sliderOnScroll ), NULL, this );
	obrot_x_slider->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MyFrame1::obrot_x_sliderOnScroll ), NULL, this );
	obrot_x_slider->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MyFrame1::obrot_x_sliderOnScroll ), NULL, this );
	obrot_x_slider->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MyFrame1::obrot_x_sliderOnScroll ), NULL, this );
	obrot_y_slider->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MyFrame1::obrot_y_sliderOnScroll ), NULL, this );
	obrot_y_slider->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MyFrame1::obrot_y_sliderOnScroll ), NULL, this );
	obrot_y_slider->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MyFrame1::obrot_y_sliderOnScroll ), NULL, this );
	obrot_y_slider->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MyFrame1::obrot_y_sliderOnScroll ), NULL, this );
	obrot_y_slider->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MyFrame1::obrot_y_sliderOnScroll ), NULL, this );
	obrot_y_slider->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MyFrame1::obrot_y_sliderOnScroll ), NULL, this );
	obrot_y_slider->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MyFrame1::obrot_y_sliderOnScroll ), NULL, this );
	obrot_y_slider->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MyFrame1::obrot_y_sliderOnScroll ), NULL, this );
	obrot_y_slider->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MyFrame1::obrot_y_sliderOnScroll ), NULL, this );
	obrot_z_slider->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MyFrame1::obrot_z_sliderOnScroll ), NULL, this );
	obrot_z_slider->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MyFrame1::obrot_z_sliderOnScroll ), NULL, this );
	obrot_z_slider->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MyFrame1::obrot_z_sliderOnScroll ), NULL, this );
	obrot_z_slider->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MyFrame1::obrot_z_sliderOnScroll ), NULL, this );
	obrot_z_slider->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MyFrame1::obrot_z_sliderOnScroll ), NULL, this );
	obrot_z_slider->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MyFrame1::obrot_z_sliderOnScroll ), NULL, this );
	obrot_z_slider->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MyFrame1::obrot_z_sliderOnScroll ), NULL, this );
	obrot_z_slider->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MyFrame1::obrot_z_sliderOnScroll ), NULL, this );
	obrot_z_slider->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MyFrame1::obrot_z_sliderOnScroll ), NULL, this );
	focus_slider->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MyFrame1::focus_sliderOnScroll ), NULL, this );
	focus_slider->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MyFrame1::focus_sliderOnScroll ), NULL, this );
	focus_slider->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MyFrame1::focus_sliderOnScroll ), NULL, this );
	focus_slider->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MyFrame1::focus_sliderOnScroll ), NULL, this );
	focus_slider->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MyFrame1::focus_sliderOnScroll ), NULL, this );
	focus_slider->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MyFrame1::focus_sliderOnScroll ), NULL, this );
	focus_slider->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MyFrame1::focus_sliderOnScroll ), NULL, this );
	focus_slider->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MyFrame1::focus_sliderOnScroll ), NULL, this );
	focus_slider->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MyFrame1::focus_sliderOnScroll ), NULL, this );
	zapisz->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::zapiszOnButtonClick ), NULL, this );
	this->Connect( wxID_ANY, wxEVT_TIMER, wxTimerEventHandler( MyFrame1::sfmlTimerOnTimer ) );
}

MyFrame1::~MyFrame1()
{
	// Disconnect Events
	wczytaj->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::wczytajOnButtonClick ), NULL, this );
	obrot_x_slider->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MyFrame1::obrot_x_sliderOnScroll ), NULL, this );
	obrot_x_slider->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MyFrame1::obrot_x_sliderOnScroll ), NULL, this );
	obrot_x_slider->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MyFrame1::obrot_x_sliderOnScroll ), NULL, this );
	obrot_x_slider->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MyFrame1::obrot_x_sliderOnScroll ), NULL, this );
	obrot_x_slider->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MyFrame1::obrot_x_sliderOnScroll ), NULL, this );
	obrot_x_slider->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MyFrame1::obrot_x_sliderOnScroll ), NULL, this );
	obrot_x_slider->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MyFrame1::obrot_x_sliderOnScroll ), NULL, this );
	obrot_x_slider->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MyFrame1::obrot_x_sliderOnScroll ), NULL, this );
	obrot_x_slider->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MyFrame1::obrot_x_sliderOnScroll ), NULL, this );
	obrot_y_slider->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MyFrame1::obrot_y_sliderOnScroll ), NULL, this );
	obrot_y_slider->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MyFrame1::obrot_y_sliderOnScroll ), NULL, this );
	obrot_y_slider->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MyFrame1::obrot_y_sliderOnScroll ), NULL, this );
	obrot_y_slider->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MyFrame1::obrot_y_sliderOnScroll ), NULL, this );
	obrot_y_slider->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MyFrame1::obrot_y_sliderOnScroll ), NULL, this );
	obrot_y_slider->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MyFrame1::obrot_y_sliderOnScroll ), NULL, this );
	obrot_y_slider->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MyFrame1::obrot_y_sliderOnScroll ), NULL, this );
	obrot_y_slider->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MyFrame1::obrot_y_sliderOnScroll ), NULL, this );
	obrot_y_slider->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MyFrame1::obrot_y_sliderOnScroll ), NULL, this );
	obrot_z_slider->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MyFrame1::obrot_z_sliderOnScroll ), NULL, this );
	obrot_z_slider->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MyFrame1::obrot_z_sliderOnScroll ), NULL, this );
	obrot_z_slider->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MyFrame1::obrot_z_sliderOnScroll ), NULL, this );
	obrot_z_slider->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MyFrame1::obrot_z_sliderOnScroll ), NULL, this );
	obrot_z_slider->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MyFrame1::obrot_z_sliderOnScroll ), NULL, this );
	obrot_z_slider->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MyFrame1::obrot_z_sliderOnScroll ), NULL, this );
	obrot_z_slider->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MyFrame1::obrot_z_sliderOnScroll ), NULL, this );
	obrot_z_slider->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MyFrame1::obrot_z_sliderOnScroll ), NULL, this );
	obrot_z_slider->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MyFrame1::obrot_z_sliderOnScroll ), NULL, this );
	focus_slider->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MyFrame1::focus_sliderOnScroll ), NULL, this );
	focus_slider->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MyFrame1::focus_sliderOnScroll ), NULL, this );
	focus_slider->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MyFrame1::focus_sliderOnScroll ), NULL, this );
	focus_slider->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MyFrame1::focus_sliderOnScroll ), NULL, this );
	focus_slider->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MyFrame1::focus_sliderOnScroll ), NULL, this );
	focus_slider->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MyFrame1::focus_sliderOnScroll ), NULL, this );
	focus_slider->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MyFrame1::focus_sliderOnScroll ), NULL, this );
	focus_slider->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MyFrame1::focus_sliderOnScroll ), NULL, this );
	focus_slider->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MyFrame1::focus_sliderOnScroll ), NULL, this );
	zapisz->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::zapiszOnButtonClick ), NULL, this );
	this->Disconnect( wxID_ANY, wxEVT_TIMER, wxTimerEventHandler( MyFrame1::sfmlTimerOnTimer ) );

}
