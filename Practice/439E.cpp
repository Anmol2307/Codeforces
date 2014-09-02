#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define MAX 100001
typedef long long int lli

inline void inp(int &n ) {//fast input function
    n=0;
    int ch=getchar(),sign=1;
    while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar();}
    while( ch >= '0' && ch <= '9' )
        n=(n<<3)+(n<<1)+ ch-'0', ch=getchar();
    n=n*sign;
}

vector <int> divisors[MAX];
lli fact[MAX], invFact[MAX];

lli modexp(lli base, lli exponent) {
  lli ans = 1;

  while (exponent != 0) {
    if (exponent % 2 != 0) ans = (ans*base)%MOD;
    base = (base * base) % MOD;
    exponent /= 2;
  }
  return ans;
}

lli ncr (int n, int r) {
  if (r < 0 || r > n) return 0;

  lli ans = (((fact[n] * invFact[r])%MOD)*invFact[n-r])%MOD;
  return ans;
}

lli dp(int n,int f) {
  
}


int main () {
  
  for (int i = 1; i < MAX; i++) {
    for (int j = i; j < MAX; j+=i) {
      divisors[j].push_back(i);
    }
  }

  fact[0] = invFact[0] = 1;

  for (int i = 1; i < MAX; i++) {
    fact[i] = (fact[i-1]*i)%MOD;
    invFact[i] = modexp(fact[i],MOD-2);
  }

  int t;
  inp(t);
  while (t--) {
    int n, f;
    inp(n); inp(f);
    lli ans = dp(n,f);
    printf("%lli\n",ans);
  }
}