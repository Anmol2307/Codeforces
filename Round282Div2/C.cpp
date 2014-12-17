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
  string str;
  cin >> str;
  int s = str.size();
  int arr[s];
  int cnt = 0;
  int idx = 0;

  for (int i = 0; i < s; i++) {
    if (str[i] == '(') cnt++;
    else if (str[i] == ')') cnt--;
    else {
      arr[idx++] = 1;
      cnt--;
    }
    if (cnt < 0) {
      printf("-1\n");
      return 0;
    }
  }
  arr[idx-1] += cnt;
  cnt = 0;
  int val = 0;
  
  for (int i = 0; i < s; i++) {
    if (str[i] == '(') cnt++;
    else if (str[i] == ')') cnt--;
    else {
      cnt -= arr[val++];
    }
    if (cnt < 0) {
      printf("-1\n");
      return 0;
    }
  }
  for (int i = 0; i < idx; i++) {
    printf("%d\n",arr[i]);
  }
}