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
typedef unsigned long long lli;

int main () {
  lli n, a, b;
  scanf("%llu %llu %llu",&n,&a,&b);

  lli val = ((lli)6)*n;
  lli val2 = a*b;
  lli ma = max(a,b);
  lli mi = min(a,b);
  if (val2 < val) {
    while (val2 < val) {
      ma++;    
      val2 = mi*ma;  
    }
    // printf("%lli\n",val2);
    // printf("%lli %lli\n",mi,ma); 
  }
  // else {
    printf("%llu\n",val2);
    printf("%llu %llu\n",mi,ma);
  // }

}