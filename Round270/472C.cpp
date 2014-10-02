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
  int n;
  inp(n);

  map<int,pair<string,string> > mymap;

  for (int i = 1; i <= n; i++) {
    string str;
    cin >> str;
    mymap[i].first = str;
    cin >> str;
    mymap[i].second = str;
  }

  vector <int> vec;

  for (int i = 0; i < n; i++) {
    int x; inp(x);
    vec.push_back(x);
  }
  vector <string> order;
  if (mymap[vec[0]].first.compare(mymap[vec[0]].second) < 0) {
    order.push_back(mymap[vec[0]].first);
  }
  else {  
    order.push_back(mymap[vec[0]].second);
  }
  int i;
  for (i = 1; i < n; i++) {
    int j = vec[i];
    if (mymap[j].first.compare(mymap[j].second) < 0) {
      if (mymap[j].first.compare(order[i-1]) > 0) {
        order.push_back(mymap[j].first);
      }
      else if (mymap[j].second.compare(order[i-1]) > 0) {
        order.push_back(mymap[j].second);
      }
      else {
        printf("NO\n");
        break;
      }
    }
    else {  
      if (mymap[j].second.compare(order[i-1]) > 0) {
        order.push_back(mymap[j].second);
      }
      else if (mymap[j].first.compare(order[i-1]) > 0) {
        order.push_back(mymap[j].first);
      }
      else {
        printf("NO\n");
        break;
      }
    }
  }
  if (i == n) printf("YES\n");
}