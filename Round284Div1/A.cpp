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
typedef long long ll;
typedef vector <int> vi;
typedef pair< int ,int > pii;
typedef pair< int, ll > pil;
typedef istringstream iss;
typedef ostringstream oss;
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define sz size()
#define ln length()
#define rep(i,n) for(int i=0;i<n;i++)
#define fu(i,a,n) for(int i=a;i<=n;i++)
#define fd(i,n,a) for(int i=n;i>=a;i--)
#define all(a)  a.begin(),a.end() 
#define ESP (1e-9)
 
#define gi(n) scanf("%d",&n)
#define gl(n) cin >> n
#define pi(n) printf("%d",n)
#define pl(n) printf("%lld",n)
#define ps printf(" ")
#define pn printf("\n")
#define N 90
#define MOD 1000000007


int main () {
  ll x1, y1, x2, y2;
  int n;
  scanf("%lli %lli %lli %lli",&x1,&y1,&x2,&y2);
  inp(n);
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    ll a, b, c;
    scanf("%lli %lli %lli",&a, &b, &c);
    ll val1 = a*x1 + b*y1 + c;
    ll val2 = a*x2 + b*y2 + c;
    if ((val2 > 0 && val1 < 0) || (val2 < 0 && val1 > 0)) ans++;
  }

  printf("%lli\n",ans);
}