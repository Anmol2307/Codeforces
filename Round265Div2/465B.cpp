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

	// int i = 0;
	// while (i < n && arr[i] != 1) i++;

	int ans = 0;
	bool flag = false;
	for (int j = 0; j < n;) {
		if (arr[j] == 0) {
			j++;
			continue;
		}
		if (!flag) {
			ans++;
			flag = true;
		}
		// printf("%d %d\n",j,ans);
		if ((j+1)< n && arr[j+1] == 1) {
			ans++; j++;
			flag = true;
			// printf("F %d %d\n",j,ans);
		}
		else if ((j+2) < n && arr[j+2] == 1) {
			ans++; j+=2; flag = false;
			// printf("S %d %d\n",j,ans);
		}
		else {
			if ((j+3) < n) {
				ans++;
				flag = false;
			}
			j += 3; 
			// printf("T %d %d\n",j,ans);
		}
		
	}

	printf("%d\n",ans);

}