%{
#include<stdio.h>
#include<math.h>
#include<string.h>
%}

%%

[0-9]*00 { c1++; printf("%s -> string ending in 00\n",yytext);}

[0-9]*222[0-9]* { c2++; printf("%s -> string with three consecutive 222’s \n",yytext);}

[0-9]*1[0-9]{9} {
c5++; printf("%s -> string such that the 10th symbol from the right end is 1 \n",yytext); }

[1-9]+ {
    if (yyleng == 4){
        int sum = 0, j;
        for(j=0;j<4;j++){
            sum += yytext[j] - '0';
        }
        if(sum == 9){
            printf("%s sum upto 9", yytext);
        }
        
        int k, asc = 1;
        for(k=0;k<3;k++){
            if(yytext[k] > yytext[k+1]){
                asc = 0;
                break;
            }
        }
        if (asc){
            printf("\n%s is in asc", yytext);
        }
    }
}

1[0|1]* {
    int value = 0, i;
    int power = 0;
        
        for (i = strlen(yytext) - 1; i >= 0; i--) {
            if (yytext[i] != '0' && yytext[i] != '1') {
                value = -1;
            }
            int digit = yytext[i] - '0';
            value += digit * (1 << power);
            power++;
        }
    if (value % 5 == 0) {
        printf("Valid binary string: %s (decimal %d mod 5 = 0)\n", yytext, value);
    }
}

%%

int yywrap()
{
    return 1;
}
int main() {
    printf("Enter text\n");
    yylex();
    return 0;
}
