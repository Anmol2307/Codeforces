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
	int n, k, d;
	inp(n); inp(k); inp(d);

	long long int val = 1;
	bool flag = false;

	for (int i = 0; i < d; i++) {
		val *= k;
		if (val >= n) {
			flag = true;
			break;
		}
	}

	if (!flag) {
		printf("%d	\n",-1);
		return 0;
	}

	int ans[1005][1005];
	memset(ans,0,sizeof(ans));

	for (int i = 1; i < n; i ++) 
    {
        for (int j = 0; j < d; j ++) ans[i][j] = ans[i - 1][j];
        for (int j = d - 1; j >= 0; j --)
        {
            ans[i][j] = (ans[i][j] + 1) % k;
            if (ans[i][j]) break;
        }
    }

    for (int i = 0; i < d; i ++, cout << endl)
        for (int j = 0; j < n; j ++)
            cout << ans[j][i] + 1 << ' ';
    return 0;
}