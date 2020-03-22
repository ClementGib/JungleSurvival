#pragma once
#include <iostream>
#include <Windows.h>
#include <conio.h>

// =============================================

class C_CRITICAL_SECTION
{
public:
	C_CRITICAL_SECTION();
	~C_CRITICAL_SECTION();
protected:
	inline void P();
	inline void V();
	CRITICAL_SECTION Verrou;
};

// =============================================

void C_CRITICAL_SECTION::P()
{
	EnterCriticalSection(&Verrou);
}

// =============================================

void C_CRITICAL_SECTION::V()
{
	LeaveCriticalSection(&Verrou);
}
