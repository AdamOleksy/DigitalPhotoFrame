#pragma once

#include "wx/wx.h"
#include "ImagePanel.h"
#include "Timer.h"
#include "FilesListManagement.h"

class MainFrame : public wxFrame
{
public:
	MainFrame();
	~MainFrame();
	void loadImage(wxString file);
	Timer* timer = nullptr;
	void onClose(wxCloseEvent& evt);

	DECLARE_EVENT_TABLE()

private:
	ImagePanel* m_image_panel = nullptr;
	wxStatusBar *m_status_bar = nullptr;
	wxSlider *m_slider = nullptr;

	void OnTimeChange(wxCommandEvent &evt);
	
};

