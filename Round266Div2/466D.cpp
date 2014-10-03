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

typedef long long int lli;
#define MOD 1000000007
int arr[2001];
lli dp[2001][2011];
int n, h;
  
lli solve(int i, int opened) {
  if (i == n && opened == 0) return 1;
  else if (i == n) return 0;

  if (dp[i][opened] != -1) return dp[i][opened];

  lli ans = 0;

  if (arr[i] + opened == h) {
    ans += solve(i+1,opened);
    if (opened > 0) ans = (ans + (opened*solve(i+1, opened-1))%MOD) %MOD;
  }
  else if (arr[i] + opened == h-1) {
    ans += solve(i+1, opened+1);
    ans = (ans + ((opened+1)*solve(i+1,opened))%MOD)%MOD;
  }
  
  dp[i][opened] = ans;
  return ans;
}

int main () {
  inp(n); inp(h);

  for (int i = 0; i < n; i++) {
    inp(arr[i]);
  }

  memset(dp,-1,sizeof(dp));

  lli ans = solve(0,0);
  printf("%lli\n",ans);
}