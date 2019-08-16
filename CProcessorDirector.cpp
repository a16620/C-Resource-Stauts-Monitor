#include "CProcessorDirector.h"

using namespace std;

CProcessorDirector::CProcessorDirector()
{
}


CProcessorDirector::~CProcessorDirector()
{
}

void CProcessorDirector::AddProcessor(std::string name, LogProcessor * pProcessor)
{
	if (processors.find(name) == processors.end())
		return;
	processors[name]->addListener(pProcessor);
}

void CProcessorDirector::SetReader(std::string name, StatusReader * pReader)
{
	if (processors.find(name) == processors.end())
	{
		CProcess* pCP = new CProcess();
		pReader->Initialize();
		pCP->setReader(pReader);
		processors.insert(make_pair(name, pCP));
	}
	else
	{
		processors[name]->setReader(pReader);
	}
}

bool CProcessorDirector::Activate(std::string name)
{
	if (processors.find(name) != processors.end())
	{
		return processors[name]->Process();
	}
	return false;
}

void CProcessorDirector::Release()
{
	for (auto iter = processors.begin(); iter != processors.end(); ++iter)
	{
		iter->second->Release();
		delete (iter->second);
	}
	processors.clear();
}
