#include "App.h"
#include "MainWindow.h"

IMPLEMENT_APP(App);

App::App()
{
}

App::~App()
{
}

bool App::OnInit()
{
	if (!wxApp::OnInit()) {
		return false;
	}
	
	MainWindow* main_window = new MainWindow(
		nullptr, 
		wxID_ANY, 
		"Complex Numbers Calculator", 
		wxPoint(30,30), 
		wxSize(610, 400)
	);

	main_window->Show();

	return true;
}
