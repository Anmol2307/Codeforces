#include <bits/stdc++.h>
using namespace std;

// Returns true if set1 and set2 are disjoint, else false
bool areDisjoint(vector<int> set1, vector<int> set2)
{
    int n = set1.size();
    int m = set2.size();
    sort(set1.begin(), set1.end());
    sort(set2.begin(), set2.end());
 
    // The code below checks for common elements using a merge like process
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (set1[i] < set2[j]){
            i++;
        }
        else if (set2[j] < set1[i]){
            j++;
        }
        else {
            return false;
        }
    }
    return true;
}

int main () {
	vector <int> vec1;
	vec1.push_back(12);
	vec1.push_back(34);
	vec1.push_back(11);
	vec1.push_back(9);
	vec1.push_back(3);
	vector <int> vec2;
	vec2.push_back(7);
	vec2.push_back(2);
	vec2.push_back(1);
	vec2.push_back(5);

	if (areDisjoint(vec1,vec2)) {
		printf("Yes\n");
	}
	else {
		printf("No\n");
	}
}