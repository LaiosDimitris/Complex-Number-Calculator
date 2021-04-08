#pragma once
#include <wx/wxprec.h>
#include "../Complex/Complex.hpp"

#ifndef WX_PRECOMP
	#include <wx/wx.h>
#endif

class MainWindow : public wxFrame
{
public:
	MainWindow(wxWindow* parent,
        wxWindowID id,
        const wxString& title,
        const wxPoint& pos = wxDefaultPosition,
        const wxSize& size = wxDefaultSize,
        long style = wxDEFAULT_FRAME_STYLE,
        const wxString& name = wxFrameNameStr);
   ~MainWindow();

   wxTextCtrl* complex_num1 = nullptr;
   wxTextCtrl* complex_num1_real = nullptr;
   wxTextCtrl* complex_num1_real_input = nullptr;
   wxTextCtrl* complex_num1_imag = nullptr;
   wxTextCtrl* complex_num1_imag_input = nullptr;

   wxTextCtrl* complex_num2 = nullptr;
   wxTextCtrl* complex_num2_real = nullptr;
   wxTextCtrl* complex_num2_real_input = nullptr;
   wxTextCtrl* complex_num2_imag = nullptr;
   wxTextCtrl* complex_num2_imag_input = nullptr;

   wxTextCtrl* operation = nullptr;
   wxTextCtrl* current_operator = nullptr;
   wxButton* op_add = nullptr;
   wxButton* op_sub = nullptr;
   wxButton* op_mul = nullptr;
   wxButton* op_div = nullptr;

   wxButton* result_button = nullptr;
   wxTextCtrl* result = nullptr;
   
   void add_button_click(wxCommandEvent& evt);
   void sub_button_click(wxCommandEvent& evt);
   void mul_button_click(wxCommandEvent& evt);
   void div_button_click(wxCommandEvent& evt);
   void result_button_click(wxCommandEvent& evt);

   DECLARE_EVENT_TABLE();
};