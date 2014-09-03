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

int L[1001][1001];
vector <int> X;
vector <int> Y;
vector <int> ans;
int n;

 
void lcs(int m, int n)
{
   int i, j;
   memset(L,0,sizeof(L));
   for (i=1; i<=m; i++)
   {
     for (j=1; j<=n; j++)
     {
        if (X[i-1] == Y[j-1]){
          L[i][j] = L[i-1][j-1] + 1;
        }
  
        else{
          L[i][j] = max(L[i-1][j], L[i][j-1]);
        }
     }
   }
}

void printLCS(int i,int j)
{
    if (i==0 || j==0)
       return;
    if (X[i-1]==Y[j-1])
    {
        printLCS(i-1,j-1);
        ans.push_back(X[i-1]);
    }
    else if (L[i][j]==L[i-1][j])
         printLCS(i-1,j);
    else
        printLCS(i,j-1);
}

int main () {
  int k;
  inp(n); inp(k);
  
  for (int i = 0; i < n; i++) {
      int val;inp(val);
      X.push_back(val);
  }
  for (int i = 1; i < k; i++) {
    Y.clear();
    for (int i = 0; i < n; i++) {
      int val;inp(val);
      Y.push_back(val);
    }
    lcs(X.size(), Y.size());
    printLCS(X.size(), Y.size());
    X.clear();

    for (int i = 0; i < ans.size(); i++) {
      X.push_back(ans[i]);
    }
    ans.clear();
  }
  printf("%lu\n",X.size());
}