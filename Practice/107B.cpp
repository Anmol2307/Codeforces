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
  int n, m, h;
  inp(n); inp(m); inp(h);

  vector <int> s;
  int sum = 0;

  for (int i = 0; i < m; i++) {
    int x; inp(x);
    s.push_back(x);
    sum += x;
  }

  if (sum < n) {
    printf("-1\n");
    return 0;
  }
  
  h--;n--;s[h]--;sum--;
  double res=1;
  for(int i=0;i<s[h];i++)
    res*=double(sum-n-i)/(sum-i);
  printf("%f",1-res);
  return 0;
}