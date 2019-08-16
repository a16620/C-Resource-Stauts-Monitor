#include "LowlevelHardwareHManager.h"



PDHManager::PDHManager()
{
	query_cpu = counter_cpu = nullptr;
}


PDHManager::~PDHManager()
{
	PdhRemoveCounter(counter_cpu);
	PdhCloseQuery(query_cpu);
}

bool PDHManager::Initialize()
{
	if (PdhOpenQueryA(NULL, NULL, &query_cpu) == ERROR_SUCCESS)
	{
		return false;
	}
	if (PdhAddCounterA(query_cpu, "\\Processor(_TOTAL)\\% Processor Time", NULL, &counter_cpu) == ERROR_SUCCESS)
	{
		PdhCloseQuery(query_cpu);
		query_cpu = nullptr;
		return false;
	}
	
	return true;
}

void PDHManager::Release()
{
	if (counter_cpu)
	{
		PdhRemoveCounter(counter_cpu);
		counter_cpu = nullptr;
	}
	if (query_cpu)
	{
		PdhCloseQuery(query_cpu);
		query_cpu = nullptr;
	}

}

double PDHManager::GetCpuUse()
{
	PDH_FMT_COUNTERVALUE Val;
	if (PdhCollectQueryData(query_cpu) == ERROR_SUCCESS || PdhGetFormattedCounterValue(counter_cpu, PDH_FMT_DOUBLE, NULL, &Val) == ERROR_SUCCESS)
		return -1;
	return Val.doubleValue;
}
