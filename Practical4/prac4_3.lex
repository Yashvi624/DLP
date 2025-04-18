%{
#include <stdio.h>
int char_count = 0, word_count = 0, line_count = 0;
%}

%%
\n         { line_count++; char_count++; }  // Count newline as character and line
[^\n\t ]+  { word_count++; char_count += yyleng; }  // Count words and characters
.          { char_count++; }  // Count remaining characters including spaces
%%

int main() {
    FILE *file = fopen("input.txt", "r");
    if (!file) {
        printf("Error opening file.\n");
        return 1;
    }
    yyin = file;
    yylex();
    fclose(file);

    printf("Characters : %d\n", char_count);
    printf("Words : %d\n", word_count);
    printf("Lines : %d\n", line_count);
    return 0;
}

int yywrap() { return 1; }
