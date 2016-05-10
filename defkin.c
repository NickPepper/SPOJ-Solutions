/*
http://www.spoj.pl/problems/DEFKIN/
SPOJ Problem Set (classical)
7804. Defense of a Kingdom
Problem code: DEFKIN

			FUCK:
6889290 	2012-04-22 18:35:04 	Nick Pepper
Defense of a Kingdom

wrong answer (мой алгоритм работает прекрасно, проверено на ideone.com - а у этих пидаров WRONG ANSWER !)
0.23 	1.9M 	C
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
    		temp= A[i];
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
	char dummy;
	scanf("%d%c", &testcases, &dummy);
	while(testcases--) {
		scanf("%d %d %d%c", &width, &height, &towers, &dummy);
		switch(towers) {
			case 0:
				answer = width * height;
				printf("%d\n", answer);
				break;
			case 1:
				scanf("%d %d%c", &x, &y, &dummy);
				int sx = width - x;
				int sy = height -y;
				int ax = (sx > x) ? sx : (sx == x) ? x : --x;
				int ay = (sy > y) ? sy : (sy == y) ? y : --y;
				answer = ax * ay;
				printf("%d\n", answer);
				break;
			default:
				{
					int arlen = towers+1;
					int txs[towers+2];
					//memset(txs,0,sizeof(txs));
					int tys[towers+2];
					//memset(tys,0,sizeof(tys));
					txs[0] = tys[0] = 1;
					txs[arlen] = width+1;//txs[arlen] = width;
					tys[arlen] = height+1;//tys[arlen] = height;
					int i;
					for(i = 1; i < arlen; i++) {
						scanf("%d %d%c", &x, &y, &dummy);
						txs[i] = x;
						tys[i] = y;
					}

					quicksort(txs, 1, arlen-1);
					quicksort(tys, 1, arlen-1);

					int j, temp = 0, proansX = 0, proansY = 0;
					for(j = 0; j < towers+1; j++) {
						temp = txs[j+1] - txs[j];
						if(temp >= proansX) 
							proansX = temp;//if(temp > proansX) proansX = temp;

						temp = tys[j+1] - tys[j];
						if(temp >= proansY) 
							proansY = temp;//if(temp > proansY) proansY = temp;
					}

					printf("%d\n", (--proansX * --proansY));
				}
				break;
		}
	}
	return 0;
}




/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//БЛЯДЬ!!! ЭТОТ вариант тоже прекрасно работает на ideone.com НО даёт WRONG ANSWER на ведросайте (!!!)

#include<stdio.h>
#include<stdlib.h>
int comp(const void *a,const void *b){
    return(*(int*)a-*(int*)b);
}

int main(){
    int t,i,w,h,n,q,j,temp;
	char dummy;
    int x[40005],y[40005],subt1[40005],subt2[40005];
    scanf("%d%c", &t, &dummy);
    for(i=0;i<t;i++){
        scanf("%d %d %d%c", &w, &h, &n, &dummy);
        if(n!=0){
	        for(q=1;q<=n;q++){
    		    scanf("%d %d%c", &x[q], &y[q], &dummy);
    	    }
    	    x[0]=1;
    	    y[0]=1;
    	    x[n+1]=w+1;
    	    y[n+1]=h+1;
    	    qsort(x,n+1,sizeof(int),comp);
    	    qsort(y,n+1,sizeof(int),comp);
    	    for(j=0;j<n+2;j++){
		        subt1[j]=x[j+1]-x[j]-1;
    		    subt2[j]=y[j+1]-y[j]-1;
    	    }
    	    qsort(subt1,n+2,sizeof(int),comp);
    	    qsort(subt2,n+2,sizeof(int),comp);
    	    temp=subt1[n+1]*subt2[n+1];
    	    printf("%d\n",temp);
        } else if(n==0) {
	        temp=w*h;
    	    printf("%d\n",temp);
	    }
    }
    return 0;
}



/*
Input:
6
15 8 3
3 8
11 2
8 6
100 100 0
100 100 1
5 5
10 10 1
5 5
10 10 1
6 6
10 10 2
1 1
10 10

Output:
12
10000
9025
25
25
64
*/


