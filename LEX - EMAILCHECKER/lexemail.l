%{
#include <stdio.h>
int valid = 0;
%}

%%
[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,4}   { valid = 1; }
.|\n    { /* Ignoring other characters */ }
%%

int main() {
    yylex();
    if (valid)
        printf("Valid email\n");
    else
        printf("Invalid email\n");
    return 0;
}

int yywrap() {
    return 1;
}

