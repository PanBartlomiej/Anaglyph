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

	m_panel1 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_panel1->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_HIGHLIGHTTEXT ) );

	bSizer2->Add( m_panel1, 1, wxEXPAND | wxALL, 5 );


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


	bSizer3->Add( bSizer4, 1, wxEXPAND, 5 );

	zapisz = new wxButton( this, wxID_ANY, wxT("zapisz"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( zapisz, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );


	bSizer1->Add( bSizer3, 0, wxEXPAND, 5 );


	this->SetSizer( bSizer1 );
	this->Layout();
	m_timer1.SetOwner( this, wxID_ANY );
	m_timer1.Start( 20 );


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

}
