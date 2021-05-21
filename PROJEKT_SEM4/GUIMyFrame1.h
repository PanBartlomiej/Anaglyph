#ifndef __GUIMyFrame1__
#define __GUIMyFrame1__

/**
@file
Subclass of MyFrame1, which is generated by wxFormBuilder.
*/

#include "GUI.h"

//// end generated include
#include <wx/filedlg.h>
#include <wx/dcmemory.h>
#include <wx/dcclient.h>
#include <wx/dcbuffer.h>
#include <wx/colourdata.h>
#include <wx/colordlg.h>
#include <tuple>
#include <vector>
#include "wec.h"
#include "structures.h"
#include "ViewWindow.h"


/** Implementing MyFrame1 */
class GUIMyFrame1 : public MyFrame1
{
protected:
	// Handlers for MyFrame1 events.
	~GUIMyFrame1();
	void wczytajOnButtonClick(wxCommandEvent& event);
	void obrot_x_sliderOnScroll(wxScrollEvent& event);
	void obrot_y_sliderOnScroll(wxScrollEvent& event);
	void obrot_z_sliderOnScroll(wxScrollEvent& event);
	void focus_sliderOnScroll(wxScrollEvent& event);
	void zapiszOnButtonClick(wxCommandEvent& event);

	void sfmlTimerOnTimer(wxTimerEvent& event);

	void closeRenderWindow();
	void openRenderWindow(const bool restart, const int width = 800, const int height = 650, const char* title = "Render window");
public:
	/** Constructor */
	GUIMyFrame1(wxWindow* parent);
	//// end generated class members
	Matrix4 rotuj_x(double x);
	Matrix4 rotuj_y(double y);
	Matrix4 rotuj_z(double z);
	ViewWindow* viewWindow;

	std::vector<Section> data;
	Sphere kula;
        unsigned liczba_k; //liczba krawędzi


};


#endif // __GUIMyFrame1__
