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
  lli n;
  scanf("%lli", &n);
  
  lli i;
  lli ans = 0;
  for (i = 1;;i++) {
    lli val = i*(3*i+1);
    val /= 2;
    if (val > n) break;
    if ((n + i)%3 == 0) ans++;
  }
  printf("%lli\n",ans);
}