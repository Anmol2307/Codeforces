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
#define N 200005

int B[N], E[N], lps[N];
int n, w;

void computeLPS() {
  lps[0] = 0;
  int len = 0;
  int i = 1;

  while (i < w) {
    if (E[i] == E[len]) {
      len++;
      lps[i] = len;
      i++;
    }
    else {
      if (len != 0) {
        len = lps[len-1];
      }
      else {
        lps[i] = 0;
        i++;
      }
    }
  }
}

int main () {
  inp(n); inp(w);

  for (int i = 0; i < n; i++) {
    inp(B[i]);
    if (i > 0) {
      B[i-1] = B[i] - B[i-1];
    }
  }

  for (int i = 0; i < w; i++) {
    inp(E[i]);
    if (i > 0) {
      E[i-1] = E[i] - E[i-1];
    }
  }

  if (w > n) {
    printf("0\n");
    return 0;
  }
  else if (w == 1) {
    printf("%d\n",n);
    return 0;
  }

  n--, w--;

  computeLPS();

  int i = 0, j = 0, ans = 0;

  while (i < n) {
    if (E[j] == B[i]) {
      i++; j++;
    }
    if (j == w) {
      ans++;
      j = lps[j-1];
    }
    else if (E[j] != B[i]) {
      if(j != 0)
        j = lps[j-1];
      else
        i = i+1;
    }
  }
  printf("%d\n",ans);
}