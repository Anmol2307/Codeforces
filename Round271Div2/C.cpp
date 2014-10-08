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

typedef pair<double, double> pdd;
#define eps 1e-8

pdd rotate (double x, double y, double a, double b, int cnt) {
  if (cnt == 0) return pdd(x,y);
  double ax, ay;
  for (int i = 0; i < cnt; i++) {
    ax = -(y-b) + a;
    ay = (x-a) + b;
    x = ax;
    y = ay;
  }
  return pdd(ax,ay);
}

double dist(pdd p1, pdd p2) {
    return sqrt((p1.first-p2.first)*(p1.first-p2.first) + (p1.second-p2.second)*(p1.second-p2.second));
}

int cmp(double a, double b) {
    if(abs(a-b)<eps)return 0;
    if((a-b)>eps)return 1;
    return -1;
}

bool check (pdd p1, pdd p2, pdd p3, pdd p4) {
  double a[6];
  a[0] = dist(p1,p2);
  a[1] = dist(p1,p3);
  a[2] = dist(p1,p4);
  a[3] = dist(p2,p3);
  a[4] = dist(p2,p4);
  a[5] = dist(p3,p4);
  sort(a, a+6);

  if(cmp(a[4],a[5])!=0)return false;
  if(cmp(a[3],a[4])==0)return false;
  if(cmp(a[0],a[1])!=0)return false;
  if(cmp(a[1],a[2])!=0)return false;
  if(cmp(a[2],a[3])!=0)return false;
  return true;
}

int main () {
  int n; inp(n);
  for (int i = 0; i < n; i++) {
    int ans = INT_MAX;
    vector <pdd> p(4);
    vector <pdd> h(4);
    for (int j = 0; j < 4; j++) {
      scanf("%lf %lf %lf %lf",&p[j].first, &p[j].second, &h[j].first, &h[j].second);
    }

    for (int j = 0; j < 4; j++) {
      for (int k = 0; k < 4; k++) {
        for (int l = 0; l < 4; l++) {
          for (int m = 0; m < 4; m++) {
            pdd  p1 = rotate(p[0].first, p[0].second, h[0].first, h[0].second, j);
            pdd  p2 = rotate(p[1].first, p[1].second, h[1].first, h[1].second, k);
            pdd  p3 = rotate(p[2].first, p[2].second, h[2].first, h[2].second, l);
            pdd  p4 = rotate(p[3].first, p[3].second, h[3].first, h[3].second, m);
            if (check(p1,p2,p3,p4)) {
              ans = min(ans,j+k+l+m);
            }
          }
        }
      }
    }
    if (ans == INT_MAX) printf("-1\n");
    else printf("%d\n",ans);
  }
}