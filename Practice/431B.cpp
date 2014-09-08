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


vector<string> genPerm(int n) {
  if (n==1) {
    vector <string> vec;
    vec.push_back("1");
    return vec;
  }

  vector <string> ans  = genPerm(n-1);
  vector <string> ret;
  for (int i = 0; i < ans.size(); i++) {
    string str = ans[i];
    for (int j = 0; j <= str.size(); j++) {
      string str1 = str;
      char ch = (char)(n + 48);
      str1.insert(j,1,ch);
      ret.push_back(str1);
    }
  }
  return ret;
}


int main () {
  int mat[5][5];

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      inp(mat[i][j]);
    }
  }
  vector <string> vec = genPerm(5);
  int ans = 0;
  for (int i = 0; i < vec.size(); i++) {
    string str = vec[i];
    int a = str[0] - '0' - 1;
    int b = str[1] - '0' - 1;
    int c = str[2] - '0' - 1;
    int d = str[3] - '0' - 1;
    int e = str[4] - '0' - 1;
    int sum = 0;
    sum += mat[a][b] + mat[b][a];
    sum += mat[b][c] + mat[c][b];
    sum += (mat[c][d] + mat[d][c])*2;
    sum += (mat[d][e] + mat[e][d])*2;
    if (sum > ans) ans = sum;
  }
  printf("%d\n",ans);
}