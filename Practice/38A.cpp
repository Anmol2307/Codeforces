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
  int n;
  inp(n);

  int arr[n-1];
  int sum[n];
  for (int i = 0; i < n-1; i++) {
    inp(arr[i]);
  }

  sum[0] = 0;
  for (int i = 1; i < n; i++) {
    sum[i] = sum[i-1] + arr[i-1];
  }

  int a, b;
  inp(a); inp(b);
  int ans = sum[b-1] - sum[a-1];
  printf("%d\n",ans);
}
