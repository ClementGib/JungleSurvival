#include "C_SECTION_CRITIQUE.h"

// =============================================

C_CRITICAL_SECTION::C_CRITICAL_SECTION()
{
	InitializeCriticalSection(&Verrou);
}

// =============================================

C_CRITICAL_SECTION::~C_CRITICAL_SECTION()
{
	DeleteCriticalSection(&Verrou);
}
