#include <stdio.h>

int count(int x){

    return 3-(x%2)/x;// OK
    //return 2 | !(!(x >> 1));
    //return -!(x - 1) + 3; // compilation error

}

int main(){

    for( int i=1 ; i-1001 ; i++ ) printf("%d %d\n",i,count(i));

    return 0;

}

