%{
#include <stdio.h>
#include <string.h>

int valid = 1; // Flag to track validity
char user_input[100]; // Store input string
int pos = 0;

void validate();
%}

%%

i      { user_input[pos++] = 'i'; }
b      { user_input[pos++] = 'b'; }
t      { user_input[pos++] = 't'; }
a      { user_input[pos++] = 'a'; }
e      { user_input[pos++] = 'e'; }
\n     { user_input[pos] = '\0'; validate(); pos = 0; }
.      { valid = 0; } // Invalid character

%%

void validate() {
    // Implement manual validation of the grammar S → i E t S S' | a
    int len = strlen(user_input);

    if (strcmp(user_input, "a") == 0) {
        printf("Valid string\n");
        return;
    }

    if (len >= 4 && user_input[0] == 'i' && user_input[1] == 'b' && user_input[2] == 't') {
        int i = 3; // Start checking for S and S'
        while (i < len) {
            if (user_input[i] == 'a' || (user_input[i] == 'i' && i + 2 < len && user_input[i+1] == 'b' && user_input[i+2] == 't')) {
                i++; // Move forward if valid
            } else if (user_input[i] == 'e' && (i + 1 < len && (user_input[i+1] == 'a' || user_input[i+1] == 'i'))) {
                i++; // Handling S'
            } else {
                printf("Invalid string\n");
                return;
            }
        }
        printf("Valid string\n");
    } else {
        printf("Invalid string\n");
    }
}

int main() {
    printf("Enter a string to validate:\n");
    yylex();
    return 0;
}

int yywrap() {
    return 1;
}
