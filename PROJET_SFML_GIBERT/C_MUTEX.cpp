#include "C_MUTEX.h"

// =============================================

C_MUTEX::C_MUTEX()
{
	H_Mutex = CreateMutexA(NULL, false, NULL);
}

// =============================================

C_MUTEX::~C_MUTEX()
{
	CloseHandle(H_Mutex);
}