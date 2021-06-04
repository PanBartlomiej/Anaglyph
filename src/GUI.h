///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.9.0 Apr  7 2021)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/button.h>
#include <wx/string.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/stattext.h>
#include <wx/slider.h>
#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/clrpicker.h>
#include <wx/choice.h>
#include <wx/spinctrl.h>
#include <wx/checkbox.h>
#include <wx/textctrl.h>
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
		wxPanel* m_panel6;
		wxButton* wczytaj;
		wxStaticText* obrtot_x;
		wxSlider* obrot_x_slider;
		wxStaticText* m_staticText2;
		wxSlider* obrot_y_slider;
		wxStaticText* m_staticText3;
		wxSlider* obrot_z_slider;
		wxPanel* m_panel7;
		wxStaticText* m_staticText4;
		wxSlider* focus_slider;
		wxStaticText* m_staticText8;
		wxSlider* distance_eye_slider;
		wxStaticText* m_staticText9;
		wxColourPickerCtrl* color_right_colourPicker;
		wxStaticText* m_staticText10;
		wxColourPickerCtrl* color_left_colourPicker;
		wxPanel* m_panel8;
		wxStaticText* m_staticText5;
		wxChoice* ResolutionChoice;
		wxButton* AssignWindowResolution;
		wxStaticText* m_staticText6;
		wxSpinCtrl* ResolutionWidthSpinCtrl;
		wxButton* FitProportionXBtn;
		wxStaticText* m_staticText7;
		wxSpinCtrl* ResolutionHeightSpinCtrl;
		wxButton* FitProportionYBtn;
		wxCheckBox* StretchToWindowProportionChk;
		wxButton* zapisz;
		wxTextCtrl* m_textCtrl1;
		wxTimer sfmlTimer;

		// Virtual event handlers, override them in your derived class
		virtual void wczytajOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void obrot_x_sliderOnScroll( wxScrollEvent& event ) { event.Skip(); }
		virtual void obrot_y_sliderOnScroll( wxScrollEvent& event ) { event.Skip(); }
		virtual void obrot_z_sliderOnScroll( wxScrollEvent& event ) { event.Skip(); }
		virtual void focus_sliderOnScroll( wxScrollEvent& event ) { event.Skip(); }
		virtual void distance_eye_sliderOnScroll( wxScrollEvent& event ) { event.Skip(); }
		virtual void color_right_colourPickerOnColourChanged( wxColourPickerEvent& event ) { event.Skip(); }
		virtual void color_left_colourPickerOnColourChanged( wxColourPickerEvent& event ) { event.Skip(); }
		virtual void ResolutionChoiceOnChoice( wxCommandEvent& event ) { event.Skip(); }
		virtual void AssignWindowResolutionOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void ResolutionWidthSpinCtrlOnSpinCtrl( wxSpinEvent& event ) { event.Skip(); }
		virtual void FitProportionXBtnOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void ResolutionHeightSpinCtrlOnSpinCtrl( wxSpinEvent& event ) { event.Skip(); }
		virtual void FitProportionYBtnOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void zapiszOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void sfmlTimerOnTimer( wxTimerEvent& event ) { event.Skip(); }


	public:

		MyFrame1( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxPoint( -1,-1 ), const wxSize& size = wxSize( 886,585 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~MyFrame1();

};

