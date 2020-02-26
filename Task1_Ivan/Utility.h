#include "stdafx.h"
#pragma once
#include <stdlib.h>
#include <string.h>

namespace util
{
    constexpr size_t MAXIMUM_STRING_BYTE_COUNT = 1024; 
    /* Replaces every occurence of the 'before' with 'after' */
    char* StringReplace(const char* original, const char* before, const char* after/*, size_t offset = 0*/);
    /* Checks strings for equality of memory address or value. NULL is a valid argument */
    bool StringsEqual(const char* left, const char* right); 

    //inline void HandleOutOfMemory(void* memoryLocation)
    //inline void DummyCrashOnOutOfMemory()
}