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

  int maxx = -1, maxy = -1;
  pair <int,int> arr[n];
  for (int i = 0; i < n; i++){
    int x, y;
    inp(x); inp(y);
    pair<int,int> p(x,y);
    arr[i] = p;
  }
  sort(arr, arr+n);

  for (int i = 1; i < n; i++) {
    if (arr[i].second < arr[i-1].second) {
      printf("Happy Alex\n");
      return 0;
    }
  }
  printf("Poor Alex\n");

}