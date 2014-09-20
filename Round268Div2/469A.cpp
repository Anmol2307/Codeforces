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
  
  bool arr[n];

  for (int i = 0; i < n; i++) {
    arr[i] = false;
  }

  int p; inp(p);

  for (int i = 0; i < p; i++) {
    int x; inp(x);
    arr[x-1] = true;
  }

  int q; inp(q);

  for (int i = 0; i < q; i++) {
    int x; inp(x);
    arr[x-1] = true;
  }

  bool flag = false;
  for (int i = 0; i < n; i++) {
    if (arr[i] == false) {
      flag = true;
      break;
    }
  }
  if (!flag) printf("I become the guy.\n");
  else printf("Oh, my keyboard!\n");
}