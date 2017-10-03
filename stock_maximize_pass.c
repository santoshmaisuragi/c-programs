#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int big_index (long a[], int left, int n) {
     int i , ib = left;
     long big = 0;
     if (left >= n-1) { return left;}
     //if (n==1) {return 0;}
     big = a[ib];
     for (i = left ; i< n ; i++) {
          if (big <= a[i] ) {
               big = a[i];
               ib = i;
          }
     }
     return ib;
}

int reverse_sorted (long a[], int is , int n) {
     int i;
     for (i= is ; i< n-1 ; i++) {
          if (a[i] < a[i+1] ) {
               return 0;
          }
     }
     return 1;
}

long calc_profit (long a[], int i, int j) {
     int x,y,s=0;
     long b = 0;
     for (x = i; x<j ; x++ ) { b+= a[x]; }
     return (long)((a[j]*(j-i))- b);
}

int main() {

     /* Enter your code here. Read input from STDIN. Print output to STDOUT */
     int t,it,jt, n, i,j, ib, left ;
     long big, a[50000],profit;
     scanf("%d",&t);
     for (it = 0 ; it< t ; it++) {
          scanf("%d",&n);
          profit = 0;
          for (i=0 ; i<n ; i++) {a[i] = (long)0;}
          for (i=0 ; i<n ; i++) {scanf("%ld",&a[i]);}
          if (n ==1 || reverse_sorted(a,0,n)) {
               printf ("%ld\n",profit);
               //printf("ssm1 profit %d\n",profit);
          } else {
               left =0;
               ib=0;
               while (left <= ib &&  ib<=n ){
                    ib = big_index (a,left,n);
                    profit += calc_profit(a,left,ib );
                    //printf("ssm2 profit %d left = %d ib = %d big = %d\n",profit,left, ib, a[ib]);
                    left = ib+1;
                    ib = big_index (a,ib+1,n);
                    //printf("ssm3 left = %d ib = %d big = %d\n",left, ib, a[ib]);
                    if ((n-left) == 1 || reverse_sorted(a,left,n)) { break;}
               }
               printf("%ld\n",profit);
          }
     }
     return 0;
}
