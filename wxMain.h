#pragma once

#include "wx/wx.h"
#include "MainFrame.h"
#include "FilesListManagement.h"
#include <string>

class wxMain : public wxApp 
{
public:
	virtual bool OnInit();

private:
	MainFrame* m_main_frame = nullptr;
	int m_picture_change_time;
};

