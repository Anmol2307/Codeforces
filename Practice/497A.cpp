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
int n,m,i,j,ans,tmp,flag[1000];
char s[1000][1000];
int main()
{
  scanf("%d%d",&n,&m);
  for (i=1;i<=n;i++) {
    scanf("%s",&s[i]);
  }
  for (j=0;j<m;j++){
    tmp=0;
    for (i=1;i<=n-1;i++) {
      if ((s[i][j]>s[i+1][j])&&(flag[i]==0)) {
        tmp=1;
      }
    }
    ans=ans+tmp;
    if (tmp==0){
      for (i=1;i<=n-1;i++) {
        if ((s[i][j]<s[i+1][j])&&(flag[i]==0)){
          flag[i]=1;
        }
      }
    }
  }
  printf("%d\n",ans);
}