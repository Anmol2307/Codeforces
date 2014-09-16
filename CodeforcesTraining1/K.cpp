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


map<string,int> m;

int dp[101];


int findtab(string pre, string tofind) {
  // printf("cal %s %s\n",pre.c_str(),tofind.c_str());  
  if (m.find(tofind) == m.end()) {
    // printf("%d\n",-1);
    return -1;
  }
  if (pre.compare("") == 0) return m.find(tofind)->second + 1;

  int sz = tofind.size();
  map<string,int>::iterator e = m.find(tofind);
  map<string,int>::iterator it = e;
  map<string,int>::iterator f = m.begin(); f--;

  for (it--; it != f; it--) {
    string cmp = it->first;
    // printf("HERE %s %s\n",cmp.c_str(),pre.c_str());
    if (cmp.compare(pre) == 0) {
      // printf("%d - %d\n",e->second, it->second );
      return e->second - it->second;
    }
    else if (cmp.compare(pre) < 0) {
      // printf("%d - %d\n",e->second, it->second + 1);
      return e->second - it->second - 1;
    }
  }
  // return e->second - it->second - 1;
}

int find (string str) {
  int sz = str.size();
  dp[0] = 1;

  for (int i = 1; i < sz; i++) {
    int mi = INT_MAX;
    string use = str.substr(0,i+1);
    int x = findtab("",use);
    if (x != -1 && mi > x) {
      mi = min(x,i+1);
    }
    for (int j = 0; j < i; j++) {
      int x = findtab(str.substr(0,j+1),use);
      if (x != -1 && mi > (x + dp[j])) {
        mi = min(x + dp[j],dp[j] + i-j);
        
      }
      else if (x == -1 && mi > (dp[j] + i-j)){
        mi = dp[j] + i-j;
      }
    }
    dp[i] =  mi;
  }

  // for (int i = 0; i < sz; i++) {
  //   printf("%d ",dp[i]);
  // }
  // printf("\n");
  return dp[sz-1];
}

int main () {
  int n;
  inp(n);

  vector <string> vec;
  for (int i = 0; i < n; i++) {
    string str;
    getline(cin,str);
    vec.push_back(str);
  }

  // m.insert(pair<string,int>("",0));
  for (int i = 0; i < vec.size(); i++) {
    m.insert(pair<string,int>(vec[i],i));
  }

  string tofind;
  getline(cin,tofind);
  int ans = find(tofind) + 1;
  printf("%d\n",ans);
}