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
  int t;
  inp(t);

  int ans = 0;
  while (t--) {
    int p, q;
    inp(p);
    inp(q);

    if (q-p >= 2) ans++;
  }
  printf("%d\n",ans);
}