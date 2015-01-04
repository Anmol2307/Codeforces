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
typedef pair<int,int> pii;

bool mycomp(const pii& f, const pii& s) {
  if (f.first < s.first) return true;
  else if (f.first == s.first) return f.second < s.second;
  return false;
}


int main () {
  int n;
  inp(n);

  int arr[n];
  int onearr[n+1];
  int twoarr[n+1];
  map<int,int> o;
  map<int,int> t;

  for (int i = 0; i < n; i++) {
    inp(arr[i]);
  }
  int totone = 0, tottwo = 0;
  onearr[0] = 0;
  twoarr[0] = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i] == 1) {
      totone++;
      o[totone] = i;
      onearr[i+1] = onearr[i] + 1;
      twoarr[i+1] = twoarr[i];
    }
    else {
      tottwo++;
      t[tottwo] = i;
      onearr[i+1] = onearr[i];
      twoarr[i+1] = twoarr[i] + 1;
    }
  }

  vector<pii> vec;
  for (int i = 1; i <= n; i++) {
    int one = 0, two = 0;
    int j = -1;
    while (j < n) {
        if (o.find(i + onearr[j+1]) != o.end() && t.find(i + twoarr[j+1]) != t.end()) {
          int onepos = o[i + onearr[j+1]];
          int twopos = t[i + twoarr[j+1]];
          if (onepos < twopos) {
            j = onepos;
            one++;
          }
          else if (onepos > twopos) {
            j = twopos;
            two++;
          }
        }
        else if (o.find(i + onearr[j+1]) == o.end() && t.find(i + twoarr[j+1]) != t.end()) {
          int twopos = t[i + twoarr[j+1]];
          j = twopos;
          two++;
        }
        else if (o.find(i + onearr[j+1]) != o.end() && t.find(i + twoarr[j+1]) == t.end()) {
          int onepos = o[i + onearr[j+1]];
          j = onepos;
          one++;
        }
        else if (o.find(i + onearr[j+1]) == o.end() && t.find(i + twoarr[j+1]) == t.end() && j == n-1) {
          if (one != two && one > two && arr[n-1] == 1) {
            vec.push_back(pii(one,i));
          }
          else if (one != two && one < two && arr[n-1] == 2) {
            vec.push_back(pii(two,i));
          }
          break;
        }
        else break;
    }
  }

  sort(vec.begin(), vec.end(), mycomp);
  printf("%lu\n",vec.size());
  for (int i = 0; i < vec.size(); i++) {
    printf("%d %d\n",vec[i].first, vec[i].second);
  }
}