#include "Utility.h"

namespace util
{

    char* util::StringReplace(char* original, char* before, char* after)
    {
        char* result;               // The return string
        char* ins;                  // The next insert point
        char* tmp;                  // Allocated edited string
        int lenBefore;              // Length of the string to remove
        int lenAfter;               // Length of the string to 'before' with
        int lenFromLastSegment;     // Distance between 'before' and end of last 'before'
        int count;                  // Number of replacements

        // Sanity checks and initialization
        if (!original || !before)
            return nullptr;
        lenBefore = strlen(before);
        if (lenBefore == 0)
            return nullptr; // Empty rep causes infinite loop during count
        if (!after)
            after = const_cast<char*>("");
        lenAfter = strlen(after);

        // Searching for each starting location of the 'before' segment and counting them
        ins = original /*+ offset*/;
        for (count = 0; tmp = strstr(ins, before); ++count)  
            ins = tmp + lenBefore;  

        tmp = result = // Allocating enough memory for replacement(reallocating original risks to lose some end characters)  
            static_cast<char*>(malloc(strlen(original) + (lenAfter - lenBefore) * count + 1));

        if (!result)
            return nullptr;

        while (count--) {
            ins = strstr(original, before);                                         // Searching for the next segment
            lenFromLastSegment = ins - original;                 
            tmp = strncpy(tmp, original, lenFromLastSegment) + lenFromLastSegment;  // Copy everything before current segment
            tmp = strcpy(tmp, after) + lenAfter;                                    // Copy 'after' in place, move past replaced part
            original += lenFromLastSegment + lenBefore;                             // Move past replaced part in the original
        }
        strcpy(tmp, original);                                                      
        return result;
    }

    bool util::StringsEqual(const char* left, const char* right)
    {
        // Same memory address OR ((both left, right != 0) AND Strings are equal)
        return (left == right) || (left && right && (strcmp(left, right) == 0));
    }
}
