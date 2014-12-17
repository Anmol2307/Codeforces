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
#define N 222222

int main () {
  int a, b;
  scanf("%d %d",&a,&b);
  
  if (a < b) {
    printf("0\n");
  }
  else if (a == b) {
    printf("infinity\n");
  }
  else {
    int x = a-b;
    int y = sqrt(x);
    int ans = 0;
    for (int i = 1; i <= y; i++) {
      if (x%i == 0) {
        if (i > b) {
          // printf("H %d\n",i);
          ans++;
        }
        if (x/i != i && x/i > b) {
          // printf("H %d\n",x/i);
          ans++;
        }
      }
    }
    // if (y*y == x && y > b) {
    //   // printf("H %d\n",y);
    //   ans++;
    // }
    printf("%d\n",ans);
  }
}