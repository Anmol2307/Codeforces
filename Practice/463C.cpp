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
#define NMAX 2002
typedef long long int lli;

int a[NMAX][NMAX];
lli D1[2*NMAX], D2[2*NMAX];

int main () {
  int n;
  inp(n);

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      inp(a[i][j]);
      D1[i+j] += a[i][j];
      D2[i-j+n] += a[i][j];
    }
  }
  lli sol[2];
  sol[0] = sol[1] = -1;
  pair<int,int> v[2];
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if ((i+j) & 1) {
        lli val = D1[i+j] + D2[i-j+n] - a[i][j];
        if (val > sol[1]) {
          sol[1] = val;
          v[1].first = i;
          v[1].second = j;
        }
      }
      else {
        lli val = D1[i+j] + D2[i-j+n] - a[i][j];
        if (val > sol[0]) {
          sol[0] = val;
          v[0].first = i;
          v[0].second = j;
        }
      }
    }
  }

  printf("%lli\n",sol[0] + sol[1]);
  if (v[0] > v[1]) swap(v[0], v[1]);
  printf("%d %d %d %d\n",v[0].first,v[0].second,v[1].first,v[1].second);
}