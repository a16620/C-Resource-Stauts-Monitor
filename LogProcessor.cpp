#include "LogProcessor.h"
#include <stdio.h>
//#include <WinSock2.h>
//#pragma comment(lib, "ws32.lib")
LogSender::LogSender()
{
}

LogSender::~LogSender()
{
	//closesocket(s);
}

void LogSender::Initialize(const char * ip)
{
	/*s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	sockaddr_in addr;
	addr.sin_addr.s_addr = inet_addr(ip);
	addr.sin_family = AF_INET;
	addr.sin_port = htons(4750);
	connect(s, (sockaddr*)&addr, sizeof(addr));*/
}

BOOL LogSender::Process(LPCVOID in)
{
	printf("Count #%d  %f  %d\n", cnt++, ((CPStatus*)in)->dCpuUse, ((CPStatus*)in)->dwMemLoad);
	return TRUE;
}
