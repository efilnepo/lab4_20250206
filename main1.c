#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>

#define BUFFER_SIZE 1024

// Function to remove extra whitespace and tabs from a string
void clean_line(char* str) {
    int len = strlen(str);
    
    // Find first non-whitespace character
    int start = 0;
    while (start < len && (str[start] == ' ' || str[start] == '\t')) {
        start++;
    }
    
    // Find last non-whitespace character
    int end = len - 1;
    while (end > 0 && (str[end] == ' ' || str[end] == '\t' || str[end] == '\n')) {
        end--;
    }
    
    // Shift string left to remove leading whitespace
    memmove(str, str + start, end - start + 1);
    
    // Null terminate the string
    str[end - start + 1] = '\0';
}

int main() {
    char* input_line;
    
    printf("Enter lines (Ctrl+D to finish):\n");
    
    // Read lines until EOF
    while ((input_line = readline("")) != NULL) {
        if (*input_line) {  // Check if line is not empty
            clean_line(input_line);
            
            // Print cleaned line
            printf("Cleaned line: %s\n", input_line);
            
            // Add to history
            add_history(input_line);
        }
        
        // Free the allocated memory
        free(input_line);
    }
    
    return 0;
}