#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

     /* Enter your code here. Read input from STDIN. Print output to STDOUT */
     long a[1200],i,j,k,x,rotations,arr[300][300],row,col, circles,y;
     long direction = 0, total =0 ,tr, limit;
     scanf("%d%d%d",&row,&col,&rotations);
     for (i=0 ; i<row ; i++ ) { for (j=0 ; j<col ; j++) { scanf("%d",&arr[i][j]);}}
     circles = row<col ? row : col;
     circles /= 2;
     for (k=0; k<circles ; k++) {
          // Read a circle's elements
          direction = 1;
          //total = (row - 2*k) * (col - 2*k);
          total = 2*(row - 2*k) + 2*(col - 2*k) - 4;
          for (i=k , j=k, x=0 ; i< row-k && j<col-k && x<total && direction != 0;  ) {
               if       (direction == 1) { a[x] = arr[i][j] ; x++; i++; if (i >= (row-k)) { i = row-k-1 ; j++; direction = 2;}
               } else if(direction == 2) { a[x] = arr[i][j] ; x++; j++; if (j >= (col-k)) { j = col-k-1 ; i--; direction = 3;}
               } else if(direction == 3) { a[x] = arr[i][j] ; x++; i--; if (i <  k)       { i = k ;     j--;  direction = 4;}
               } else if(direction == 4) { a[x] = arr[i][j] ; x++; j--; if (j <  k)       { j = k ;       direction = 0;}}
          }
          //printf("\nCircle : %d Total = %d Elements: ",k,total);
          //for (y=0 ; y<total ; y++ ) { printf("%d ",a[y]);}

          tr = rotations % total ;
          direction = 1;
          for (i=k , j=k, x=total-tr, limit = 1 ; i< row-k && j<col-k && limit<=total && direction != 0;  ) {
               x = x%total;
               if       (direction == 1) { arr[i][j] = a[x]; x++; limit++; i++; if (i >= (row-k)) { i = row-k-1 ; j++ ;direction = 2;}
               } else if(direction == 2) { arr[i][j] = a[x]; x++; limit++; j++; if (j >= (col-k)) { j = col-k-1 ; i-- ;direction = 3;}
               } else if(direction == 3) { arr[i][j] = a[x]; x++; limit++; i--; if (i <  k)       { i = k ;   j--;    direction = 4;}
               } else if(direction == 4) { arr[i][j] = a[x]; x++; limit++; j--; if (j <  k)       { j = k ;       direction = 0;}}
          }
     }
     for (i=0 ; i<row ; i++ ) { for (j=0 ; j<col ; j++) { printf("%d ",arr[i][j]);} printf("\n");}
     return 0;
}
