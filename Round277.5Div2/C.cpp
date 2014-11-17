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
#define N 101
#define M 905
#define MOD 1000000007
int m, s;
string dp[N][M];
string rev (string num) {
  int l = num.size();
  int count = 0;
  string ret = "";
  stack<char> stk;
  for (int i = 0; i < l; i++) {
    if (num[i] == '0') count++;
    else {
      stk.push(num[i]);
    }
  }

  for (int i = 0; i < count; i++) {
    stk.push('0');
  }

  while(!stk.empty()){
    ret += stk.top();
    stk.pop();
  }
  return ret;
}

string find (int digits, int sum, string val, int base, int start) {
  if (digits == m && sum == s && dp[digits][sum] != "") return dp[digits][sum];
  else if (digits == m && sum != s) return "";
  else {
    if (start == 1) {
      string tmp = "";
      for (int i = base+1; i <= 9; i++) {
        string s = val;
        s.push_back((char)(i+48));
        tmp = find(digits+1,sum+i,s,i,0);
        if (tmp != "") {
          dp[digits][sum] = tmp;
          return tmp; 
        }
      }
      return tmp;
    }
    else {
      string s = val;
      s.push_back((char)(48));
      string tmp = find(digits+1,sum,s,base,0);
      if (tmp != "") {
        dp[digits][sum] = tmp;
        return tmp;
      }
      for (int i = base; i <= 9; i++) {
        string s = val;
        s.push_back((char)(i+48));
        tmp = find(digits+1,sum+i,s,i,0);
        if (tmp != "") {
          dp[digits][sum] = tmp;
          return tmp;
        }
      }
      return tmp;
    }
  }
}

int main () {
  inp(m); inp(s);
  for (int i = 0; i <= m; i++) {
    for (int j = 0; j <= s; j++) {
      dp[i][j] = "";
    }
  }

  string ans = find(0,0,"",0,1);
  if (ans != "") printf("%s %s\n",ans.c_str(),rev(ans).c_str());
  else printf("-1 -1\n");
}