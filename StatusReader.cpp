#include "StatusReader.h"
ResourceStatusReader::ResourceStatusReader()
{
}

ResourceStatusReader::~ResourceStatusReader()
{
}

bool ResourceStatusReader::Initialize()
{
	/*if (!m_pdh.Initialize)
	{
		return false;
	}

	return true;*/
	return m_pdh.Initialize();
}

void ResourceStatusReader::Release()
{
	m_pdh.Release();
}

bool ResourceStatusReader::Read(CPStatus* out)
{
	out->dCpuUse = m_pdh.GetCpuUse();
	MEMORYSTATUSEX memst;
	memst.dwLength = sizeof(MEMORYSTATUSEX);
	BOOL res = GlobalMemoryStatusEx(&memst);
	out->dwMemLoad = memst.dwMemoryLoad;
	return (out->dCpuUse != -1) && res;
}
