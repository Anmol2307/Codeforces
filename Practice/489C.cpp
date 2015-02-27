#include <bits/stdc++.h>
using namespace std;

string largest = "", smallest = ""; 
int m, s;
bool flag;

string findLargest(int digits, int sum) {
	
	if (digits == 0 && sum == 0) {
		return "";
	}
	else if (digits == 0) {
		return "-1";
	}
	// 
	if (digits == 1 && (sum < 0 || sum > 9)) {
		largest = "-1";
		return largest;
	}
	else if (digits > 1 && sum == 0 && digits == m) {
		largest = "-1";
		return largest;
	}
	else if (digits == 1 && sum >= 0) {
		largest += (char)(sum + 48);
		return largest;
	}
	

	if (digits > 1 && sum >= 9) {
		largest += "9";
		return findLargest(digits-1,sum-9);
	}
	else if (digits > 1 && sum == 0) {
		while (digits > 0){
			largest += "0";
			digits--;
		}
		return largest;
	}
	else if (digits > 1) {
		largest += (char)(sum + 48);
		return findLargest(digits-1,0);
	}
}

string findSmallest(int digits, int sum) {
	if (digits == 1 && sum == 0) {
		return "0";
	}
	for (int i = 1; i <= 9 && sum >= i; i++) {
		largest = "";
		smallest = findLargest(digits-1,sum-i);
		if (smallest != "-1") {
			reverse(smallest.begin(), smallest.end());
			smallest = (char)(i + 48) + smallest;
			return smallest;
		}
	}
	return "-1";
}


int main () {
	scanf("%d %d", &m, &s);
	printf("%s ",findSmallest(m,s).c_str());
	largest = "";
	printf("%s\n",findLargest(m,s).c_str());
}