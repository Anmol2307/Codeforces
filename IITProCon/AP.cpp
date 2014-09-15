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
  int arr[n];
  
  for (int i= 0; i <n; i++) {
    inp(arr[i]);
  }

  if(n == 1) {
      printf("-1\n"); 
      return 0;
  } 
  else if(n == 0) {
      printf("0\n");
      return 0;
  }

  sort(arr,arr + n);
  int d = 1000000000;
  
  for(int i = 0;i < n - 1;i++) {
    if(arr[i + 1] - arr[i] < d) d = arr[i + 1] - arr[i];
  }
  
  int count = 0, pos = 0;
  for(int i = 0;i < n - 1;i++) {
    if(arr[i + 1] - arr[i] != d) {
      count++; pos = i;
    }
  }

  if(count == 0) {
    if(n == 2 && d > 1 && (arr[0] + arr[1]) % 2 == 0) {
      printf("3\n%d %d %d\n",arr[0] - d,(arr[0] + arr[1]) / 2,arr[1] + d);
    }
    else if(d != 0){
      printf("2\n%d %d\n",arr[0] - d,arr[n - 1] + d);
    } 
    else {
      printf("1\n%d\n",arr[0]);
    }
  }
  else if(count == 1 && ((arr[pos] + arr[pos + 1]) % 2 == 0) && (arr[pos] + arr[pos + 1]) / 2 - arr[pos] == d) {
    printf("1\n%d\n",(arr[pos] + arr[pos + 1]) / 2);
  }
  else {
    printf("0\n");
  }
}