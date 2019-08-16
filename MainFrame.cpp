#include "MainFrame.h"



MainFrame::MainFrame()
{
}


MainFrame::~MainFrame()
{
}

bool MainFrame::Initialize()
{
	m_director.SetReader("RS_1", new ResourceStatusReader());
	LogSender* sender = new LogSender();
	sender->Initialize("localhost");
	m_director.AddProcessor("RS_1", sender);

	return true;
}

void MainFrame::Run(DWORD interval, int exitKey)
{
	while (TRUE)
	{
		if (GetAsyncKeyState(exitKey))
			break;
		m_director.Activate("RS_1");
		Sleep(interval);
	}
}

void MainFrame::Release()
{
	m_director.Release();
}
