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

bool iscomp(int n) {
  for (int i = 2; i*i <= n; i++) {
    if (n%i == 0) return true;
  }
  return false;
}


int main () {
  int n;
  inp(n);

  for (int i = 2; i < n; i++) {
    if (iscomp(i) && iscomp(n-i)) {
      printf("%d %d\n",i,n-i);
      break;
    }
  }
}