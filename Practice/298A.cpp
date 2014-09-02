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


int main(){
  int n;
  string s;
  cin>>n>>s;
  int start = 0;
  while(s[start] == '.') start++;
  int end = n - 1;
  while(s[end]=='.') end--;
  if(s[end] != 'L') end++;
  else while(s[end] == 'L') end--;
  start++, end++;
  cout<<start<<" "<<end<<endl;;
}