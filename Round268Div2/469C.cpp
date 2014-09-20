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

void func (int n) {
  if (n == 4) {
      printf("%d * %d = %d\n", 1,2,2);
      printf("%d * %d = %d\n", 3,4,12);
      printf("%d * %d = %d\n", 12,2,24);
  }
  else if (n == 5) {
    printf("%d - %d = %d\n", 3,1,2);
    printf("%d * %d = %d\n", 2,2,4);
    printf("%d * %d = %d\n", 4,5,20);
    printf("%d + %d = %d\n", 4,20,24);
  }
  else {
    printf("%d - %d = %d\n", n,n-1,1);
    printf("%d * %d = %d\n", 1,1,1);
    func(n-2);
  }
}

int main () {
  int n;
  inp(n);

  if (n < 4) printf("NO\n");
  else {
    printf("YES\n");
    func(n);
  }
}