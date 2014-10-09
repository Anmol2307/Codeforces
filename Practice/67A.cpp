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
  int n; inp(n);
  string str;
  cin >> str;

  for (int i = 0; i < n; i++) {
    int c1 = 0, c2 = 0;
    for (int j = i-1; j >= 0; j--) {
      if (str[j] == 'R') c1++;
      else if (str[j] == 'L') break;
    }

    for (int j = i+1; j < n; j++) {
      if (str[j-1] == 'L') c2++;
      else if (str[j-1] == 'R') break;
    }
    int ans = ( (c1 > c2)? c1 : c2 ) + 1; 
    printf("%d ",ans);
  }
  printf("\n");
}