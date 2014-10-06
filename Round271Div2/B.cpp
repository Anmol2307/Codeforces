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
  vector<int> arr(n);
  vector<int> sum(n);

  for (int i = 0; i < n; i++) {
    inp(arr[i]);
  }

  sum[0]= arr[0];

  for (int i = 1; i < n; i++) {
    sum[i] = arr[i] + sum[i-1];
  }

  int m;
  inp(m);
  for (int i = 0; i < m; i++) {
    int x;
    inp(x);
    vector <int>::iterator low;
    low = lower_bound(sum.begin(),sum.end(),x);
    int ans = low-sum.begin();
    printf("%d\n",ans+1);
  }
}
