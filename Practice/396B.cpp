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

inline bool prime(long long int x) {
  for(int i=2;i*i<=x;i++)
    if (x%i==0) return false;
  return true;
}

int main () {
  int t;
  inp(t);

  while (t--) {
    long long int n;
    scanf("%lli",&n);
    long long int s, l;
    for (s=n; !prime(s); s--);
    for (l=n+1; !prime(l); l++);
    
    long long int num = s*l + 2*(n-s-l+1);
    long long int den = 2*s*l;
    long long int fact = __gcd(num, den);

    num /= fact;
    den /= fact;
    printf("%lli/%lli\n",num,den);
  }
}