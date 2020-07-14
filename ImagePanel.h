#pragma once

#include "wx/wx.h"
#include "wx/sizer.h"

class ImagePanel : public wxPanel
{
	wxImage m_image;
	wxBitmap resized;
	wxFrame* m_parent;

public:
	ImagePanel(wxFrame* parent, wxString file);

	void paintEvent(wxPaintEvent & evt);
	void OnSize(wxSizeEvent& event);

	void render(wxDC& dc);

	void changeImage(wxString file);
	void paintNow();

	DECLARE_EVENT_TABLE()
};

