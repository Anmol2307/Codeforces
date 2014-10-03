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

int main () {
  int n;
  inp(n);

  lli arr[n];
  lli cnt[n];
  memset(cnt,0,sizeof(cnt));

  lli s = 0;
  for (int i = 0; i < n; i++) {
    scanf("%lli",&arr[i]);
    s += arr[i];
  }

  if (s % 3 != 0) {
    printf("0\n");
    return 0; 
  }
  s = s/3;
  lli ss = 0;
  for (int i = n-1; i >= 0; i--) {
    ss += arr[i];
    if (ss == s) cnt[i] = 1;
  }

  for (int i = n-2; i >= 0; i--) {
    cnt[i] += cnt[i+1];
  }

  lli ans = 0;

  ss = 0;

  for (int i = 0; i < n-2; i++) {
    ss += arr[i];
    if (ss == s) ans += cnt[i+2];
  }

  printf("%lli\n",ans);
}