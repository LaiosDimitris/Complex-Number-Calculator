#include <string>
#include <cctype>
#include "MainWindow.h"

BEGIN_EVENT_TABLE(MainWindow, wxFrame)
    EVT_BUTTON(001, MainWindow::add_button_click)
    EVT_BUTTON(002, MainWindow::sub_button_click)
    EVT_BUTTON(003, MainWindow::mul_button_click)
    EVT_BUTTON(004, MainWindow::div_button_click)
    EVT_BUTTON(005, MainWindow::result_button_click)
END_EVENT_TABLE()

MainWindow::MainWindow(wxWindow* parent,
    wxWindowID id,
    const wxString& title,
    const wxPoint& pos,
    const wxSize& size,
    long style,
    const wxString& name) :
    wxFrame(parent, id, title, pos, size, style, name)
{
    MainWindow::SetBackgroundColour(wxColour(*wxWHITE));
    MainWindow::SetFont(wxFont(13, wxFONTFAMILY_TELETYPE, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));

    // Widgets
    this->complex_num1 = new wxTextCtrl(this, wxID_ANY, "Enter Complex Number 1", wxPoint(10, 10), wxSize(230, 25), wxTE_READONLY);
    this->complex_num1_real = new wxTextCtrl(this, wxID_ANY, "Real", wxPoint(250, 10), wxSize(50, 25), wxTE_READONLY);
    this->complex_num1_real_input = new wxTextCtrl(this, wxID_ANY, "", wxPoint(300, 10), wxSize(60, 25));
    this->complex_num1_imag = new wxTextCtrl(this, wxID_ANY, "Imaginary", wxPoint(370, 10), wxSize(100, 25), wxTE_READONLY);
    this->complex_num1_imag_input = new wxTextCtrl(this, wxID_ANY, "", wxPoint(470, 10), wxSize(60, 25));

    this->complex_num2 = new wxTextCtrl(this, wxID_ANY, "Enter Complex Number 2", wxPoint(10, 40), wxSize(230, 25), wxTE_READONLY);
    this->complex_num2_real = new wxTextCtrl(this, wxID_ANY, "Real", wxPoint(250, 40), wxSize(50, 25), wxTE_READONLY);
    this->complex_num2_real_input = new wxTextCtrl(this, wxID_ANY, "", wxPoint(300, 40), wxSize(60, 25));
    this->complex_num2_imag = new wxTextCtrl(this, wxID_ANY, "Imaginary", wxPoint(370, 40), wxSize(100, 25), wxTE_READONLY);
    this->complex_num2_imag_input = new wxTextCtrl(this, wxID_ANY, "", wxPoint(470, 40), wxSize(60, 25));

    this->operation = new wxTextCtrl(this, wxID_ANY, "Enter Operator", wxPoint(10, 100), wxSize(150, 25), wxTE_READONLY);
    this->op_add = new wxButton(this, 001, "+", wxPoint(170, 98), wxSize(40, 30));
    this->op_add = new wxButton(this, 002, "-", wxPoint(230, 98), wxSize(40, 30));
    this->op_add = new wxButton(this, 003, "x", wxPoint(290, 98), wxSize(40, 30));
    this->op_add = new wxButton(this, 004, "/", wxPoint(350, 98), wxSize(40, 30));

    this->current_operator = new wxTextCtrl(this, wxID_ANY, "", wxPoint(550, 20), wxSize(30, 40));
    this->current_operator->SetFont(wxFont(25, wxFONTFAMILY_TELETYPE, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));

    this->result_button = new wxButton(this, 005, "Get Result", wxPoint(200, 180), wxSize(200, 40));
    this->result = new wxTextCtrl(this, wxID_ANY, "", wxPoint(148, 260), wxSize(300, 40));
    this->result->SetFont(wxFont(15, wxFONTFAMILY_TELETYPE, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
}

MainWindow::~MainWindow()
{
}

char c_operator;

void MainWindow::add_button_click(wxCommandEvent& evt)
{
    this->current_operator->SetLabelText('+');
    c_operator = '+';
}

void MainWindow::sub_button_click(wxCommandEvent& evt)
{
    this->current_operator->SetLabelText('-');
    c_operator = '-';
}

void MainWindow::mul_button_click(wxCommandEvent& evt)
{
    this->current_operator->SetLabelText('x');
    c_operator = 'x';
}

void MainWindow::div_button_click(wxCommandEvent& evt)
{
    this->current_operator->SetLabelText('/');
    c_operator = '/';
}

bool is_number(const std::string& str)
{
    int float_point_count = 0;

    if (!str.length()) {
        return false;
    }

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '.') {
            float_point_count++;

            if (float_point_count > 1) {
                return false;
            }
            else if (i == 0 || i == str.length() - 1) {
                return false;
            }
        }
        else if (!isdigit(str[i])) {
            return false;
        }
    }

    return true;
}

void MainWindow::result_button_click(wxCommandEvent& evt)
{
    double c1_re, c1_im;
    double c2_re, c2_im;

    std::string c1_re_str, c1_im_str;
    std::string c2_re_str, c2_im_str;

    c1_re_str = this->complex_num1_real_input->GetValue().ToStdString();
    c1_im_str = this->complex_num1_imag_input->GetValue().ToStdString();
    c2_re_str = this->complex_num2_real_input->GetValue().ToStdString();
    c2_im_str = this->complex_num2_imag_input->GetValue().ToStdString();
    
    bool error = false;

    if (!is_number(c1_re_str) || !is_number(c1_im_str) || !is_number(c2_re_str) || !is_number(c2_im_str)) {
        error = true;
    }
    else if (!c_operator) {
        error = true;
    }
    else {
        c1_re = std::stod(c1_re_str);
        c1_im = std::stod(c1_im_str);
        c2_re = std::stod(c2_re_str);
        c2_im = std::stod(c2_im_str);
    }
    
    if (error) {
        this->result->SetLabel("error");
    }
    else {
        Complex c1(c1_re, c1_im);
        Complex c2(c2_re, c2_im);

        Complex result;

        switch (c_operator)
        {
        case '+':
            result = c1 + c1;
            break;
        case '-':
            result = c1 - c2;
            break;
        case 'x':
            result = c1 * c1;
            break;
        case '/':
            result = c1 / c2;
            break;
        }

        std::string result_str;

        result_str += std::to_string(result.real());

        if (result.imag() > 0) {
            result_str += " + " + std::to_string(result.imag()) + "i";
        }
        else if (result.imag() < 0) {
            result_str += " - " + std::to_string(-result.imag()) + "i";
        }

        this->result->SetLabel(result_str);
    }
}