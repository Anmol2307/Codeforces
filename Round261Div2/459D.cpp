#include<bits/stdc++.h>

using namespace std;

#define LL long long int
#define sd(x) scanf("%d", &x)
#define MP make_pair
#define PB push_back
#define vi vector<int>
#define F first
#define S second
#define INF 2000000000
#define MOD 1000000007
#define D double
#define LD long double

#define N 2000000

map<int, int> cnt;

int a[N], b[N], c[N];
int bit[N];
int ret;

inline int query(int i){
    ret = 0;
    while(i > 0){
        ret += bit[i];
        i -= (i & (-i));
    }
    return ret;
}

inline void update(int i, int v){
    while(i < N){
        bit[i] += v;
        i += (i & (-i));
    }
}

int main(){
    int n, i, j;
    LL ans = 0;
    cin>>n;
    for(i = 0; i < n; i++){
        sd(a[i]);
        if(cnt.find(a[i]) == cnt.end()){
            cnt[a[i]] = 0;
        }
        j = cnt[a[i]];
        cnt[a[i]] = j + 1;
        b[i] = j + 1;
    }
    cnt.clear();
    for(i = n - 1; i >= 0; i--){
        if(cnt.find(a[i]) == cnt.end()){
            cnt[a[i]] = 0;
        }
        j = cnt[a[i]];
        cnt[a[i]] = j + 1;
        c[i] = j + 1;
    }

    // for (int i = 0; i < n; i++) {
    //     printf("%d ",b[i]);
    // }
    // printf("\n");
    // for (int i = 0; i < n; i++) {
    //     printf("%d ",c[i]);
    // }
    // printf("\n");
    // exit(0);

    for(i = 0; i < n; i++){
        ans += i - query(c[i]);
        update(b[i], 1);
        printf("%d %lli\n",i,ans);
    }
    cout<<ans<<endl;
    return 0;
}