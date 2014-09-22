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

map<int, int> mymap;

int main () {
  int n, a, b;
  inp(n); inp(a); inp(b);

  int arr[n];
  int ans[n];
  for (int i = 0; i < n; i++) {
    inp(arr[i]);
    mymap[arr[i]] = i;
  }

  bool flag = false;
  if (a > b) {
    swap(a,b);
    flag = true;
  }

  map<int,int>::iterator it;
  while (!mymap.empty()) {
    it = mymap.begin();
    // it--;
    int first = it->first;
    int index = it->second;

    if (mymap.find(b-first) != mymap.end()) {
      ans[index] = 1;
      ans[mymap[b-first]] = 1;
      mymap.erase(first);
      mymap.erase(b-first);
      continue;
    }
    if (mymap.find(a-first) != mymap.end()) {
      ans[index] = 0;
      ans[mymap[a-first]] = 0;
      mymap.erase(first);
      mymap.erase(a-first);
      continue;
    }
    printf("NO\n");
    return 0;
  }
  printf("YES\n");
  if(flag) {
    for(int i=0; i < n; i++) printf("%d ",1-ans[i]);
    printf("\n");
  }
  else {
    for(int i=0; i < n; i++) printf("%d ",ans[i]);
      printf("\n");
  }
}