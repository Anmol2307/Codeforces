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
  int n, m;

  inp(n);
  int b[n];
  for (int i = 0; i < n; i++) {
    inp(b[i]);
  } 
  
  inp(m);
  int g[m];
  for (int i = 0; i < m; i++) {
    inp(g[i]);
  }

  sort(b,b+n);
  sort(g,g+m);

  if (n <= m) {
    int ans = 0;
    int j = 0;
    for (int i = 0; i < n; i++) {
      while (j < m) {
        if (g[j] <= b[i] && abs(g[j]-b[i]) > 1) {
          j++;
          continue;
        }
        else if (g[j] <= b[i] && abs(g[j]-b[i]) <= 1) {
          ans++;
          j++;
          break;
        }
        else if (g[j] > b[i] && abs(g[j]-b[i]) <= 1) {
          ans++;
          j++;
          break;
        }
        else if (g[j] > b[i] && abs(g[j]-b[i]) > 1) {
          break;
        }
      }
      if (j == m) break;
    }
    printf("%d\n",ans);
  }
  else {
    int ans = 0;
    int j = 0;
    for (int i = 0; i < m; i++) {
      while (j < n) {
        if (b[j] <= g[i] && abs(g[i]-b[j]) > 1) {
          j++;
          continue;
        }
        else if (b[j] <= g[i] && abs(g[i]-b[j]) <= 1) {
          ans++;
          j++;
          break;
        }
        else if (g[i] < b[j] && abs(g[i]-b[j]) <= 1) {
          ans++;
          j++;
          break;
        }
        else if (g[i] < b[j] && abs(g[i]-b[j]) > 1) {
          break;
        }
      }
      if (j == n) break;
    }
    printf("%d\n",ans);
  }
}