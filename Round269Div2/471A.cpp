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
  
  int arr[10];
  memset(arr,0,sizeof(arr));

  for (int i = 0; i < 6; i++) {
    int x; inp(x);
    arr[x]++;
  }
  bool flag = false;
  for (int i = 1; i <= 9; i++) {
    if (arr[i] >= 4) {
      arr[i] -= 4;
      flag = true;
      break;
    }
  }
  int count = 0;
  int k = 0;
  if (!flag) printf("Alien\n");
  else {
    for (int i = 1; i <= 9; i++) {
      if (arr[i] > 0) {
        count++; 
      }
    }
    if (count == 1) printf("Elephant\n");
    else printf("Bear\n");
  }
}