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
  int x;
  inp(x);

  if (x == 1) {
    printf("1\n");
    return 0;
  }
  else if (x == 2 || x == 4 || x == 5) {
    printf("3\n");
    return 0;
  }
  else if (x == 3) {
    printf("5\n");
    return 0;
  }

  int ans = 3;
  while ((ans*ans + 1)/2 < x) ans +=2;
  printf("%d\n",ans);
}