#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <climits>
#include <cctype>
#include <cassert>
#include <complex>

using namespace std;

#define ull unsigned long long
#define ill long long int
#define pii pair<int,int>
#define pb(x) push_back(x)
#define F(i,a,n) for(int i=(a);i<(n);++i)
#define REP(i,a,n) for(i=(a);i<(n);++i)
#define FD(i,a,n) for(int i=(a);i>=(n);--i)
#define FE(it,x) for(it=x.begin();it!=x.end();++it)
#define V(x) vector<x>
#define S(x) scanf("%d",&x)
#define Sl(x) scanf("%llu",&x)
#define M(x,i) memset(x,i,sizeof(x))
#define debug(i,sz,x) F(i,0,sz){cout<<x[i]<<" ";}cout<<endl
#define MAX(a,b) ((a)>(b)?(a):(b))
ill ABS(ill a) { if ( a < 0 ) return (-a); return a; }
#define fr first
#define se second

/* Relevant code begins here */

/* Input from file or online */

void input() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif
}

/* Input opener ends */

#define N 100005

ill a[N], c[N];
ill n,m,w;
ill check(ill x) {
    ill days = 0;
    F(i,0,n) c[i] = 0;
    ill cur = 0;
    F(i,0,n) {
        if ( i >= w ) cur -= c[i-w];
        if ( a[i]+cur < x ) {
            ill temp = x-a[i]-cur;
            c[i] = temp;
            cur += temp;
            days += temp;
        }
    }
    return days;
}

int main() {
    // input();
    Sl(n); Sl(m); Sl(w);
    F(i,0,n) Sl(a[i]);

    ill lo = 1, hi = 10000000000LL;
    ill ans = 1;
    while ( lo <= hi ) {
        ill mid = (lo+hi)/2;
        if ( check(mid) <= m ) {
            ans = mid; lo = mid+1;
        } else hi = mid-1;
    }
    cout << ans << endl;
    return 0;
}
