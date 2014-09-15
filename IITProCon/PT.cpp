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
  
  int n,t,c;
  inp(n);inp(t);inp(c);
  
  int len = 0, ans= 0;
  for(int i=0;i<n;i++){
    int x;
    inp(x);
    if(x<=t)len++;
    else len=0;
    if(len>=c)ans++;
  }
  printf("%d\n",ans);
  return 0;
}