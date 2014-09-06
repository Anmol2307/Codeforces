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

typedef long long int lli;

int main () {
  int n;
  inp(n);
  lli s;
  scanf("%lli",&s);
  int arr[n];
  map <lli, vector<int> > mymap;
  inp(arr[0]);
  vector <int> vec;
  vec.push_back(0);
  mymap.insert(pair<lli, vector<int> >(arr[0],vec));
  lli sum = arr[0];
  for (int i = 1; i < n; i++) {
    inp(arr[i]);
    sum += arr[i];
    if (mymap.find(sum) != mymap.end()){
      (mymap.find(sum)->second).push_back(i);
    }
    else {
      vector <int> v; v.push_back(i);
      mymap.insert(pair<lli, vector<int> >(sum,v));  
    }
    // printf("%lli %d\n",sum,i);
  }

  // printf("\n");



  map<lli,vector<int> >::iterator it;
  
  // for (it = mymap.begin(); it != mymap.end(); it++) {
  //   printf("%lli %d\n",it->first, it->second);
  // }
  // exit(0);

  int ans = 0;
  for (it = mymap.begin(); it != mymap.end(); it++) {
    if (it->first == sum) {
      ans += it->second.size();
      // printf("HERE %lli %d\n",it->first,ans);
    }

    lli val = it->first - s;
    if (mymap.find(val) != mymap.end() ) {
      for (int i = 0; i < it->second.size(); i++) {
        for (int j = 0; j < mymap.find(val)->second.size(); j++) {
          if (mymap.find(val)->second[j] < it->second[i]) {
            ans++;  
            // printf("%lli %d\n",it->first,ans);
          }
        }
      }
    }
  }
  printf("%d\n",ans);
}