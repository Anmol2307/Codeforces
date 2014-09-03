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
  vector <int> h;
  for (int i = 0; i < n; i++) {
    int x;
    inp(x);
    h.push_back(x);
  }

  int ans = h[0];
  int energy = 0;

  for (int i = 1; i < n; i++) {
    if (h[i] > h[i-1]){
      if (energy < (h[i] - h[i-1])) {
        ans += (h[i] - h[i-1]) - energy;
        energy = 0;
      }
      else energy -= (h[i] - h[i-1]);
    }
    else {
      energy += (h[i-1] - h[i]);
    }
  }

  printf("%d\n",ans);
}