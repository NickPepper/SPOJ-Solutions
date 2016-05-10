/*
http://www.spoj.pl/problems/ADDREV/
SPOJ Problem Set (classical)
42. Adding Reversed Numbers
Problem code: ADDREV

gcc addrev.c -time -o addrev_c

see also: 
http://www.algorithmist.com/index.php/SPOJ_ADDREV
*/

//#include <cstdio> // decomment to compile the program as C++ // g++ addrev.c -time -o addrev_cpp
#include <stdio.h>

int rev(int num) {
   int res = 0;
   while(num > 0) {
       res = res*10 + num%10;
       num /= 10;
   }
   return res;
}

int main() {
   int cases, x, y;
   scanf("%d", &cases);
   while(cases--) {
       scanf("%d %d", &x, &y);
       printf("%d\n", rev(rev(x)+rev(y)));
   }
   return 0;
}

/*
Sample input:
4
24 1
4358 754
305 794
00012 21000

Sample output:
34
1998
1
33
*/

