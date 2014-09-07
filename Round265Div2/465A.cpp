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
	char ch[n];
	scanf("%s",ch);
	
	int ans = 0;
	int i = 0;
	while (ch[i] == '1'){
		ans++; i++;
	}
	printf("%d\n",min(ans+1,n));
}