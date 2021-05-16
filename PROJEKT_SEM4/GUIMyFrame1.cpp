#include "GUIMyFrame1.h"
#include <vector>
#include <fstream>

struct Point {
    double _x, _y, _z;
    Point(double x, double y, double z) : _x(x), _y(y), _z(z) {}
    Point() = default;
    void print()const { printf("%f %f %f", _x, _y, _z); }
    void set(double x, double y, double z) { _x = x; _y = y, _z = z; }
};



struct odc {
    Point _begin, _end;
   // Color color; 
    double _grubosc;
    odc(Point begin, Point end,double grubosc) :_begin(begin), _end(end),_grubosc(grubosc) {}

};

std::vector<odc> data;

class kulaa {
public:
    
    Point _point;
    double _sr; 
    kulaa() {}
};
kulaa kula;

GUIMyFrame1::GUIMyFrame1( wxWindow* parent )
:
MyFrame1( parent )
{

}


void GUIMyFrame1::wczytajOnButtonClick( wxCommandEvent& event )
{
// TODO: Implement wczytajOnButtonClick
    wxFileDialog WxOpenFileDialog(this, wxT("Choose a file"), wxT(""), wxT(""), wxT("Geometry file (*.txt)|*.txt"), wxFD_OPEN | wxFD_FILE_MUST_EXIST);

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
                    {
                        kula._point.set(x1, y1, z1);
                        kula._sr = x2;
                    }
                    
                }
            }
            in.close();
        }
    }
   
}


Matrix4 GUIMyFrame1::rotuj_x(double x) {
    Matrix4 macierz;
    double fi = (x * M_PI / 180.0);
    macierz.data[0][0] = 1.0; macierz.data[1][1] = cos(fi);
    macierz.data[2][2] = cos(fi); macierz.data[3][3] = 1.0;
    macierz.data[1][2] = -sin(fi); macierz.data[2][1] = sin(fi);
    return macierz;
}
Matrix4 GUIMyFrame1::rotuj_y(double x) {
    Matrix4 macierz;
    double fi = (x * M_PI / 180.0);
    macierz.data[0][0] = cos(fi); macierz.data[0][2] = sin(fi);
    macierz.data[1][1] = 1.0;   macierz.data[2][0] = -sin(fi);
    macierz.data[2][2] = sin(fi); macierz.data[3][3] = 1.0;
    return macierz;

}
Matrix4 GUIMyFrame1::rotuj_z(double x) {
    Matrix4 macierz;
    double fi = (x * M_PI / 180.0);
    macierz.data[0][0] = cos(fi); macierz.data[1][1] = cos(fi);
    macierz.data[0][1] = -sin(fi); macierz.data[1][0] = sin(fi);
    macierz.data[2][2] = 1.0; macierz.data[3][3] = 1.0;
    return macierz;
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
