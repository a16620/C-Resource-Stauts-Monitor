#pragma once
#include "StatusReader.h"

class LogProcessor
{
public:
	LogProcessor() {};
	virtual ~LogProcessor() {};

	virtual BOOL Process(const CPStatus&)=0;
};

class LogSender : public LogProcessor
{
private:
	//SOCKET s;
	int cnt = 0;

public:
	LogSender();
	~LogSender();
	void Initialize(const char* ip);
	BOOL Process(const CPStatus& out);
};