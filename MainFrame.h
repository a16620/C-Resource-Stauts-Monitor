#pragma once
#include "CProcessorDirector.h"

class MainFrame
{
private:
	CProcessorDirector m_director;

public:
	MainFrame();
	~MainFrame();

	bool Initialize();
	void Run(DWORD interval, int exitKey);
	void Release();
};

