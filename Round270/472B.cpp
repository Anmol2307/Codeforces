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
  int n, k;
  inp(n); inp(k);

  vector <int> vec;

  for (int i = 0; i < n; i++) {
    int x; inp(x);
    vec.push_back(x);
  }
  
  sort(vec.begin(), vec.end());
  int ans = 0;
  for (int i = n-1; i >= 0; i-=k) {
    ans += (vec[i] - 1)*2; 
  }

  printf("%d\n",ans);
  

}