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
  int n, m, k;
  inp(n); inp(m); inp(k);

  vector <int> vec;
  for (int i = 0; i <= m; i++) {
    int x;
    inp(x);
    vec.push_back(x);
  }
  int ans = 0;
  for (int j = 0; j < m; j++) {
    int num = vec[j];
    int fedor = vec[m];
    int x = 0;
    for (int i = 0; i  < n; i++) {
      if ((num^fedor) % 2 == 1) x++;
      num >>= 1;
      fedor >>= 1;
    }

    if (x <= k) ans++;
  }
  printf("%d\n",ans);
}