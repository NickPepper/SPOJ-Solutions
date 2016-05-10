/*
http://www.spoj.pl/problems/FCTRL/
SPOJ Problem Set (classical)
11. Factorial
Problem code: FCTRL
*/

//#include <cstdio> // decomment to compile the program as C++ // g++ factorial.c -time -o factorial_cpp
#include <stdio.h>
/*
// this variant of zeta works only in C99
// (‘for’ loop initial declarations are only allowed in C99 mode)
// to compile use: gcc factorial.c -std=c99 -time -o factorial_c99
int zeta(int n) 
{
	int ret = 0;
	for(int p = 5; p <= n; p*=5)
		ret += n/p;
	return ret;
}
*/

// this variant of zeta works in traditional C
// to compile use: gcc factorial.c -time -o factorial_c
int zeta(int n) 
{
	int p;
	int ret = 0;
	for(p = 5; p <= n; p*=5)
		ret += n/p;
	return ret;
}


int main()
{
	int t, n;
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		printf("%d\n", zeta(n));
	}
	return 0;
}

