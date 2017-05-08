#pragma once

#ifndef LOGGER_H
#define LOGGER_H

#include "StackWalker.h"
#include <fstream>


class Logger : public StackWalker
{

private:
	std::ofstream debugFile;

public:

	Logger(LPCSTR fileName) : StackWalker()
	{
		this->debugFile.open(fileName, std::fstream::out);
	};

	~Logger(void)
	{
		this->debugFile.close();
	}

	void Logger::OnOutput(LPCSTR szText)
	{
		this->debugFile << szText;

		StackWalker::OnOutput(szText);
	}

	LONG WINAPI Logger::ExpFilter(EXCEPTION_POINTERS* pExp, DWORD dwExpCode)
	{
		this->ShowCallstack(GetCurrentThread(), pExp->ContextRecord);
		return EXCEPTION_EXECUTE_HANDLER;
	}


};

#endif