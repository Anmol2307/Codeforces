#include <bits/stdc++.h>

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

string s;

int main(){
    int n, p, i, j, k;
    cin>>n>>p;
    cin>>s;
    s = "  " + s;
    for(i = n + 1; i >= 2; i--){
        for(j = s[i] - 'a' + 1; j < p; j++){
            if(j != s[i - 1] - 'a' && j != s[i - 2] - 'a'){
                break;
            }
        }
        //cout<<i<<" "<<j<<endl;
        
        if(j >= p){
            continue;
        }
        
        printf("%d %d\n",i,j);
        exit(0);

        s[i] = j + 'a';
        for(k = i + 1; k <= n + 1; k++){
            for(j = 0; j < p; j++){
                if(j != s[k - 1] - 'a' && j != s[k - 2] - 'a'){
                    break;
                }
            }
            if(j == p){
                break;
            }
            s[k] = j + 'a';
        }
        //cout<<k<<endl;
        if(k <= n + 1){
            i = 0;
        }
        break;
    }
    if(i >= 2){
        for(i = 2; i <= n + 1; i++){
            cout<<s[i];
        }
        cout<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    return 0;
}