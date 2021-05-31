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
    MyFrame1::SetPosition(wxPoint(0, 0));
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
        std::ifstream in(WxOpenFileDialog.GetPath().ToAscii());

        if (in.is_open())
        {
            info << "Plik wczytany poprawnie\n ";
            data.clear();
            in >> liczba_k;
            info << "liczba krawedzi:  " << liczba_k << "\n";
            while (!in.eof())
            {

                in >> test;
                if (test == 1) {
                    in >> x1 >> y1 >> z1 >> x2 >> y2 >> z2 >> grubosc;

                    info << x1 << " " << y1 << " " << z1 << " " << x2 << " " << y2 << " " << z2 << " " << grubosc << "\n";
                    makeSection(Point(x1, y1, z1), Point(x2, y2, z2), grubosc, 16, data);
                    //data.push_back(Section(Point(x1, y1, z1), Point(x2, y2, z2), grubosc));
                }
                else if (test == 2) {
                    in >> x1 >> y1 >> z1 >> x2;
                    {               //TODO: regulacja rozdzielczości kuli
                        makeSphere(Point(x1, y1, z1), x2, 256, data);
                        info << "kula:\n" << x1 << " " << y1 << " " << z1 << " r=" << x2 << "\n";

                    }
                }
            }
            in.close();
        }
    }
    else info << "Nie można wczytać pliku";
    m_textCtrl1->Clear();
    m_textCtrl1->WriteText(info);

    openRenderWindow(false);
    viewWindow->setData(data);
}

void GUIMyFrame1::sfmlTimerOnTimer(wxTimerEvent& event)
{
    if (viewWindow)
        if (!viewWindow->processMessages())
            closeRenderWindow();
}


Matrix4 GUIMyFrame1::rotacja() const
{
    float angle_x = obrot_x_slider->GetValue() * M_PI / 180.;
    float angle_y = obrot_y_slider->GetValue() * M_PI / 180.;
    float angle_z = obrot_z_slider->GetValue() * M_PI / 180.;
    Matrix4 rotate = CreateRotationMatrix(angle_y, 2) * CreateRotationMatrix(angle_x, 1) * CreateRotationMatrix(angle_z, 0);
    return rotate;
}

void GUIMyFrame1::obrot_x_sliderOnScroll(wxScrollEvent& event)
{
    if (viewWindow)
    {
        Matrix4 transformation = Matrix4();
        transformation.data[0][0] = 1;
        transformation.data[1][1] = 1;
        transformation.data[2][2] = 1;

        Matrix4 rotate = rotacja();
        viewWindow->Update(transformation, rotate);
    }
}

void GUIMyFrame1::obrot_y_sliderOnScroll(wxScrollEvent& event)
{
    if (viewWindow)
    {
        Matrix4 transformation = Matrix4();
        transformation.data[0][0] = 1;
        transformation.data[1][1] = 1;
        transformation.data[2][2] = 1;

        Matrix4 rotate = rotacja();
        viewWindow->Update(transformation, rotate);
    }
}

void GUIMyFrame1::obrot_z_sliderOnScroll(wxScrollEvent& event)
{
    if (viewWindow)
    {
        Matrix4 transformation = Matrix4();
        transformation.data[0][0] = 1;
        transformation.data[1][1] = 1;
        transformation.data[2][2] = 1;

        Matrix4 rotate = rotacja();
        viewWindow->Update(transformation, rotate);
    }
}

void GUIMyFrame1::focus_sliderOnScroll(wxScrollEvent& event)
{
    if (viewWindow)
    {
        viewWindow->setEyeFocus(2 + focus_slider->GetValue() / 10.);
    }
}

void GUIMyFrame1::distance_eye_sliderOnScroll(wxScrollEvent& event)
{
    if (viewWindow)
    {
        viewWindow->setEyeDistance(0.1 + (distance_eye_slider->GetValue() - 50.) / 500.);
    }
}

void GUIMyFrame1::kolor1OnColourChanged(wxColourPickerEvent& event)
{
    wxColour c1 = color_left_colourPicker->GetColour();
    wxColour c2 = color_right_colourPicker->GetColour();
    if (viewWindow)
    {
        viewWindow->setColors(c1.Red(), c1.Green(), c1.Blue(), c2.Red(), c2.Green(), c2.Blue());
    }
}

void GUIMyFrame1::kolor2OnColourChanged(wxColourPickerEvent& event)
{
    wxColour c1 = color_left_colourPicker->GetColour();
    wxColour c2 = color_right_colourPicker->GetColour();
    if (viewWindow)
    {
        viewWindow->setColors(c1.Red(), c1.Green(), c1.Blue(), c2.Red(), c2.Green(), c2.Blue());
    }
}

void GUIMyFrame1::openViewWindowBtnOnButtonClick(wxCommandEvent& event)
{
    //TO DO

    
    openRenderWindow(viewWindow);

    viewWindow->setData(data);
    wxColour c1 = color_left_colourPicker->GetColour();
    wxColour c2 = color_right_colourPicker->GetColour();
    if (viewWindow)
    {
        viewWindow->setColors(c1.Red(), c1.Green(), c1.Blue(), c2.Red(), c2.Green(), c2.Blue());
    }
}


void GUIMyFrame1::zapiszOnButtonClick(wxCommandEvent& event)
{
    std::string fileName;

    wxFileDialog saveDialog(this, "", "", "", "PNG files (*.png)|*.png|JPG files (*.jpg)|*.jpg", wxFD_SAVE | wxFD_OVERWRITE_PROMPT);

    if (saveDialog.ShowModal() == wxID_CANCEL) {
        return;
    }
    fileName = saveDialog.GetPath();
    if (viewWindow)
        viewWindow->ViewWindow::SaveToFile(fileName, ResolutionWidthSpinCtrl->GetValue(), ResolutionHeightSpinCtrl->GetValue());
}