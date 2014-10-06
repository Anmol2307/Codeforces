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

#define MOD 1000000007
#define N 100005
typedef long long int lli;

lli dp[N];
lli sum[N];

void pre (int k) {
  
  dp[0] = 1;
  for (int i = 1; i < k; i++) {
    dp[i] = 1;
  }
  for (int i = k; i < N; i++) {
    dp[i] = (dp[i-1] + dp[i-k])%MOD;
  }

  sum[0] = 0;
  for (int i = 1; i < N; i++) {
    sum[i] = (sum[i-1] + dp[i])%MOD;
  }
}

int main () {
  int t, k;
  inp(t); inp(k);
  pre(k);
  
  while (t--) {
    int a, b;
    inp(a); inp(b);
    lli ans = sum[b] - sum[a-1];
    if (ans < 0) ans += MOD;
    printf("%lli\n",ans);
  }
}