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

bool ResourceStatusReader::Read(LPVOID out)
{
	((CPStatus*)out)->dCpuUse = m_pdh.GetCpuUse();
	MEMORYSTATUSEX memst;
	memst.dwLength = sizeof(MEMORYSTATUSEX);
	BOOL res = GlobalMemoryStatusEx(&memst);
	((CPStatus*)out)->dwMemLoad = memst.dwMemoryLoad;
	return (((CPStatus*)out)->dCpuUse != -1) && res;
}
