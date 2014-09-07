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

vector <int> alph[26];
int n;

bool check (char c[]) {
	char x = c[n-1];
	int z = x-'a';
	for (int i = 0; i < aplh[z].size(); i++) {
		int val = alph[z][i];
		for (int k = val; k < )
	}
}


int main () {
	int p;
	inp(n); inp(p);

	char ch[n];
	scanf("%s",ch);
	
	for (int i = 0; i < n; i++) {
		aplh[ch[i] - 'a'].push_back(i);
	}

	char test[n];
	for (int i = n-1; i >= 0; i--) {
		test = ch;
		for (int j = ch[i] - 'a'+1; j < p; j++) {
			test[i] = (char)(j+97);
			if (check(test)) printf("%s\n",test);
		}
	}

	

}