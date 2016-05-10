/*
http://www.spoj.pl/problems/TOANDFRO/
SPOJ Problem Set (classical)
400. To and Fro
Problem code: TOANDFRO

			IT DOES NOT WORK (!)
toandfro.cpp: In function ‘int main()’:
toandfro.cpp:59: error: ‘i’ was not declared in this scope
toandfro.cpp:59: error: ‘sz’ was not declared in this scope
toandfro.cpp:59: error: ‘rep’ was not declared in this scope
toandfro.cpp:59: error: expected ‘;’ before ‘{’ token
toandfro.cpp:77: error: expected ‘}’ at end of input
toandfro.cpp:77: error: expected ‘}’ at end of input
# cc1plus 0.27 0.02
*/
// to compile the program:  g++ toandfro.cpp -time -o toandfro_cpp

#include <iostream>
#include <string>
#include <deque>
#include <set>
#include <map>
#include <list>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <bitset>
#include <algorithm>
#include <sstream>
#include <cstring>
using namespace std;

/*
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
*/

int main()
{
	int cl;
	scanf("%d", &cl);//cin >> cl;
  	while(cl) {
    	string s,t,temp;
    	cin >> s;
    	int k=0;
    	rep(i,0,sz(s)/cl) {
      		rep(j,0,cl) {
			temp += s[k++];
      		}
      		if(i%2)
			reverse(all(temp));
      		t += temp;
      		temp.clear();
    	}
    	rep(i,0,cl) {
      		rep(j,0,sz(t)/cl) {
			cout << t[i+j*cl];
      		}
    	}
    	cout << endl;
    	cin >> cl;
  	}
  	return 0;
} 
