%{
#include <ctype.h>
#include <stdio.h> 
#include <stdlib.h>
#include <math.h> 
%}

%token digit

%%
S: E { printf("\n\n"); }
;
E: E '+' T { printf("+"); } 
| E '-' T { printf("-"); }
|T ;
T: T '*' F { printf("*"); } 
| T '/' F { printf("/"); }
|F
;
F: F '^' G { printf("^"); }
|G
;
G: '(' E ')'
| digit { printf("%d", $1); } 
;
%%
int main() {
printf("Enter infix expression: ");
yyparse();
}
int yyerror() {
printf("Error");
return 0;
}
