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
typedef long long int lli;

int main () {
  lli n, m, a, b;
  scanf("%lli %lli %lli %lli",&n,&m,&a,&b);
  
  // lli one = n*a;
  // lli two = (n/m+1)*b;
  // lli three = (n/m)*b + (n%m)*a;
  // lli ans = min(min(one,two),three);
  // printf("%lli\n",ans);
  // return 0;

  lli ans = 0;
  if ((b/m) >= a) ans = n*a;
  else {
    ans = (n/m)*b;
    if (b < (n%m)*a) ans += b;
    else ans += (n%m)*a;
  }
  printf("%lli\n",ans);
}