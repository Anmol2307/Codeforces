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

unsigned long long c[65][65], l = 1, r = 1e18, t, p, s;

int main()
{
    unsigned long long m, k;
    scanf("%llu %llu", &m, &k);

    c[0][0] = 1;

    for (int i = 1; i <= 64; i++){
        for (int j = 0; j <= i; j++){
            if (j == 0) c[i][j] = c[i - 1][j];
            else  c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
        }
    }

    unsigned long long l = 1, r = 1e18;
    unsigned long long t, p, s;

    while (l < r)
    {
        t = l + (r-l)/2;
        p = 0, s = 0;
        
        for (int i = 63; ~i && p <= k; i--) {
            if (t & 1ull << i) {
                s += c[i + 1][k - p] - c[i][k - p];
                p++;
            }
        }
        if (s < m)
            l = t + 1;
        else
            r = t;
    }

    printf("%llu\n", l);

    return 0;
}