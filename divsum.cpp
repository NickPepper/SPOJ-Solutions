/*
http://www.spoj.pl/problems/DIVSUM/
SPOJ Problem Set (classical)
74. Divisor Summation
Problem code: DIVSUM
Here is a C/C++ solution taken from http://comments.gmane.org/gmane.comp.programming.algogeeks/23111
*/
#include <stdio.h>// gcc divsum.cpp -time -o divsum_c
//#include <cstdio>// g++ divsum.cpp -time -o divsum_cpp
#include <math.h>
int main() {
    long long int n,i,t,d,k,l;
    scanf("%lld",&t);
    while(t--) {
        d = 0;
        scanf("%lld",&n);
        k = sqrt(n);
        for(i = 1; i <= k; i++) {
            if((n%i) == 0) {
                d = d+i;
                l = n/i;
                if(i != l)
                    d = d+l;
            }
        }
        printf("%lld\n",d-n);
    }
    return 0;
}
