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

int main () {
  lli n, a, b;
  scanf("%lli %lli %lli", &n, &a, &b);

  n *= 6;
  lli cur = a*b;

  if (cur > n) {
    printf("%lli\n%lli %lli\n",cur,a,b);
  }
  else {
    lli sm = min(a,b);
    lli bg = max(a,b);
    lli ma = INT_MAX;
    lli mb = INT_MAX;
    lli mcur = ma*mb;
    
    for (lli i = sm; i*i <= n; i++) {
      lli na = i; 
      lli nb;
      if (n%i != 0) nb = n/i + 1;
      else nb = n/i;
      cur = na*nb;
      if (na < nb && nb >= bg) {
        if (cur < mcur) {
          mcur = cur;
          ma = na;
          mb = nb;
        }
      }
      else if (na >= nb && na >= bg && nb >= sm){
        if (cur < mcur) {
          mcur = cur;
          ma = na;
          mb = nb;
        }
      }
    }

      if (ma >= a && mb >= b) {
        printf("%lli\n%lli %lli\n",mcur,ma,mb);
      }
      else if (ma >= b && mb >= a) {
        printf("%lli\n%lli %lli\n",mcur,mb,ma);
      }
  }
}