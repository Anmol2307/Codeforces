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
  lli sum[n];

  for (int i = 0; i < n; i++) {
    scanf("%lli",&arr[i]);
  }
  sum[0] = arr[0];

  for (int i = 1; i < n; i++) {
    sum[i] = sum[i-1] + arr[i];
  }
  
  // for (int i = 0; i < n; i++) {
  //   printf("%lli ",sum[i]);
  // }
  // printf("\n");

  int x = 1, y = n-2;
  int ans = 0;
  while (x <= y) {
    lli p1 = sum[x-1];
    lli p2 = sum[y] - p1;
    lli p3 = sum[n-1] - p2 - p1;
    // printf("%lli %lli %lli\n",p1,p2,p3);
    if (p1 == p2 && p2 == p3) {
      ans++;
      if (arr[x] < arr[y]) x++;
      else y--;
    }
    if (p1 < p2 && arr[x+1] > 0 && x < y) {
      x++;
    }
    else if (p1 > p2 && arr[x+1] < 0 && x < y) {
      x++;
    }
    else if (p3 < p2 && arr[y-1] > 0 && x < y) {
      y--;
    }
    else if (p3 > p2 && arr[y-1] < 0 && x < y) {
      y--;
    }
    else {
      break;
    }
  }

  printf("%d\n",ans);
}