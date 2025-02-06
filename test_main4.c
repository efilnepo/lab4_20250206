#include <stdio.h>
#include <string.h>
#include <ctype.h>

char* removeExtraSpaces(char* str) {
    // Input validation
    if (!str || !(*str)) return NULL;
    
    char* readPtr = str;
    char* writePtr = str;
    int prevWasSpace = 0;
    
    // Skip leading whitespace
    while (*readPtr && isspace(*readPtr)) {
        readPtr++;
    }
    
    // Handle empty string case
    if (*readPtr == '\0') {
        *writePtr = '\0';
        return str;
    }
    
    // Copy first character
    *writePtr++ = *readPtr++;
    
    // Process remaining characters
    while (*readPtr) {
        if (isspace(*readPtr)) {
            if (!prevWasSpace) {
                *writePtr++ = ' ';
                prevWasSpace = 1;
            }
            readPtr++;
        } else {
            *writePtr++ = *readPtr++;
            prevWasSpace = 0;
        }
    }
    
    // Remove trailing space if exists
    if (writePtr > str + 1 && *(writePtr - 1) == ' ') {
        writePtr--;
    }
    
    *writePtr = '\0';
    return str;
}

int main() {
    char text[100];
    
    printf("Enter a string: ");
    fgets(text, sizeof(text), stdin);
    
    // Remove newline character if present
    int len = strlen(text);
    if (len > 0 && text[len-1] == '\n') {
        text[len-1] = '\0';
    }
    
    printf("Original string: '%s'\n", text);
    char* result = removeExtraSpaces(text);
    printf("Modified string: '%s'\n", result);
    
    return 0;
}