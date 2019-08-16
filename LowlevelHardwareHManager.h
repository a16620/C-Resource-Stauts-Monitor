#pragma once
#include <Pdh.h>
#pragma comment(lib, "pdh.lib")

class PDHManager
{
private:
	PDH_HQUERY query_cpu;
	PDH_HCOUNTER counter_cpu;
public:
	PDHManager();
	~PDHManager();
	bool Initialize();
	void Release();
	double GetCpuUse();
};

