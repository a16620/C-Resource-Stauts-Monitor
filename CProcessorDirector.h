#pragma once
#include <list>
#include <string>
#include <map>
#include "StatusReader.h"
#include "LogProcessor.h"

class CProcessorDirector
{
private:
	class CProcess
	{
	private:
		std::list<LogProcessor*> listeners;
		StatusReader* reader = nullptr;
		int datasize = 0;
	public:
		void setReader(StatusReader* pReader, int szData)
		{
			if (reader)
				reader->Release();
			datasize = szData;
			reader = pReader;
			reader->Initialize();
		}
		void addListener(LogProcessor* pListener)
		{
			listeners.push_back(pListener);
		}

		bool Process()
		{
			void* stat = malloc(datasize);
			bool result = reader->Read(stat);
			if (!result)
			{
				free(stat);
				return result;
			}

			for (std::list<LogProcessor*>::iterator iter = listeners.begin(); iter != listeners.end(); ++iter)
			{
				(*iter)->Process(stat);
			}
			free(stat);
			return true;
		}

		void Release()
		{
			if (reader)
				reader->Release();
			for (std::list<LogProcessor*>::iterator iter = listeners.begin(); iter != listeners.end();)
			{
				delete (*iter);
				listeners.erase(iter++);
			}
		}
		CProcess() {}
	};
	std::map<std::string, CProcess*> processors;
public:
	CProcessorDirector();
	~CProcessorDirector();

	void AddProcessor(std::string name, LogProcessor* pProcessor);
	void SetReader(std::string name, StatusReader* pReader, int szData);
	bool Activate(std::string name);
	void Release();
};

