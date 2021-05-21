#include "GUIMyFrame1.h"
#include <fstream>
#include <iostream>   
#include <string>  


GUIMyFrame1::GUIMyFrame1(wxWindow* parent) : MyFrame1(parent), viewWindow(NULL)
{
    openRenderWindow(true);
    obrtot_x->SetLabel(_("Obr\u00F3t X:"));
    m_staticText2->SetLabel(_("Obr\u00F3t Y:"));
    m_staticText3->SetLabel(_("Obr\u00F3t Z:"));
    m_staticText4->SetLabel(_("Focus:"));
}

GUIMyFrame1::~GUIMyFrame1()
{
    closeRenderWindow();
}

void GUIMyFrame1::closeRenderWindow()
{
    if (viewWindow)
    {
        delete viewWindow;
        viewWindow = NULL;
    }
}

void GUIMyFrame1::openRenderWindow(const bool restart, const int width, const int height, const char* title)
{
    if (restart)
        closeRenderWindow();
    if (!viewWindow)
        viewWindow = new ViewWindow(width, height, title);
}

void GUIMyFrame1::wczytajOnButtonClick(wxCommandEvent& event)
{
    // TODO: Implement wczytajOnButtonClick
    wxFileDialog WxOpenFileDialog(this, wxT("Choose a file"), wxT(""), wxT(""), wxT("Geometry file (*.txt)|*.txt"), wxFD_OPEN | wxFD_FILE_MUST_EXIST);
    wxString info = "";
    if (WxOpenFileDialog.ShowModal() == wxID_OK)
    {
        double test;
        double x1, y1, z1, x2, y2, z2;
        double grubosc;
        unsigned liczba_k; //liczba krawędzi
        std::ifstream in(WxOpenFileDialog.GetPath().ToAscii());

        if (in.is_open())
        {
            info << "Plik wczytany poprawnie\n ";
            data.clear();
            in >> liczba_k;
            info << "liczba krawedzi:  "<<liczba_k<<"\n";
            while (!in.eof())
            {
                
                in >> test;
                if (test == 1) {
                    in >> x1 >> y1 >> z1 >> x2 >> y2 >> z2 >> grubosc;

                    info << x1 << " " << y1 << " " << z1 << " " << x2 << " " << y2 << " " << z2 << " " << grubosc << "\n";
                    data.push_back(Section(Point(x1, y1, z1), Point(x2, y2, z2), grubosc));
                }
                else if (test == 2) {
                    in >> x1 >> y1 >> z1 >> x2;
                    {               //TODO: regulacja rozdzielczości kuli
                        makeSphere(Point(x1, y1, z1), x2, 100, data);
                        info << "kula:\n" << x1 << " " << y1 << " " << z1 << " r=" << x2 << "\n";

                    }
                }
            }
            in.close();
        }
    }
    else info << "Nie można wczytać pliku";
    m_richText1->Clear();
    m_richText1->WriteText(info);
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

void GUIMyFrame1::sfmlTimerOnTimer(wxTimerEvent& event)
{
    if (viewWindow)
        if (!viewWindow->processMessages())
            closeRenderWindow();
}

void GUIMyFrame1::obrot_x_sliderOnScroll(wxScrollEvent& event)
{
    // TODO: Implement obrot_x_sliderOnScroll
}

void GUIMyFrame1::obrot_y_sliderOnScroll(wxScrollEvent& event)
{
    // TODO: Implement obrot_y_sliderOnScroll
}

void GUIMyFrame1::obrot_z_sliderOnScroll(wxScrollEvent& event)
{
    // TODO: Implement obrot_z_sliderOnScroll
}

void GUIMyFrame1::focus_sliderOnScroll(wxScrollEvent& event)
{
    // TODO: Implement focus_sliderOnScroll
}

void GUIMyFrame1::zapiszOnButtonClick(wxCommandEvent& event)
{
    // TODO: Implement zapiszOnButtonClick
}