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




int main()
{
    char ch[100001];
    scanf ("%s",ch);
   
    long long int mat[2][2],even,odd;
    
    for (int i=0;ch[i] != 0;i++){
        int x = ch[i] - 'a';
        int y = i % 2;
        mat[x][y]++;
        even += mat[x][!y];
        odd += mat[x][y];
    }
    
    printf ("%lli %lli\n",even,odd);

    return 0;
}