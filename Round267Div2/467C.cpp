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

#define ll long long 

ll n,m,k,s[5005],d[5005][5005],i,j;
int main() {
  
  scanf("%lli %lli %lli",&n,&m,&k);
  for(i=1;i<=n;i++){
    scanf("%lli",&s[i]);
    s[i] += s[i-1];
  }

  for(i=1;i<=k;i++){
    for(j=i*m;j<=n;j++){
      d[i][j]=max(d[i][j-1],d[i-1][j-m]+s[j]-s[j-m]);
    }
  }
  printf("%lli\n",d[k][n]);
}