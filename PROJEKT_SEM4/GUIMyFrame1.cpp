#include "GUIMyFrame1.h"
#include <fstream>
#include <iostream>   
#include <string>  

const Resolution resolutionList[] =
{
    Resolution(800, 650), Resolution(640, 480), Resolution(720/2*3, 720), Resolution(1080/2*3, 1080), Resolution(2048/2*3, 2048), Resolution(4096/2*3, 4096), 
    Resolution(720/9*16, 720), Resolution(1080/9*16, 1080), Resolution(2048/9*16, 2048), Resolution(4096/9*16, 4096)
}; 

const FileExtension fileExtensionList [] = {FileExtension("Plik png", "png"), FileExtension("Plik jpg", "jpg"), FileExtension("Plik jpeg", "jpeg"), FileExtension("Bitmapa", "bmp")};

std::string getFileExtensionListAsStr(const FileExtension* begin, const FileExtension* end)
{
    std::string result;
    for (auto e=begin;e<end;e++)
        result += e->get() + "|";
    result.pop_back();
    return result;
}

GUIMyFrame1::GUIMyFrame1(wxWindow* parent) : MyFrame1(parent), viewWindow(NULL)
{
    openRenderWindow(true);
    MyFrame1::SetPosition(wxPoint(0, 0));
    for (auto r : resolutionList)
        ResolutionChoice->Append(r.toString());
    ResolutionChoice->SetSelection(0);
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

void GUIMyFrame1::AssignWindowResolutionOnButtonClick( wxCommandEvent& event ) 
{
    if (!viewWindow)
        return;
    auto size = viewWindow->getSize();
    ResolutionWidthSpinCtrl->SetValue(size.x);
    ResolutionHeightSpinCtrl->SetValue(size.y);
}

void GUIMyFrame1::FitProportionXBtnOnButtonClick( wxCommandEvent& event )
{
    if (!viewWindow)
        return;
    auto size = viewWindow->getSize();
    ResolutionWidthSpinCtrl->SetValue(ResolutionHeightSpinCtrl->GetValue()*((double)size.x/size.y));
}

void GUIMyFrame1::FitProportionYBtnOnButtonClick( wxCommandEvent& event )
{
    if (!viewWindow)
        return;
    auto size = viewWindow->getSize();
    ResolutionHeightSpinCtrl->SetValue(ResolutionWidthSpinCtrl->GetValue()*((double)size.y/size.x));
}

void GUIMyFrame1::wczytajOnButtonClick(wxCommandEvent& event)
{
    wxFileDialog WxOpenFileDialog(this, wxT("Choose a file"), wxT(""), wxT(""), wxT("Geometry file (*.txt)|*.txt"), wxFD_OPEN | wxFD_FILE_MUST_EXIST);
    wxString info = "";
    if (WxOpenFileDialog.ShowModal() == wxID_OK)
    {
        double test;
        double x1, y1, z1, x2, y2, z2;
        double grubosc;
        char znak;
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
                    makeSection(Point(x1, y1, z1), Point(x2, y2, z2), grubosc, 8, data);
                    //data.push_back(Section(Point(x1, y1, z1), Point(x2, y2, z2), grubosc));
                }
                else if (test == 2) {
                    in >> x1 >> y1 >> z1 >> x2;
                    {               //TODO: regulacja rozdzielczości kuli
                        makeSphere(Point(x1, y1, z1), x2, 256, data);
                        info << "kula:\n" << x1 << " " << y1 << " " << z1 << " r=" << x2 << "\n";

                    }
                }

                znak = 'a';
                while (znak != '\n')
                {
                    if (!in.eof())
                    {
                        in.get(znak);
                    }
                    else
                    {
                        znak = '\n';
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

void GUIMyFrame1::color_left_colourPickerOnColourChanged(wxColourPickerEvent& event)
{
    wxColour c1 = color_left_colourPicker->GetColour();
    wxColour c2 = color_right_colourPicker->GetColour();
    if (viewWindow)
    {
        viewWindow->setColors(c1.Red(), c1.Green(), c1.Blue(), c2.Red(), c2.Green(), c2.Blue());
    }
}

void GUIMyFrame1::color_right_colourPickerOnColourChanged(wxColourPickerEvent& event)
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
    wxFileDialog saveDialog(this, "", "", "", getFileExtensionListAsStr(std::begin(fileExtensionList), std::end(fileExtensionList)), wxFD_SAVE | wxFD_OVERWRITE_PROMPT);

    if (saveDialog.ShowModal() == wxID_CANCEL) {
        return;
    }
    std::string ext("." + fileExtensionList[saveDialog.GetFilterIndex()].extension);
    std::string fileName(saveDialog.GetPath());
    
    if (fileName.rfind(ext) != fileName.size()-ext.size())
        fileName += ext;
    
    if (viewWindow)
        viewWindow->ViewWindow::SaveToFile(fileName, ResolutionWidthSpinCtrl->GetValue(), ResolutionHeightSpinCtrl->GetValue(),  StretchToWindowProportionChk->IsChecked());
}

void GUIMyFrame1::ResolutionChoiceOnChoice( wxCommandEvent& event )
{
    const Resolution& r = resolutionList[ResolutionChoice->GetSelection()];
    ResolutionWidthSpinCtrl->SetValue(r.width);
    ResolutionHeightSpinCtrl->SetValue(r.height);
}
