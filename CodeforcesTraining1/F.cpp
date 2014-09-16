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

  string prev, cur;
  getline(cin,prev);
  printf("%s\n",prev.c_str());

  int prevlen = 0, curlen = 0, minlen = 0, pspace = 0;
  while (getline(cin,cur) && cur != "") {
    int x = 0;
    curlen = cur.size();
    prevlen = prev.size();
    minlen = min(curlen, prevlen);
      
    for (int i = 0; i < minlen; i++) {
      if (cur[i] == prev[i]) {
        x++;
      }
      else break;
    }
    int space = min(pspace+1,x);
    pspace = space;
    printf("%s",string(space,' ').c_str());
    printf("%s\n",cur.c_str());
    prev = cur;
  }
}
