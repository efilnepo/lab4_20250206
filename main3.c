#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
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
    char* input_line;
    char* result;
    printf("Enter lines (Ctrl+D to finish):\n");
    
    // Read lines until EOF
    while ((input_line = readline("")) != NULL) {
        if (*input_line) {  // Check if line is not empty

            // Remove newline character if present
            int len = strlen(input_line);
            if (len > 0 && input_line[len-1] == '\n') {
                input_line[len-1] = '\0';
            }
            printf("Original string: '%s'\n", input_line);
            result = removeExtraSpaces(input_line);
            printf("Modified string: '%s'\n", result);

            // clean_line(input_line);
            
            // // Print cleaned line
            // printf("Cleaned line: %s\n", input_line);
            
            // Add to history
            // add_history(input_line);
        }
        
        // Free the allocated memory
        free(input_line);
        // free(result);
    }
    
    return 0;
}