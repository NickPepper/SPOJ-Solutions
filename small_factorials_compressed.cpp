#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;struct BI{string a;int s;BI(){}BI(string b){(*this)=b;}int size(){return a.size();}BI inv(){s*=-1;return(*this);}BI nrm(int nS){s=nS;for(int i=a.size()-1;i>0&&a[i]=='0';i--)a.erase(a.begin()+i);if(a.size()==1&&a[0]=='0')s=1;return(*this);}void operator = (string b){a=b[0]=='-'?b.substr(1):b;reverse(a.begin(),a.end());this->nrm(b[0]=='-'?-1:1);}bool operator < (const BI &b) const {if(a.size()!=b.a.size())return a.size()<b.a.size();for(int i=a.size()-1;i>=0;i--)if(a[i]!=b.a[i])return a[i]<b.a[i];return false;}BI operator + (BI b){if(s!=b.s)return(*this)-b.inv();BI c;for(int i=0,cy=0;i<(int)a.size()||i<(int)b.size()||cy;i++){cy+=(i<(int)a.size()?a[i]-48:0)+(i<(int)b.a.size()?b.a[i]-48:0);c.a+=(cy%10+48); cy/=10;}return c.nrm(s);}BI operator - (BI b){if(s!=b.s)return(*this)+b.inv();if((*this)<b)return(b-(*this)).inv();BI c;for(int i=0,bo=0;i<(int)a.size();i++) {bo=a[i]-bo-(i<b.size()?b.a[i]:48);c.a+=bo>=0?bo+48:bo+58;bo=bo>=0?0:1;}return c.nrm(s);}BI operator * (BI b){BI c("0");for(int i=0,k=a[i];i<(int)a.size();i++,k=a[i]){while(k-- - 48)c=c+b;b.a.insert(b.a.begin(),'0');}return c.nrm(s*b.s);}BI operator / (BI b){if(b.size()==1&&b.a[0]=='0')b.a[0]/=(b.a[0]-48);BI c("0"),d;for(int j=0;j<(int)a.size();j++)d.a+="0";int ds=s*b.s;b.s=1;for(int i=a.size()-1;i>=0;i--){c.a.insert(c.a.begin(),'0');c=c+a.substr(i,1);while(!(c<b))c=c-b,d.a[i]++;}return d.nrm(ds);}BI operator % (BI b){if(b.size()==1&&b.a[0]=='0')b.a[0]/=(b.a[0]-48);BI c("0");int cs=s*b.s;b.s=1;for(int i=a.size()-1;i>=0;i--){c.a.insert(c.a.begin(),'0');c=c+a.substr(i,1);while(!(c<b))c=c-b;}return c.nrm(cs);}void print(){if(s==-1)putchar('-');for(int i=a.size()-1;i>=0;i--)putchar(a[i]);}};BI fct(BI n){string s=n.a;if(s=="1")return BI("1");return n*fct(n-BI("1"));}int main(){int t;BI n;string s;scanf("%d",&t);while(t--){cin>>s;n=s;n=fct(n);n.print();cout<<endl;}return 0;}