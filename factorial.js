/*
http://www.spoj.pl/problems/FCTRL/
SPOJ Problem Set (classical)
11. Factorial
Problem code: FCTRL

TODO:
6869336 	2012-04-18 21:42:20 	Nick Pepper
Factorial
runtime error (NZEC)
6.00 	179M 	JS

*/
importPackage(java.io);
importPackage(java.lang);
 
var reader = new BufferedReader( new InputStreamReader(System['in']) );
var t = reader.readLine();
var num = null;

function zeta(n) {
	var ret = 0;
	for(var p = 5; p <= n; p *= 5)
		ret += parseInt(n/p);
	return ret.toString();
}

while(t--) {
	num = reader.readLine();
	if(!num)
       break;

	System.out.println( zeta(num) );
}

