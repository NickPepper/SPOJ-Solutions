#include <stdio.h>

int count(int x) {

    //return 2 | !(!((x & 2) | (x & 4) | (x & 8) | (x & 16) | (x & 32) | (x & 64) | (x & 128) | (x & 256) | (x & 512) | (x & 1024) | (x & 2048) | (x & 4096)  ));
    //return 2 | !(!(x & 1073741822));
    //return 2 | !(!(x & 65534));
    //return 2 | !(!(x & 32766));
    //return 2 | !(!(x & 16382));
    //return 2 | !(!(x & 8190));
    //return 2 | !(!(x & 4094));
    return 2 | !(!(x >> 1)); // это самый красивый вариант, пусть SPOJ идет нахер!
}

int main(){for(int i=1;i^10001;i++)printf("%d %d\n",i,count(i));return 0;}
