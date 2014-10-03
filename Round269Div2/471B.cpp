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
typedef vector <pair<int,int> > vpii;

int main () {
  int n;
  inp(n);

  vpii vec;
  for (int i = 0; i < n; i++) {
    int x; inp(x);
    vec.push_back(pair<int,int>(x,i+1));
  }

  sort(vec.begin(), vec.end());

  int count = 1;
  int val = 1;
  for (int i = 0; i < vec.size() - 1; i++) {
    if (vec[i].first == vec[i+1].first) count++;
    else val *= count;
  }

  if (val >= 3) {
    vector <vector <int> > ans(3);

  }
  else printf("NO\n");


}