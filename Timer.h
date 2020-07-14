#pragma once
#include <wx/timer.h>
#include "ImagePanel.h"
#include "FilesListManagement.h"

class Timer : public wxTimer
{
	ImagePanel* panel;
public:
	Timer(ImagePanel* panel);
	void Notify();
	void start();
	~Timer();
	int timeInMiliSecounds;
	void changeInterval(int newInterval);
private:
	FilesListManagement* file_list_menager = nullptr;
};

