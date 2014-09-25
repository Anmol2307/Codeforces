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
  string n;
  getline(cin,n);
  
  int sz = n.size();
  int last = n[sz-1] - '0';
  int slast = 0;
  if (sz > 1) slast = n[sz-2] - '0';
  last = slast*10 + last;
  last = last%4;
  // int arr1[4] = {1,1,1,1};
  // int arr2[4] = {1,2,4,3};
  // int arr3[4] = {1,3,4,2};
  // int arr4[4] = {1,4,1,4};
  if (last == 0) printf("4\n");
  else printf("0\n"); 
}