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

  int p, q, l, r;

  inp(p); inp(q); inp(l); inp(r);

  pair <int, int> Z[55];
  pair <int, int> X[55];
  int arr[1005];
  memset(arr,0,sizeof(arr));

  for (int i = 0; i < p; i++) {
    inp(Z[i].first); inp(Z[i].second);
  }

  for (int i = 0; i < q; i++) {
    inp(X[i].first); inp(X[i].second);
  }

  for (int i = 0; i < q; i++) {
    for (int j = 0; j < p; j++) {
      int mi = Z[j].first - X[i].second;
      int ma = Z[j].second - X[i].first;
      mi = max(l,mi);
      ma = min(r,ma);
      for (int k = mi; k <= ma; k++) {
        arr[k] = 1;
      }
    }
  }
  int count = 0;
  for (int i = l; i <= r; i++) {
    if (arr[i] == 1) count++;
  }
  printf("%d\n",count);
}