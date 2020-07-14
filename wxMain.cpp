#include "wxMain.h"
#include <chrono>
#include <thread>

wxIMPLEMENT_APP(wxMain);

bool wxMain::OnInit()
{
	wxInitAllImageHandlers();
	m_main_frame = new MainFrame();

	m_main_frame->Show();

	return true;
}