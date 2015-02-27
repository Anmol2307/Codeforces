#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> arr, int key)
{
    
    int l = -1, r = arr.size()-1;
    int m;

    while( r - l > 1 )
    {
        m = l + (r - l)/2;
 
        if( arr[m] >= key )
            r = m;
        else
            l = m;
    }
    return r;
}

int main () {
	vector <int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(4);
	vec.push_back(5);
	vec.push_back(5);
	vec.push_back(5);
	vec.push_back(6);
	vec.push_back(7);
	printf("%d\n",binarySearch(vec,5));
}