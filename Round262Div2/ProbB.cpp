#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

///////////////////////////////////////////////////////////////////////////////////////////

int checksum (long long int val) {
  
  if(val == 0) return 0;
  int sum = 0;
  while (val != 0) {
    sum += (int)val%10;
    val = (long long int)val/10;
  }
  return sum;
}

long long int mypow(long long int a, int b) {
  long long int ans = a;
  for(int i=1; i<b; i++) {
    ans *= a;
  }
  return ans;
}

int main () {
  int a, b, c;
  scanf("%d %d %d", &a, &b, &c);
  vector <long long int> vec;
  int count = 0;
  for (int i = 1; i <= 81; i++) {
    long long int val = (long long int)mypow(i,a)*(long long int)b + (long long int)c; 
    if (checksum(val) == i && val > 0 && val < 1000000000) {
      count++;
      vec.push_back(val);
    }
  }
  // sort(vec.begin(), vec.end());
  printf("%d\n", count);
  for(int i=0; i<(int)vec.size(); i++) {
    printf("%lld%c", vec[i], (i == (int)vec.size()-1) ? '\n' : ' ');
  }
}