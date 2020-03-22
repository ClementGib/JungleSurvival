#pragma once
#include <Windows.h>

// =============================================

class C_MUTEX
{
public:
	C_MUTEX();
	~C_MUTEX();
	inline DWORD P(DWORD P_TimeOut = INFINITE);
	inline DWORD V();
protected:
	HANDLE H_Mutex;
};

// =============================================

DWORD C_MUTEX::P(DWORD P_TimeOut)
{
	return WaitForSingleObject(H_Mutex, P_TimeOut);
}

// =============================================

DWORD C_MUTEX::V()
{
	return ReleaseMutex(H_Mutex);
}