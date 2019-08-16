#pragma once
#include <Windows.h>
#include "LowlevelHardwareHManager.h"

struct CPStatus {
	DWORD dwMemLoad;
	DOUBLE dCpuUse;
};

class StatusReader
{
public:
	StatusReader() {};
	virtual ~StatusReader() {};
	virtual bool Initialize() = 0;
	virtual void Release() = 0;
	virtual bool Read(struct CPStatus* out)=0;
};

class ResourceStatusReader : public StatusReader
{
private:
	PDHManager m_pdh;

public:
	ResourceStatusReader();
	~ResourceStatusReader();
	bool Initialize();
	void Release();
	bool Read(struct CPStatus* out);
};