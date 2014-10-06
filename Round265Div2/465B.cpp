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

	for (int i = 0; i < n; i++) {
		inp(arr[i]);
	}
	int i = 0;

	while (i < n && arr[i] != 1) {
		i++;
	}
	int ans = 0;

	for (int j = i; j < n;) {
		ans++;
		if (j+1 < n && arr[j+1] == 1) {
			j++;
		}
		else {
			// printf("HERE %d\n",j);
			while (j+1 < n && arr[j+1] != 1) j++;
			// printf("HERE %d\n",j);
			// exit(0);
			if (j+1 < n && arr[j+1] == 1) {
				ans++;
				j++;
				continue;
			}
			else break;
		}
	}

	printf("%d\n",ans);
}