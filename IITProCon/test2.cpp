#include <cstdio>
#include <cmath>
#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <map>
#include <cassert>
#include <string>
#include <cstring>

using namespace std;

#define rep(i,a,b) for(int i = a; i < b; i++)
#define S(x) scanf("%d",&x)
#define P(x) printf("%d\n",x)

typedef long long int LL;
const int N = 2*200005;
int tin[N];
int tout[N];
int X[N];
int A[N/2];
int D[N/2];
int BIT[N];
vector<int > g[N/2];
int tm;

void dfs(int c,int p,int d) {
  D[c] = d;
  tm++;
  tin[c] = tm;
  rep(i,0,g[c].size()) if(g[c][i] != p) {
    dfs(g[c][i], c, d+1);
  }
  tm++;
  tout[c] = tm;
}

void update(int idx,int val) {
  for(int i = idx; i < N; i += i&-i) BIT[i] += val;
}


int query(int idx) {
  int res = 0;
  for(int i = idx; i; i -= i&-i) res += BIT[i];
  return res;
}

int main() {
  int n,m;
  S(n);S(m);
  rep(i,1,n+1) S(A[i]);
  rep(i,0,n-1) {
    int x,y;
    S(x);S(y);
    g[x].push_back(y);
    g[y].push_back(x);
  }
  dfs(1,-1,1);
  rep(i,0,m) {
    int type;
    int x;
    S(type);
    S(x);
    if(type == 1) {
      int v;
      S(v);
      if(!(D[x]&1)) v = -v;
      update(tin[x],v);
      update(tout[x]+1,-v);
    } else {
      int ans = A[x];
      int sign = 1;
      if(!(D[x]&1)) sign = -1;
      ans += sign * query(tin[x]);
      printf("%d\n",ans);
    }
  }
  return 0;
}