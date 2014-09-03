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
	int x1, y1, x2, y2;
	inp(x1); inp(y1); inp(x2); inp(y2);

	int x = abs(x2-x1);
	int y = abs(y2-y1);

	if (x == 0) {
		printf("%d %d %d %d\n",x1+y,y1,x2+y,y2);
	}
	else if (y == 0) {
		printf("%d %d %d %d\n",x1,y1+x,x2,y2+x);
	}
	else if (x == y) {
		printf("%d %d %d %d\n",x2,y1,x1,y2);
	}
	else {
		printf("%d\n",-1);
	}
}