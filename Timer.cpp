#include "Timer.h"

Timer::Timer(ImagePanel* panel) : wxTimer()
{
	Timer::panel = panel;
	file_list_menager = new FilesListManagement("Pictures");
	timeInMiliSecounds = 5000;
}

void Timer::Notify()
{
	panel->changeImage(file_list_menager->GiveRandomName());
	panel->Refresh();
	wxTimer::Start(timeInMiliSecounds);
}

void Timer::start()
{
	wxTimer::Start(timeInMiliSecounds);
}

Timer::~Timer()
{
	delete file_list_menager;
}

void Timer::changeInterval(int newInterval)
{
	timeInMiliSecounds = newInterval;
}