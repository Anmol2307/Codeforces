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
  char ch;
  cin >> ch;
  string arr[3];
  arr[0] = "qwertyuiop";
  arr[1] = "asdfghjkl;";
  arr[2] = "zxcvbnm,./";
  string ans = "";
  if (ch == 'L') {
    string str;
    cin >> str;
    for(int i = 0; i < str.size(); i++) {
      for (int j = 0; j < 3; j++) {
        int k;
        bool flag = false;
        for (k = 0; k < 10; k++) {
          if (arr[j][k] == str[i]) {
            ans += arr[j][k+1];
            break;
          }
        }
        if (flag) break;
      }
    }
  }
  else {
    string str;
    cin >> str;
    for(int i = 0; i < str.size(); i++) {
      for (int j = 0; j < 3; j++) {
        int k;
        bool flag = false;
        for (k = 0; k < 10; k++) {
          if (arr[j][k] == str[i]) {
            ans += arr[j][k-1];
            flag = true;
            break;
          }
        }
        if (flag) break;
      }
    }
  }
  printf("%s\n",ans.c_str()); 
}