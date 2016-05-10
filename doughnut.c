
//#include <cstdio> is a C++ convention.
//If you replace it with:
//#include <stdio.h> it will compile in C. 

#include <stdio.h>

int main()
{
	int t, c, k, w;

	scanf("%d", &t);
	while(t--) {
		scanf("%d %d %d", &c, &k, &w);
		if(c*w <= k) 	printf("yes\n");
		else 					printf("no\n");
	}

	return 0;
}

