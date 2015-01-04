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


int main () {
  int n, m;
  inp(n); inp(m);

  vector <string> vec;

  for (int i = 0; i < n; i++) {
    string str;
    getline(cin,str);
    vec.push_back(str);
  }
  int ans = 0;
  int sorted = 0;
  memset(arr,0,sizeof arr);
  for (int i = 0; i < n-1; i++) {
    if (vec[i][0] > vec[i+1][0]) {
      ans++;
      sorted = -1;
      break;
    }
    else if (vec[i][0] == vec[i+1][0]) {
      sorted = -2;
    }
  }

  for (int i = 1; i < m; i++) {
    if (sorted < 0) {
      for (int j = 0; j < n; j++) {

      }
    }
  }
}