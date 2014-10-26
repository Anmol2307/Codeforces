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
  int n, k;
  inp(n); inp(k);
  int arr[n];

  for (int i = 0; i < n; i++) {
    inp(arr[i]);
  }

  vector <pii> vec;
  int i = 0;
  // int gd = INT_MAX;
  for (i = 0; i < k; i++) {
    int mi, ma;
    int miv = INT_MAX, mav = INT_MIN;
    // int nd;
    for (int j = 0; j < n; j++) {
      if (arr[j] < miv) {
        mi = j;
        miv = arr[j];
      }
      if (arr[j] > mav) {
        mav = arr[j];
        ma = j;
      }
    }
    // nd = mav - miv;
    if (mi != ma) {
      arr[ma]--;
      arr[mi]++;
      vec.push_back(pii(ma,mi));
      // gd = nd;
    }
    else {
      break;
    }
  }

  int miv = INT_MAX, mav = INT_MIN;
  for (int j = 0; j < n; j++) {
    if (arr[j] < miv) {
      miv = arr[j];
    }
    if (arr[j] > mav) {
      mav = arr[j];
    }
  }
  printf("%d ",mav-miv);
  printf("%d\n",i);
  for (int j  = 0; j < vec.size(); j++) {
    printf("%d %d\n",vec[j].ff+1,vec[j].ss+1);
  }
}