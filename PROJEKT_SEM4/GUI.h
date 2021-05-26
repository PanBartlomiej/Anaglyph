///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.9.0 Apr  7 2021)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/textctrl.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/stattext.h>
#include <wx/slider.h>
#include <wx/choice.h>
#include <wx/spinctrl.h>
#include <wx/timer.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class MyFrame1
///////////////////////////////////////////////////////////////////////////////
class MyFrame1 : public wxFrame
{
	private:

	protected:
		wxTextCtrl* m_textCtrl1;
		wxButton* wczytaj;
		wxStaticText* obrtot_x;
		wxSlider* obrot_x_slider;
		wxStaticText* m_staticText2;
		wxSlider* obrot_y_slider;
		wxStaticText* m_staticText3;
		wxSlider* obrot_z_slider;
		wxStaticText* m_staticText4;
		wxSlider* focus_slider;
		wxStaticText* m_staticText5;
		wxChoice* m_choice1;
		wxStaticText* m_staticText6;
		wxSpinCtrl* m_spinCtrl1;
		wxStaticText* m_staticText7;
		wxSpinCtrl* m_spinCtrl2;
		wxButton* m_button3;
		wxButton* zapisz;
		wxTimer sfmlTimer;

		// Virtual event handlers, override them in your derived class
		virtual void wczytajOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void obrot_x_sliderOnScroll( wxScrollEvent& event ) { event.Skip(); }
		virtual void obrot_y_sliderOnScroll( wxScrollEvent& event ) { event.Skip(); }
		virtual void obrot_z_sliderOnScroll( wxScrollEvent& event ) { event.Skip(); }
		virtual void focus_sliderOnScroll( wxScrollEvent& event ) { event.Skip(); }
		virtual void zapiszOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void sfmlTimerOnTimer( wxTimerEvent& event ) { event.Skip(); }


	public:

		MyFrame1( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 969,673 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~MyFrame1();

};

