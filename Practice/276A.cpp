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


int main () {
  int n, k;

  inp(n); inp(k);

  int max = INT_MIN;
  for (int i = 0; i < n; i++) {
    int f, t;
    inp(f); inp(t);

    if (t > k) f -= (t-k);
    if (f > max) max = f;
  }
  printf("%d\n",max);
}