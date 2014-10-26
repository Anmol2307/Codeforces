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
#define N 100005
#define MOD 1000000007

int n, l, x, y;
int arr[N];
bool checkx, checky;
 
bool binSearch (int num) {
  int i = 0, j = n-1, m;

  while (i <= j) {
    m = i + (j-i)/2;
    if (arr[m] == num) return true;
    else if (arr[m] < num) i = m+1;
    else j = m-1; 
  }
  return false;
}

int check () {
  for (int i = 0; i < n; i++) {
    bool one = binSearch(arr[i] + x + y);
    bool two = binSearch(arr[i] + x - y);
    bool three = binSearch(arr[i] - x + y);
    bool four = binSearch(arr[i] - x - y);
    if (arr[i] + x <= l) {
      if (one || two) {
        return (arr[i]+x); 
      }
    }
    if (arr[i] - x >= 0) {
      if (three || four) {
        return (arr[i]-x); 
      }
    }
    if (arr[i] + y <= l) {
      if (one || three) {
        return (arr[i]+y); 
      }
    }
    if (arr[i] - y >= 0) {
      if (two || four) {
        return (arr[i]-y); 
      }
    }
  }
  return -1;
}

int main () {
  inp(n); inp(l); inp(x); inp(y);

  for (int i = 0; i < n; i++) {
    inp(arr[i]);
  }

  for (int i = 0; i < n; i++) {
    bool leftx = binSearch(arr[i]-x);
    bool rightx = binSearch(arr[i]+x);
    if (leftx || rightx) {
      checkx = true;
      break;
    }
  }

  for (int i = 0; i < n; i++) {
    bool lefty = binSearch(arr[i]-y);
    bool righty = binSearch(arr[i]+y);
    if (lefty || righty) {
      checky = true;
      break;
    }
  }


  if (checkx && checky) printf("0\n");
  else if (checkx) {
    printf("1\n%d\n",y);
  }
  else if (checky) {
    printf("1\n%d\n",x); 
  }
  else {
    int val = check();
    if (val != -1) printf("1\n%d\n",val);
    else printf("2\n%d %d\n",x,y);
  }
}