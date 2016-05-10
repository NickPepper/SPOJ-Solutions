/*
http://www.spoj.pl/problems/DEFKIN/
SPOJ Problem Set (classical)
7804. Defense of a Kingdom
Problem code: DEFKIN
*/

//#include <cstdio> // decomment to compile the program as C++ // g++ factorial.c -time -o factorial_cpp
#include <stdio.h>

//Quicksort w/o a separate compare function :)
void quicksort(int A[], int lo, int hi) {
    int i, j, pivot, temp;
    if(lo == hi) return;
    i = lo;
    j = hi;
    pivot= A[(lo+hi)/2];
    /* Split the array into two parts */
    do {
    	while(A[i] < pivot) i++;
    	while(A[j] > pivot) j--;
    	if(i <= j) {
    		temp= A[i]; // TODO: заменить temp на XOR'ы (?)
    		A[i]= A[j];
    		A[j]=temp;
    		i++;
    		j--;
    	}
    } while (i <= j);
    if(lo < j) quicksort(A, lo, j);
    if(i < hi) quicksort(A, i, hi);
}


int main()
{
	int testcases, width, height, towers, x, y, answer;
	scanf("%d", &testcases);
	while(testcases--) {
		scanf("%d %d %d", &width, &height, &towers);
		switch(towers) {
			case 0:
				answer = width * height;
				printf("%d\n", answer);
				break;
			case 1:
				//printf("There was only ONE tower.\n");
				scanf("%d %d", &x, &y);
				int sx = width - x;
				int sy = height -y;
				int ax = (sx > x) ? sx : --x;
				int ay = (sy > y) ? sy : --y;
				answer = ax * ay;
				printf("%d\n", answer);
				break;
			default:
				{
					int arlen = ++towers;
					int txs[++towers];
					int tys[towers];
					txs[0] = tys[0] = 1;
					txs[arlen] = width;
					tys[arlen] = height;
					int i;
					for(i = 1; i < arlen; i++) {
						scanf("%d %d", &x, &y);
						txs[i] = x;
						tys[i] = y;
					}

					quicksort(txs, 1, arlen-1);
					quicksort(tys, 1, arlen-1);

					int xj;
					for(xj = 0; xj < towers; xj++) {
						printf("txs[%d] = %d\n", xj, txs[xj]);
					}
					printf("\n\n");

					int j, temp, proansX = 0, proansY = 0;
					for(j = 0; j < towers-1; j++) {
						temp = txs[j+1] - txs[j];
						//printf("temp = %d\n", temp);
						if(temp > proansX) {
							proansX = temp;
						}
						temp = tys[j+1] - tys[j];
						if(temp > proansY) {
							proansY = temp;
						}
					}
					printf("biggest difference X = %d\n\n\n", --proansX);

					int yj;
					for(yj = 0; yj < towers; yj++) {
						printf("tys[%d] = %d\n", yj, tys[yj]);
					}
					printf("\n\n");
					printf("biggest difference Y = %d\n\n\n", --proansY);
				}
				break;
		}
	}
	return 0;
}


