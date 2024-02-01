%{
#include<stdio.h>
int cnt=0;
%}
letter [a-zA-Z]
digit [0-9]
punc [!|,|.]
oper [+|*|-|/|%]
boole [true|false]
%%
{digit}+|{digit}*.{digit}+ {printf("Constants");} int|float {printf("Keyword");} {letter}({digit}|{letter})* {printf("Identifiers");} {oper} {printf("Operator");}
{punc} {printf("Punctuator");}
%%
int yywrap()
{
return 1;
}
int main()
{
yylex();
return 0;
}
