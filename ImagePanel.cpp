#include "ImagePanel.h"

BEGIN_EVENT_TABLE(ImagePanel, wxPanel)
	EVT_PAINT(ImagePanel::paintEvent)
	EVT_SIZE(ImagePanel::OnSize)
END_EVENT_TABLE()

ImagePanel::ImagePanel(wxFrame* parent, wxString file) :
	wxPanel(parent)
{
	m_parent = parent;
	changeImage(file);
}

void ImagePanel::paintEvent(wxPaintEvent & evt)
{
	wxPaintDC dc(this);
	render(dc);
}

void ImagePanel::OnSize(wxSizeEvent& event) {
	Refresh();
	event.Skip();
}

void ImagePanel::render(wxDC&  dc)
{
	int newW, newH;
	dc.GetSize(&newW, &newH);
	float scale;

	if ( ((float)newW / (float)newH) >= ((float)m_image.GetWidth() / (float)m_image.GetHeight()) )
	{
		scale = (float)newH / (float)m_image.GetHeight();
		resized = wxBitmap(m_image.Scale(m_image.GetWidth()*scale, 
							newH, 
							wxIMAGE_QUALITY_HIGH));
		dc.DrawBitmap(resized, (newW - m_image.GetWidth()*scale)/2, 0, false);
	}
	else
	{
		scale = (float)newW / (float)m_image.GetWidth();
		resized = wxBitmap(m_image.Scale(newW, 
							m_image.GetHeight()*scale,
							wxIMAGE_QUALITY_HIGH));
		dc.DrawBitmap(resized, 0, (newH-m_image.GetHeight()*scale)/2, false);
	}
}

void ImagePanel::changeImage(wxString file)
{
	m_image.LoadFile(file, wxBITMAP_TYPE_JPEG);
}

void ImagePanel::paintNow()
{
	wxClientDC dc(this);
	render(dc);
}