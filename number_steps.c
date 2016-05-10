/*
www.spoj.pl/problems/NSTEPS/
SPOJ Problem Set (classical)
1112. Number Steps
Problem code: NSTEPS

			TODO: do it in NASM (!)
*/

// gcc number_steps.c -time -o number_steps_c
// gcc number_steps.c -std=c99 -time -o number_steps_c99

//#include <cstdio> // decomment to compile the program as C++ // g++ number_steps.c -time -o number_steps_cpp
#include <stdio.h>

int main() {
	int t,a,b;
	scanf("%d ",&t);
  	while(t--) {
    	scanf("%d %d", &a, &b);
    	if(a!=b && a-b!=2) {printf("No Number\n");continue;}
    	if(a%2==0 && b%2==0) printf("%d\n", a+b);
    	else printf("%d\n", a+b-1);
  }
  return 0;
}
