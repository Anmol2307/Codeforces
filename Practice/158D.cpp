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

  int arr[n];

  for (int i = 0; i < n; i++) {
    inp(arr[i]);
  }
  int ans = INT_MIN;
  for (int diff = 1; diff <= n/3; diff++) { 
    if (n % diff == 0) {
      for (int j = 0; j < diff; j++) {
        int val = 0;
        for (int i = j;; i = (i+diff)%n) {
          val += arr[i];
          if (i != j && (i+diff)%n == j) break;
        }
        ans = max(ans, val);
      } 
    }
  }
  printf("%d\n",ans);
}