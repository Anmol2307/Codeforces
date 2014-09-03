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

	for (int i = 0; i < n ; i++) {
		inp(arr[i]);
	}

	sort(arr,arr+n);

	if (arr[0] != arr[n-1]) {
		int i = 0, j = n-1;
		int init = arr[0];
		int final = arr[n-1];
		int ans = final - init;
		long long int x = 1, y = 1;
		while (arr[++i] == init) {
			x++;
		}
		while (arr[--j] == final) {
			y++;
		}

		long long int pro = x*y;
		printf("%d %lli\n",ans,pro);
	}
	else {
		long long int pro = (((long long int)n)*((long long int)(n-1)))/2;
		printf("%d %lli\n",0,pro);
	}
}