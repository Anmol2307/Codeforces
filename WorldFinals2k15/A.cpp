#include <bits/stdc++.h>
using namespace std;
#define MAX 1000001

double data[MAX];
int p,a,b,c,d,n;

void pre (int n) {
	for (int i = 1; i <= n; i++) {
		data[i] = p*(sin(a*i+b) + cos(c*i+d) + 2);
	}
}

int main () {
	scanf("%d%d%d%d%d%d",&p,&a,&b,&c,&d,&n);
	double ans = 0;
	pre(n);
	double ma = data[1];
	for (int i = 2; i <= n; i++) {
		if (data[i] >= ma) ma = data[i];
		else if (ans < (ma - data[i])) ans =  ma - data[i];
	}
	printf("%.6lf\n",ans);
}