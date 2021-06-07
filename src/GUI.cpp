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

	wxBoxSizer* bSizer10;
	bSizer10 = new wxBoxSizer( wxHORIZONTAL );

	m_panel6 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxVERTICAL );

	wczytaj = new wxButton( m_panel6, wxID_ANY, wxT("Wczytaj Plik"), wxDefaultPosition, wxDefaultSize, 0 );
	wczytaj->SetToolTip( wxT("Kliknij, aby otworzyć okno dialogowe do otwarcia pliku") );

	bSizer7->Add( wczytaj, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );

	obrtot_x = new wxStaticText( m_panel6, wxID_ANY, wxT("Obrót X:"), wxDefaultPosition, wxDefaultSize, 0 );
	obrtot_x->Wrap( -1 );
	bSizer7->Add( obrtot_x, 0, wxALL, 5 );

	obrot_x_slider = new wxSlider( m_panel6, wxID_ANY, 0, -180, 180, wxDefaultPosition, wxSize( 100,-1 ), wxSL_HORIZONTAL );
	obrot_x_slider->SetToolTip( wxT("Obraca obiekt wokół osi X. \nKażda zmiana spowoduje cofnięcie przekształcenia naniesionego w oknie renderowania i dostosuje je do ustawień z tego menu.") );

	bSizer7->Add( obrot_x_slider, 0, wxALL|wxEXPAND, 5 );

	m_staticText2 = new wxStaticText( m_panel6, wxID_ANY, wxT("Obrót Y:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	bSizer7->Add( m_staticText2, 0, wxALL, 5 );

	obrot_y_slider = new wxSlider( m_panel6, wxID_ANY, 0, -180, 180, wxDefaultPosition, wxSize( 100,-1 ), wxSL_HORIZONTAL );
	obrot_y_slider->SetToolTip( wxT("Obraca obiekt wokół osi Y. \nKażda zmiana spowoduje cofnięcie przekształcenia naniesionego w oknie renderowania i dostosuje je do ustawień z tego menu.") );

	bSizer7->Add( obrot_y_slider, 0, wxALL|wxEXPAND, 5 );

	m_staticText3 = new wxStaticText( m_panel6, wxID_ANY, wxT("Obrót Z:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3->Wrap( -1 );
	bSizer7->Add( m_staticText3, 0, wxALL, 5 );

	obrot_z_slider = new wxSlider( m_panel6, wxID_ANY, 0, -180, 180, wxDefaultPosition, wxSize( 100,-1 ), wxSL_HORIZONTAL );
	obrot_z_slider->SetToolTip( wxT("Obraca obiekt wokół osi Z. \nKażda zmiana spowoduje cofnięcie przekształcenia naniesionego w oknie renderowania i dostosuje je do ustawień z tego menu.") );

	bSizer7->Add( obrot_z_slider, 0, wxALL|wxEXPAND, 5 );


	m_panel6->SetSizer( bSizer7 );
	m_panel6->Layout();
	bSizer7->Fit( m_panel6 );
	bSizer10->Add( m_panel6, 1, wxEXPAND | wxALL, 5 );

	m_panel7 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer( wxVERTICAL );

	m_staticText4 = new wxStaticText( m_panel7, wxID_ANY, wxT("Focus:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText4->Wrap( -1 );
	bSizer8->Add( m_staticText4, 0, wxALL, 5 );

	focus_slider = new wxSlider( m_panel7, wxID_ANY, 50, 0, 100, wxDefaultPosition, wxSize( 100,-1 ), wxSL_HORIZONTAL );
	focus_slider->SetToolTip( wxT("Ustawia punkt przecięcia się osi optycznych kamer") );

	bSizer8->Add( focus_slider, 0, wxALL|wxEXPAND, 5 );

	m_staticText8 = new wxStaticText( m_panel7, wxID_ANY, wxT("Rozstaw oczu:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText8->Wrap( -1 );
	bSizer8->Add( m_staticText8, 0, wxALL, 5 );

	distance_eye_slider = new wxSlider( m_panel7, wxID_ANY, 50, 0, 100, wxDefaultPosition, wxSize( 100,-1 ), wxSL_HORIZONTAL );
	distance_eye_slider->SetToolTip( wxT("Ustawia odległość między kamerami") );

	bSizer8->Add( distance_eye_slider, 0, wxALL|wxEXPAND, 5 );

	m_staticText9 = new wxStaticText( m_panel7, wxID_ANY, wxT("Kolor dla lewego oka:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText9->Wrap( -1 );
	bSizer8->Add( m_staticText9, 0, wxALL, 5 );

	color_right_colourPicker = new wxColourPickerCtrl( m_panel7, wxID_ANY, wxColour( 255, 0, 0 ), wxDefaultPosition, wxDefaultSize, wxCLRP_DEFAULT_STYLE );
	color_right_colourPicker->SetToolTip( wxT("Kliknij, aby otworzyć okno dialogowe do zmiany koloru") );

	bSizer8->Add( color_right_colourPicker, 0, wxALL|wxEXPAND, 5 );

	m_staticText10 = new wxStaticText( m_panel7, wxID_ANY, wxT("Kolor dla prawego oka:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText10->Wrap( -1 );
	bSizer8->Add( m_staticText10, 0, wxALL, 5 );

	color_left_colourPicker = new wxColourPickerCtrl( m_panel7, wxID_ANY, wxColour( 0, 0, 255 ), wxDefaultPosition, wxDefaultSize, wxCLRP_DEFAULT_STYLE );
	color_left_colourPicker->SetToolTip( wxT("Kliknij, aby otworzyć okno dialogowe do zmiany koloru") );

	bSizer8->Add( color_left_colourPicker, 0, wxALL|wxEXPAND, 5 );


	m_panel7->SetSizer( bSizer8 );
	m_panel7->Layout();
	bSizer8->Fit( m_panel7 );
	bSizer10->Add( m_panel7, 1, wxEXPAND | wxALL, 5 );

	m_panel8 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer( wxVERTICAL );

	m_staticText5 = new wxStaticText( m_panel8, wxID_ANY, wxT("Rozdzielczość"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText5->Wrap( -1 );
	bSizer9->Add( m_staticText5, 0, wxALL, 5 );

	wxArrayString ResolutionChoiceChoices;
	ResolutionChoice = new wxChoice( m_panel8, wxID_ANY, wxDefaultPosition, wxDefaultSize, ResolutionChoiceChoices, 0 );
	ResolutionChoice->SetSelection( 0 );
	ResolutionChoice->SetToolTip( wxT("Wybierz jedną z predefiniowanych rozdzielczości, aby ustawić odpowiednie wartości w polach \"Rozdzielczość X\" i \"Rozdzielczość Y\"") );

	bSizer9->Add( ResolutionChoice, 0, wxALL|wxEXPAND, 5 );

	AssignWindowResolution = new wxButton( m_panel8, wxID_ANY, wxT("Wczytaj rozdzielczość okna"), wxDefaultPosition, wxDefaultSize, 0 );
	AssignWindowResolution->SetToolTip( wxT("Skopiuj rozdzielczość okna do poniższych pól ustawień rozdzielczości") );

	bSizer9->Add( AssignWindowResolution, 0, wxALL, 5 );

	m_staticText6 = new wxStaticText( m_panel8, wxID_ANY, wxT("Rozdzielczość X zapisu:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText6->Wrap( -1 );
	bSizer9->Add( m_staticText6, 0, wxALL, 5 );

	wxBoxSizer* bSizer71;
	bSizer71 = new wxBoxSizer( wxVERTICAL );

	ResolutionWidthSpinCtrl = new wxSpinCtrl( m_panel8, wxID_ANY, wxT("800"), wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 1, 16384, 796 );
	ResolutionWidthSpinCtrl->SetToolTip( wxT("Ustaw szerokość zapisywanego obrazu") );

	bSizer71->Add( ResolutionWidthSpinCtrl, 0, wxALL, 5 );

	FitProportionXBtn = new wxButton( m_panel8, wxID_ANY, wxT("Dostosuj proporcję"), wxDefaultPosition, wxDefaultSize, 0 );
	FitProportionXBtn->SetToolTip( wxT("Dostosuj szerokość tak, by obraz nie był zdeformowany") );

	bSizer71->Add( FitProportionXBtn, 0, wxALL, 5 );


	bSizer9->Add( bSizer71, 1, wxEXPAND, 5 );

	m_staticText7 = new wxStaticText( m_panel8, wxID_ANY, wxT("Rozdzielczość Y zapisu:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText7->Wrap( -1 );
	bSizer9->Add( m_staticText7, 0, wxALL, 5 );

	wxBoxSizer* bSizer81;
	bSizer81 = new wxBoxSizer( wxVERTICAL );

	ResolutionHeightSpinCtrl = new wxSpinCtrl( m_panel8, wxID_ANY, wxT("650"), wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 1, 16384, 0 );
	ResolutionHeightSpinCtrl->SetToolTip( wxT("Ustaw wysokość zapisywanego obrazu") );

	bSizer81->Add( ResolutionHeightSpinCtrl, 0, wxALL, 5 );

	FitProportionYBtn = new wxButton( m_panel8, wxID_ANY, wxT("Dostosuj proporcję"), wxDefaultPosition, wxDefaultSize, 0 );
	FitProportionYBtn->SetToolTip( wxT("Dostosuj wysokość tak, by obraz nie był zdeformowany") );

	bSizer81->Add( FitProportionYBtn, 0, wxALL, 5 );


	bSizer9->Add( bSizer81, 1, wxEXPAND, 5 );

	StretchToWindowProportionChk = new wxCheckBox( m_panel8, wxID_ANY, wxT("Zdeformuj do proporcji okna"), wxDefaultPosition, wxDefaultSize, 0 );
	StretchToWindowProportionChk->SetToolTip( wxT("Jeśli to zaznaczysz, wyrenderowany obraz będzie zawierał dokładnie to samo, co okno renderowania, jednak przeskalowane do powyżej wybranej rozdzielczości.\nOdznaczenie powoduje zapisanie obrazu bez deformacji, a rozciągnięty i przycięty (lub z dodanymi czarnymi pasami wokół).") );

	bSizer9->Add( StretchToWindowProportionChk, 0, wxALL, 5 );

	zapisz = new wxButton( m_panel8, wxID_ANY, wxT("zapisz"), wxDefaultPosition, wxDefaultSize, 0 );
	zapisz->SetToolTip( wxT("Kliknij, aby otworzyć okno dialogowe do zapisania pliku") );

	bSizer9->Add( zapisz, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );


	m_panel8->SetSizer( bSizer9 );
	m_panel8->Layout();
	bSizer9->Fit( m_panel8 );
	bSizer10->Add( m_panel8, 1, wxEXPAND | wxALL, 5 );


	bSizer2->Add( bSizer10, 1, wxEXPAND, 5 );

	m_textCtrl1 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxPoint( -1,-1 ), wxDefaultSize, wxTE_MULTILINE|wxTE_READONLY );
	m_textCtrl1->SetToolTip( wxT("Konsola pokazujaca wierzchołki wczytanego obiektu. Tylko jako ciekawostka.") );
	m_textCtrl1->SetMinSize( wxSize( -1,100 ) );

	bSizer2->Add( m_textCtrl1, 0, wxALL|wxEXPAND, 5 );


	bSizer1->Add( bSizer2, 1, wxEXPAND, 5 );


	this->SetSizer( bSizer1 );
	this->Layout();
	sfmlTimer.SetOwner( this, wxID_ANY );
	sfmlTimer.Start( 5 );


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
	distance_eye_slider->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MyFrame1::distance_eye_sliderOnScroll ), NULL, this );
	distance_eye_slider->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MyFrame1::distance_eye_sliderOnScroll ), NULL, this );
	distance_eye_slider->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MyFrame1::distance_eye_sliderOnScroll ), NULL, this );
	distance_eye_slider->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MyFrame1::distance_eye_sliderOnScroll ), NULL, this );
	distance_eye_slider->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MyFrame1::distance_eye_sliderOnScroll ), NULL, this );
	distance_eye_slider->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MyFrame1::distance_eye_sliderOnScroll ), NULL, this );
	distance_eye_slider->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MyFrame1::distance_eye_sliderOnScroll ), NULL, this );
	distance_eye_slider->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MyFrame1::distance_eye_sliderOnScroll ), NULL, this );
	distance_eye_slider->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MyFrame1::distance_eye_sliderOnScroll ), NULL, this );
	color_right_colourPicker->Connect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( MyFrame1::color_right_colourPickerOnColourChanged ), NULL, this );
	color_left_colourPicker->Connect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( MyFrame1::color_left_colourPickerOnColourChanged ), NULL, this );
	ResolutionChoice->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( MyFrame1::ResolutionChoiceOnChoice ), NULL, this );
	AssignWindowResolution->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::AssignWindowResolutionOnButtonClick ), NULL, this );
	ResolutionWidthSpinCtrl->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( MyFrame1::ResolutionWidthSpinCtrlOnSpinCtrl ), NULL, this );
	FitProportionXBtn->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::FitProportionXBtnOnButtonClick ), NULL, this );
	ResolutionHeightSpinCtrl->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( MyFrame1::ResolutionHeightSpinCtrlOnSpinCtrl ), NULL, this );
	FitProportionYBtn->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::FitProportionYBtnOnButtonClick ), NULL, this );
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
	distance_eye_slider->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MyFrame1::distance_eye_sliderOnScroll ), NULL, this );
	distance_eye_slider->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MyFrame1::distance_eye_sliderOnScroll ), NULL, this );
	distance_eye_slider->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MyFrame1::distance_eye_sliderOnScroll ), NULL, this );
	distance_eye_slider->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MyFrame1::distance_eye_sliderOnScroll ), NULL, this );
	distance_eye_slider->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MyFrame1::distance_eye_sliderOnScroll ), NULL, this );
	distance_eye_slider->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MyFrame1::distance_eye_sliderOnScroll ), NULL, this );
	distance_eye_slider->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MyFrame1::distance_eye_sliderOnScroll ), NULL, this );
	distance_eye_slider->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MyFrame1::distance_eye_sliderOnScroll ), NULL, this );
	distance_eye_slider->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MyFrame1::distance_eye_sliderOnScroll ), NULL, this );
	color_right_colourPicker->Disconnect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( MyFrame1::color_right_colourPickerOnColourChanged ), NULL, this );
	color_left_colourPicker->Disconnect( wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler( MyFrame1::color_left_colourPickerOnColourChanged ), NULL, this );
	ResolutionChoice->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( MyFrame1::ResolutionChoiceOnChoice ), NULL, this );
	AssignWindowResolution->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::AssignWindowResolutionOnButtonClick ), NULL, this );
	ResolutionWidthSpinCtrl->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( MyFrame1::ResolutionWidthSpinCtrlOnSpinCtrl ), NULL, this );
	FitProportionXBtn->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::FitProportionXBtnOnButtonClick ), NULL, this );
	ResolutionHeightSpinCtrl->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( MyFrame1::ResolutionHeightSpinCtrlOnSpinCtrl ), NULL, this );
	FitProportionYBtn->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::FitProportionYBtnOnButtonClick ), NULL, this );
	zapisz->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::zapiszOnButtonClick ), NULL, this );
	this->Disconnect( wxID_ANY, wxEVT_TIMER, wxTimerEventHandler( MyFrame1::sfmlTimerOnTimer ) );

}
