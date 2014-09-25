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

map<int,int> m;
long long int dp[100005];

int main () {
  int n;
  inp(n);

  int ma = -1;
  for (int i = 0; i < n; i++) {
    int x;
    inp(x);
    if (x > ma) ma = x;
    m[x]++;
  }

  dp[0] = 0;
  dp[1] = m[1];
  for (int i = 2; i <= ma; i++) {
    dp[i] = max(dp[i-1],dp[i-2] + (long long int)m[i]*(long long int)i);
  }
  printf("%lli\n",dp[ma]);
}