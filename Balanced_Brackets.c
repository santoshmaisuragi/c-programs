// Solution for : https://www.hackerrank.com/challenges/ctci-balanced-brackets/problem
// Given strings of brackets, determine whether each sequence of brackets is balanced. If a string is balanced, print YES on a new line; otherwise, print NO on a new line.
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int g = 0;
int z = -1;
int flag = 0;
int push (char* a, char x) {
     if (z+1 > g) {return -1;}
     a[++z] = x;
     /*a[z]='\0';*/
     return 0;
}

char pop (char* a){
     if (z<0) { return '\0';}
     return (char)a[z--];
}

bool is_balanced(char exp[]) {
     char a[512000], t= '\0';
     int i=0, n=0, len=0;
     len = strlen(exp);
     z = -1;
     flag = 0;
     g = len;
     for (i=0; i<len ; i++) {
          if (exp[i]=='(' || exp[i]=='[' || exp[i]=='{') {
                    push(a,exp[i]);
                    //printf("\nPush : %c",exp[i]);
               } else if (exp[i]==')' || exp[i]==']' || exp[i]=='}') {
               t = pop(a);
               //printf("\nPop  : %c Vs %c",t,exp[i]);
               if (  (exp[i]==']' && t!= '[') || (exp[i]==')' && t!= '(') || (exp[i]=='}' && t!= '{')) {
                    //printf ("\n Return 1 : non matching");
                    return (bool)0;
               }
          }
     }
     if (z>=0) {
        //printf ("\n Return 2  : non zero stack");
        return (bool)0;
     }
     return (bool)1;
}

int main(){
     int t, a0;
     scanf("%d",&t);
     for( a0 = 0; a0 < t; a0++){
          char* expression = (char *)malloc(512000 * sizeof(char));
          scanf("%s",expression);
          bool answer = is_balanced(expression);
          if(answer)
          printf("YES\n");
          else
          printf("NO\n");
     }
     return 0;
}
