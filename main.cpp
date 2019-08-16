#include "MainFrame.h"

int main(void)
{
	MainFrame mainFrame;
	mainFrame.Initialize();

	mainFrame.Run(1000, VK_ESCAPE);

	mainFrame.Release();
}