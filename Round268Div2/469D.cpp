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
  int n, a, b;
  inp(n); inp(a); inp(b);
  vector <int> arr;
  vector <int> brr;
  map <int, int> m;
  for (int i = 0; i < n; i++) {
    int x; inp(x);
    arr.push_back(x);
    brr.push_back(x);
    m.put(pair<int,int>(x,-1));
  }

  sort(brr.begin(),brr.end());
  int set[n];
  memset(set,-1,sizeof(set));
  
  // map<int,int>::iterator it;

  // for (it = m.begin(); it != m.end(); it++) {
  //   if (it->second == -1) {
  //     map<int,int>::iterator tmp = m.find(a-it->first);
  //     if ((tmp != m.end()) && tmp->second == -1) {
  //       it->second = 0;
  //       tmp->second = 0;
  //       continue;
  //     }
  //     tmp = m.find(b-it->first);
  //     if ((tmp != m.end()) && tmp->second == -1) {
  //       it->second = 1;
  //       tmp->second = 1;
  //       continue;
  //     }
  //   }
  // }

  bool flag = false;
  vector<int>::iterator it = arr.begin();
  for (; it != arr.end(); it = arr.begin()) {
    
    if (set[i] == -1) {
      if (binary_search(brr.begin(),brr.end(),a - arr[i])) {
        set[i] = 0;
        vector<int>::iterator it = lower_bound(brr.begin(),brr.end(),a-arr[i]);
        brr.erase(it);
        set[it-brr.begin()] = 0;
      }
      else if (binary_search(brr.begin(),brr.end(),b - arr[i])) {
        set[i] = 1;
        vector<int>::iterator it = lower_bound(brr.begin(),brr.end(),b-arr[i]);
        brr.erase(it);
        set[it-brr.begin()] = 1;
      }
      else {
        flag = true;
        printf("NO\n");
        break;
      }
    }
  }

  if (!flag) {
    printf("YES\n");
    for (int i = 0; i < n; i++) {
      printf("%d ",set[i]);
    }
    printf("\n");
  }
}