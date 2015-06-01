#include <bits/stdc++.h>

using namespace std;

char last; 
char slast;
string ans;

void find (int n, int m) {
	if (n == 0) {
		if (m > 2) {
			ans = "2";
			return;
		}
		else if (m == 2){
			if (last == '2') {
				ans = "11";
			}
			else if (last == '0') {
				ans += "11";
			}
			else {
				ans = "2";
				return;
			}
		}
		else if (m == 1) {
			if (last == '2') {
				ans = "1";
			}
			else if (last == '0') {
				ans += "1";
			}
			else {

				if (slast == '1') {
					ans = "2";
					return;
				}
				else {
					ans += "1";
				}
			}
		}
		return;
	}

	if (m == 0) {
		if (n > 1) {
			ans = "2";
			return;
		}
		else if (n == 1) {
			if (last == '2') {
				ans += "0";
			}
			else if (last == '1') {
				ans += "0";
			}
			else {
				ans = "2";
				return;
			}
		}
		return;
	}

	if (n != 0 && m != 0) {
		if (last == '2') {
			ans += 1;
			last = '1';
			find(n,m-1);
		}
		else if (last == '0') {
			slast = last;
			last = '1';
			ans += 1;
			find(n,m-1);
		}
		else {
			if (slast == '2') {
				slast = last;
				last = '1';
				ans += 1;
				find(n,m-1);
			}
			else if (slast == '1') {
				slast = last;
				last = '0';
				ans += "0";
				find(n-1,m);
			}
			else {
				slast = last;
				last = '1';
				ans += "1";
				find(n,m-1);
			}
		}
	}
	return;
}


int main () {
	int n, m;
	scanf("%d %d", &n, &m);
	last = '2';
	slast = '2';
	ans = "";
	find(n,m);
	reverse(ans.begin(), ans.end());
	if (ans == "2") {
		printf("-1\n");
	}
	else 
		printf("%s\n",ans.c_str());
}