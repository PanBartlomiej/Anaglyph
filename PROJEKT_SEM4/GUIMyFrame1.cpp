#include "GUIMyFrame1.h"
#include <vector>
#include <fstream>

struct Point {
    double _x, _y, _z;
    Point(double x, double y, double z) : _x(x), _y(y), _z(z) {}
};



struct odc {
    Point _begin, _end;
   // Color color; 
    double _grubosc;
    odc(Point begin, Point end,double grubosc) :_begin(begin), _end(end),_grubosc(grubosc) {}
};

std::vector<odc> data;

struct kula_ba {
    Point _point;
    double _srednica;
    void set(Point point, double sr) { _point._x = point._x; _point._y = point._y; _point._z = point._z; _srednica = sr; }
}kula;

GUIMyFrame1::GUIMyFrame1( wxWindow* parent )
:
MyFrame1( parent )
{

}


void GUIMyFrame1::wczytajOnButtonClick( wxCommandEvent& event )
{
// TODO: Implement wczytajOnButtonClick
    wxFileDialog WxOpenFileDialog(this, wxT("Choose a file"), wxT(""), wxT(""), wxT("Geometry file (*.geo)|*.geo"), wxFD_OPEN | wxFD_FILE_MUST_EXIST);

    if (WxOpenFileDialog.ShowModal() == wxID_OK)
    {
        double test;
        double x1, y1, z1, x2, y2, z2;
        double grubosc;
       
        std::ifstream in(WxOpenFileDialog.GetPath().ToAscii());
        if (in.is_open())
        {
            data.clear();
            while (!in.eof())
            {
                in >> test;
                if (test == 1) {
                    in >> x1 >> y1 >> z1 >> x2 >> y2 >> z2 >> grubosc;
                    data.push_back(odc(Point(x1, y1, z1), Point(x2, y2, z2), grubosc));
                }
                else if (test == 2) {
                    in >> x1 >> y1 >> z1 >> x2;
                    kula.set(Point(x1, y1, z1), x2);
                    
                }
            }
            in.close();
        }
    }
}

void GUIMyFrame1::obrot_x_sliderOnScroll( wxScrollEvent& event )
{
// TODO: Implement obrot_x_sliderOnScroll
}

void GUIMyFrame1::obrot_y_sliderOnScroll( wxScrollEvent& event )
{
// TODO: Implement obrot_y_sliderOnScroll
}

void GUIMyFrame1::obrot_z_sliderOnScroll( wxScrollEvent& event )
{
// TODO: Implement obrot_z_sliderOnScroll
}

void GUIMyFrame1::focus_sliderOnScroll( wxScrollEvent& event )
{
// TODO: Implement focus_sliderOnScroll
}

void GUIMyFrame1::zapiszOnButtonClick( wxCommandEvent& event )
{
// TODO: Implement zapiszOnButtonClick
}
