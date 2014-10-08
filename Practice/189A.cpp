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
  int n, a, b, c;
  inp(n); inp(a); inp(b); inp(c);
  int dp[n+1];
  memset(dp,0,sizeof(dp));

  for (int i = 1; i <= n; i++) {
    if (i >= a && ((i-a) == 0 || dp[i-a] != 0)) dp[i] = max(dp[i-a]+1, dp[i]);
    if (i >= b && ((i-b) == 0 || dp[i-b] != 0)) dp[i] = max(dp[i-b]+1, dp[i]);
    if (i >= c && ((i-c) == 0 || dp[i-c] != 0)) dp[i] = max(dp[i-c]+1, dp[i]);
  }

  // for (int i = 0; i <= n; i++) {
  //   printf("%d ",dp[i]);
  // }
  // printf("\n");
  printf("%d\n",dp[n]);

}