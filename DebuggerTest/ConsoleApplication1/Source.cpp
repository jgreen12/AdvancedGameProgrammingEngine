/**********************************************************************
*
* StackWalker.cpp
*
*
* History:
*  2005-07-27   v1    - First public release on http://www.codeproject.com/
*  (for additional changes see History in 'StackWalker.cpp'!
*
**********************************************************************/
#include <windows.h>
#include <tchar.h>
#include <stdio.h>
#include <fstream>

#if _MSC_VER >= 1300
#include <Tlhelp32.h>
#endif

#include "StackWalker.h"

#include "Logger.h"

std::ofstream outputFile;


// Test for callstack of the current thread:
void Func5() { Logger sw("bitchass.txt"); sw.ShowCallstack(); }
void Func4() { Func5(); }
void Func3() { Func4(); }
void Func2() { Func3(); }
void TestCurrentThread() { Func2(); }


// Test for callstack of an other thread:
void TFunc5() { Sleep(10000); }
void TFunc4() { TFunc5(); }
void TFunc3() { TFunc4(); }
void TFunc2() { TFunc3(); }
DWORD WINAPI LocalThread(LPVOID) { TFunc2(); return 0; }
void TestDifferentThread()
{
	DWORD dwThreadId;
	HANDLE hThread = CreateThread(NULL, 0, LocalThread, NULL, 0, &dwThreadId);
	Sleep(100);  // just be "sure" that the other thread is really running...
	Logger logger("nigga.txt");
	//MyStackWalker sw;
	//sw.ShowCallstack(hThread);
	logger.ShowCallstack(hThread);
	CloseHandle(hThread);
}

#if _MSC_VER >= 1300
// Test for callstack of threads for an other process:
void TestDifferentProcess(DWORD dwProcessId)
{
	HANDLE hProcess = OpenProcess(
		PROCESS_QUERY_INFORMATION | PROCESS_VM_READ,
		FALSE, dwProcessId);

	if (hProcess == NULL)
		return;

	HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPALL, dwProcessId);
	if (hSnap == INVALID_HANDLE_VALUE)
		return;

	THREADENTRY32 te;
	memset(&te, 0, sizeof(te));
	te.dwSize = sizeof(te);
	if (Thread32First(hSnap, &te) == FALSE)
	{
		CloseHandle(hSnap);
		return;
	}

	// Initialize StackWalker...
	//MyStackWalker sw(dwProcessId, hProcess);
	//sw.LoadModules();
	// now enum all thread for this processId
	do
	{
		if (te.th32OwnerProcessID != dwProcessId)
			continue;
		HANDLE hThread = OpenThread(THREAD_ALL_ACCESS, FALSE, te.th32ThreadID);
		if (hThread == NULL)
			continue;
		char szTemp[100];
		//sprintf(szTemp, "\r\nThreadID: %d\r\n", te.th32ThreadID);
		//sw.OnOutput(szTemp);  // output the threadId
		//sw.ShowCallstack(hThread);
		CloseHandle(hThread);
	} while (Thread32Next(hSnap, &te) != FALSE);
}
#endif  // _MSC_VER >= 1300


// Exception handling and stack-walking example:
LONG WINAPI ExpFilter(EXCEPTION_POINTERS* pExp, DWORD dwExpCode)
{
	Logger sw("weee.txt");
	sw.ShowCallstack(GetCurrentThread(), pExp->ContextRecord);
	return EXCEPTION_EXECUTE_HANDLER;
}
void ExpTest5() { char *p = NULL; p[0] = 0; }
void ExpTest4() { ExpTest5(); }
void ExpTest3() { ExpTest4(); }
void ExpTest2() { ExpTest3(); }
void ExpTest1() { ExpTest2(); }
void TestExceptionWalking()
{
	__try
	{
		ExpTest1();
	}
	__except (ExpFilter(GetExceptionInformation(), GetExceptionCode()))
	{
	}
}

//BOOL SetHook(__in BOOL bState, __inout PVOID* ppPointer, __in PVOID pDetour)
//{
//	if (DetourTransactionBegin() == NO_ERROR)
//		if (DetourUpdateThread(GetCurrentThread()) == NO_ERROR)
//			if ((bState ? DetourAttach : DetourDetach)(ppPointer, pDetour) == NO_ERROR)
//				if (DetourTransactionCommit() == NO_ERROR)
//					return TRUE;
//	return FALSE;
//}
//
//#define InstallHook(x, y) SetHook(TRUE, x, y)  
//
//		VOID(WINAPI * _OutputDebugStringW)(__in_z_opt LPCWSTR lpcszString) = OutputDebugStringW;
//
//		VOID(WINAPI * _OutputDebugStringA)(__in_z_opt LPCSTR lpcszString) = OutputDebugStringA;
//
//		VOID WINAPI OutputDebugStringHookA(__in_z_opt LPCSTR lpcszString)
//		{
//			printf("Hook: %s\n", lpcszString);
//
//			//char* ayyy;
//
//			//wcstombs(ayyy, lpcszString, sizeof(lpcszString));
//
//			outputFile << lpcszString;
//			
//			outputFile.write(lpcszString, sizeof(lpcszString));
//
//			_OutputDebugStringA(lpcszString);
//		}
//
//		VOID WINAPI OutputDebugStringHookW(__in_z_opt LPCWSTR lpcszString)
//		{
//			// do something with the string, like write to file
//			printf("if somehow you knew that\n");
//
//			char* ayyy;
//
//			wcstombs(ayyy, lpcszString, sizeof(lpcszString));
//
//			outputFile.write(ayyy, sizeof(ayyy));
//
//			_OutputDebugStringW(lpcszString);
//		}


int _tmain()
{
	outputFile.open("PlsWork.txt", std::fstream::out);

	//InstallHook((PVOID*)&_OutputDebugStringW, OutputDebugStringHookW);
	///InstallHook((PVOID*)&_OutputDebugStringA, OutputDebugStringHookA);

	// 1. Test with callstack for current thread
	TestCurrentThread();

	// 2. Test with different thread in the same process
	//TestDifferentThread();

#if _MSC_VER >= 1300
	// 3. Test with different process
	//TestDifferentProcess(800);  // adjust the ProcessID!
#endif

	// 4. Test of walking the callstack inside an exception
	TestExceptionWalking();

	outputFile.close();

	return 0;
}
