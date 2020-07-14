#include "MainFrame.h"

BEGIN_EVENT_TABLE(MainFrame, wxFrame)
	EVT_CLOSE(MainFrame::onClose)
	EVT_SLIDER(20001, MainFrame::OnTimeChange)
END_EVENT_TABLE()

MainFrame::MainFrame() 
	: wxFrame(nullptr, wxID_ANY, "Digital photo frame", wxPoint(50,50), wxSize(300,400) )
{
		m_image_panel = new ImagePanel(this, wxT("a.jpg"));
		m_status_bar = this->CreateStatusBar(2, wxSTB_DEFAULT_STYLE, wxID_ANY);
		m_slider = new wxSlider(m_status_bar, 20001, 5, 1, 30);
		m_status_bar->SetStatusText(wxString("Time: ") << m_slider->GetValue() << wxString("s"), 1);
		timer = new Timer(m_image_panel);
		timer->start();
}

MainFrame::~MainFrame()
{
	delete timer;
}

void MainFrame::loadImage(wxString file)
{
	m_image_panel->changeImage(file);
	Update();
	Refresh();
}

void MainFrame::onClose(wxCloseEvent& evt)
{
	timer->Stop();
	evt.Skip();
}

void MainFrame::OnTimeChange(wxCommandEvent &evt)
{
	m_status_bar->SetStatusText(wxString("Time: ") << m_slider->GetValue() << wxString("s"), 1);
	timer->changeInterval(m_slider->GetValue() * 1000);
	timer->start();
	evt.Skip();
}