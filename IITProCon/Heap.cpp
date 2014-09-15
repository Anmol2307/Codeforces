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


  int main () {
    int n;
    inp(n);
    vector<int> arr[101];
    n *= 2;
    int heap[201];
    int count[2];
    int x;
    for (int i = 0; i < n; i++) {
      inp(x);
      arr[x].push_back(i);
    }
    x = 0;
    for (int i = 0; i <= 100; i++) {
      if (arr[i].size() == 1){
        int id = arr[i].back();
        arr[i].pop_back();
        heap[id] = x;
        count[x]++;
        x = (x+1)%2;
      }
    }

    for (int i = 0; i <= 100; i++) {
      if (!arr[i].empty()){
        count[0]++; count[1]++;
        while (!arr[i].empty()) {
          int id = arr[i].back();
          arr[i].pop_back();
          heap[id] = x;
          x = (x+1)%2;
        }
      }
    }

    printf("%d\n",count[0]*count[1]);
    for (int i = 0; i < n; i++)
      printf("%d ",(heap[i] + 1)%2 + 1);
    printf("\n");
  }