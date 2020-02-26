#include "stdafx.h"
#include "Utility.h"


namespace util
{

    char* util::StringReplace(const char* original, const char* before, const char* after)
    {
        char* result;                  // Fully edited string
        const char* ins;               // The next insert point
        char* tmp;                     // String that is used to insert replacement segments
        size_t lenBefore;              // Length of the string to remove
        size_t lenAfter;               // Length of the string to 'before' with
        size_t count;                  // Number of replacements

        // Sanity checks and initialization
        if (!original || !before)
            return nullptr;
        lenBefore = strnlen(before, MAXIMUM_STRING_BYTE_COUNT);
        if (lenBefore == 0)
            return nullptr; // Empty rep causes infinite loop during count
        if (!after)
            after = (char*)"";
        lenAfter = strnlen(after, MAXIMUM_STRING_BYTE_COUNT);

        // Searching for each starting location of the 'before' segment and counting them
        ins = original /*+ offset*/;

        const char* segmentSearcher = nullptr;
        for (count = 0; segmentSearcher = strstr(ins, before); ++count)
            ins = segmentSearcher + lenBefore;

        long long lenDifference = ((long long)lenAfter) - lenBefore;
        size_t originaOffset = strnlen(original, MAXIMUM_STRING_BYTE_COUNT) + 1;
        size_t tempAllocationSize = originaOffset + 
            (lenDifference < 0) ?
            (originaOffset - -lenDifference * count) :
            (originaOffset + lenDifference * count);

        tmp = result = // Allocating enough memory for replacement(reallocating original risks to lose some end characters)  
            static_cast<char*>(malloc(tempAllocationSize));

        if (!result)
            return nullptr;

        while (count--) {
            size_t lenFromLastSegment;                                              // Distance between 'before' and end of last 'before'
            
            ins = strstr(original, before);                                         // Searching for the next segment
            lenFromLastSegment = ins - original;                 
            tmp = strncpy(tmp, original, lenFromLastSegment) + lenFromLastSegment;  // Copy everything before current segment
            tmp = strncpy(tmp, after, lenAfter) + lenAfter;                                    // Copy 'after' in place, move past replaced part
            original += lenFromLastSegment + lenBefore;                             // Move past replaced part in the original
            originaOffset -= (lenFromLastSegment + lenBefore);
        }
        strncpy(tmp, original, originaOffset);
        return result;
    }

    bool util::StringsEqual(const char* left, const char* right)
    {
        // Same memory address OR ((both left, right != 0) AND Strings are equal)
        return (left == right) || (left && right && (strcmp(left, right) == 0));
    }
}
