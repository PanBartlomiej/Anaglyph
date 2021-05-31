///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct 26 2018)
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
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/button.h>
#include <wx/stattext.h>
#include <wx/slider.h>
#include <wx/clrpicker.h>
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
		wxStaticText* m_staticText8;
		wxSlider* distance_eye_slider;
		wxStaticText* m_staticText13;
		wxColourPickerCtrl* color_left_colourPicker;
		wxStaticText* m_staticText14;
		wxColourPickerCtrl* color_right_colourPicker;
		wxStaticText* m_staticText5;
		wxChoice* ResolutionChoice;
		wxStaticText* m_staticText6;
		wxSpinCtrl* ResolutionWidthSpinCtrl;
		wxStaticText* m_staticText7;
		wxSpinCtrl* ResolutionHeightSpinCtrl;
		wxButton* openViewWindowBtn;
		wxTimer sfmlTimer;

		// Virtual event handlers, overide them in your derived class
		virtual void wczytajOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void obrot_x_sliderOnScroll( wxScrollEvent& event ) { event.Skip(); }
		virtual void obrot_y_sliderOnScroll( wxScrollEvent& event ) { event.Skip(); }
		virtual void obrot_z_sliderOnScroll( wxScrollEvent& event ) { event.Skip(); }
		virtual void focus_sliderOnScroll( wxScrollEvent& event ) { event.Skip(); }
		virtual void distance_eye_sliderOnScroll( wxScrollEvent& event ) { event.Skip(); }
		virtual void kolor1OnColourChanged( wxColourPickerEvent& event ) { event.Skip(); }
		virtual void kolor2OnColourChanged( wxColourPickerEvent& event ) { event.Skip(); }
		virtual void ResolutionChoiceOnChoice( wxCommandEvent& event ) { event.Skip(); }
		virtual void ResolutionWidthSpinCtrlOnSpinCtrl( wxSpinEvent& event ) { event.Skip(); }
		virtual void ResolutionHeightSpinCtrlOnSpinCtrl( wxSpinEvent& event ) { event.Skip(); }
		virtual void openViewWindowBtnOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void sfmlTimerOnTimer( wxTimerEvent& event ) { event.Skip(); }


	public:

		MyFrame1( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 1000,750 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~MyFrame1();

};

