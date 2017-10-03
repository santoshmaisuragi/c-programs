//Generate Parentheses
//https://leetcode.com/problems/generate-parentheses/description/
//Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
//input give the total length of the string , which is always an even number
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int n = 0;
int solutions = 0;

int par(char* a, int count , int pm) {
     int i = 0;

     if(count>1) {
          if (pm < n/2 && pm >=0) {
               char *a1 = (char *) malloc ((strlen(a)+2) * sizeof(char));
               a1[0]='\0';
               strcat(a1,a);
               strcat(a1,"(");
               par(a1,count-1,pm+1);

               if((pm) > 0  ) {
                    char *a2 = (char *) malloc ((strlen(a)+2) * sizeof(char));
                    a2[0]='\0';
                    strcat(a2,a);
                    strcat(a2,")");
                    par(a2,count-1,pm-1);
               }

          } else if (pm == n/2) {
               char *a3 = (char *) malloc ((strlen(a)+2) * sizeof(char));
               a3[0]='\0';
               strcat(a3,a);
               strcat(a3,")");
               par(a3,count-1,pm-1);
          }
     }
     if(count ==1 && pm==1) {
          printf("\n%s%c ",a,')');
          solutions++;
     }
     return 0;
}

int main() {
     //char a[10000];
     scanf("%d",&n);
     //a[0]='\0';
     par("",n,0);
     printf ("\nTotal solutions = %d\n",solutions);
     return 0;
}
