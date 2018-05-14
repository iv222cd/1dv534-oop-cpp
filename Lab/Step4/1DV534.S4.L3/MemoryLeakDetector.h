#pragma once

#include <crtdbg.h>
#include <windows.h>

class MemoryLeakDetector
{
public:
	MemoryLeakDetector() 
		{ ::OutputDebugString( (LPCWSTR)">>> Memory leak detection enabled <<<\n" ); }
	~MemoryLeakDetector()
		{ if (!_CrtDumpMemoryLeaks()) ::OutputDebugString( (LPCWSTR)">>> No memory leak detected <<<\n" ); }
};

MemoryLeakDetector md;
