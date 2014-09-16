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

string inttostring(int n)
{
  stringstream a;
  a<<n;
  string A;
  a>>A;
  return A;
}


string find (int n) {
  if (n == 1) return "((A0|B0)|(A0|B0))";
  string prev = find(n-1);
  string y = inttostring(n-1);
  string newstr = "|((A" + y + "|A" + y +")|(B" + y + "|B" + y + "))))";  
  string x = "((A" + y + "|B" + y + ")|(";
  x.append(prev);
  x.append(newstr);  
  return x; 
}

int main () {
  int n;
  inp(n);

  string ans = find(n);
  printf("%s\n",ans.c_str());
}