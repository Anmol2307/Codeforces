#include <bits/stdc++.h>

using namespace std;

inline void inp(int &n ) {//fast input function
    n=0;
    int ch=getchar(),sign=1;
    while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar();}
    while( ch >= '0' && ch <= '9' )
        n=(n<<3)+(n<<1)+ ch-'0', ch=getchar();
    n=n*sign;
}
typedef unsigned long long lli;

int main()
{
  long long n,a,b;
  fi>>n>>a>>b;
  n*=6;
  bool ok=bool(a>b);
  if (ok) swap(a,b);
  long long besta=a,bestb=b;
  for (long long i=a;i*i<=n;++i)
  {
    long long y=(n+i-1)/i;
    if (y<b) y=b;
    if (i*y<besta*bestb || besta*bestb<n) besta=i,bestb=y;
  }
  a=besta;b=bestb;
  if (ok) swap(a,b);
  fo<<b*a<<'\n'<<a<<' '<<b<<'\n';
  return 0;  
}