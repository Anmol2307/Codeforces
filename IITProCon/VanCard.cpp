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
  int n,x;
  inp(n); inp(x);

  int sum = 0;
  for (int i = 0; i < n; i++) {
    int val;
    inp(val);
    sum +=val;
  }

  sum = abs(sum);
  if (sum == 0) printf("%d\n",0);
  else if (sum <= x) {
    printf("%d\n",1);
  }
  else if (sum%x != 0){
    printf("%d\n",sum/x + 1);
  }
  else {
    printf("%d\n",sum/x);
  }
}