#pragma once
#include <stdlib.h>
#include <string.h>

namespace util
{
    /* Calls realloc on pointer with specified new size, returns result of realloc */
    template<typename T>
    inline T* reallocate_memory(T** ptrRef, size_t newSize)
    {
        T* resized = static_cast<T*>(realloc(*ptrRef, sizeof(T) * newSize));
        return resized;
    }
    /* Returns pointer from malloc call, gets amount of bytes for latter through sizeof(T) * size */
    template<typename T>
    inline T* allocate_memory(size_t size)
    {
        return static_cast<T*>(malloc(sizeof(T) * size));
    }
    /* Calls free on pointer and assigns nullptr to it */
    template <typename T>
    inline void free_memory(T** ptrRef)
    {
        free(*ptrRef);
        (*ptrRef) = nullptr;
    }
   
    /* Replaces every occurence of the 'before' with 'after' */
    char* StringReplace(char* original, char* before, char* after/*, size_t offset = 0*/);
    /* Checks strings for equality of memory address or value. NULL is a valid argument */
    bool StringsEqual(const char* left, const char* right); 

    //inline void HandleOutOfMemory(void* memoryLocation)
    //inline void DummyCrashOnOutOfMemory()
}