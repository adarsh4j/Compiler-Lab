%{
#include<stdio.h>
#include<ctype.h>
int vow=0, con=0;
%}

%%
[aeiouAEIOU]+ {vow++;}
[bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ] {con++;}
%%

int main( ) {
    FILE *fp;
    fp = fopen("input1.txt", "r");
    if (fp == NULL) {
        printf("File not found");
        return 1;
    }
    char ch;
    while ((ch = fgetc(fp)) != EOF) {
        if (isalpha(ch)) {
            ch = tolower(ch);
            ECHO;
            yylex();
        }
    }
    fclose(fp);
    printf("\nNumber of vowels=%d\n",vow);
    printf("Number of consonants=%d\n",con);
    return 0;
}

int yywrap( ) {
    return 1;
}
