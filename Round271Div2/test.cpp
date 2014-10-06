#include <bits/stdc++.h>

using namespace std;
#define N 100005
typedef long long int lli;

lli A[N];
// int tailIndices[N];
lli tailTable[N];
int prevIndices[N];
lli n, d;


// int GetCeilIndex(int l, int r, int key) {
//    int m;
 
//    while( r - l > 1 ) {
//       m = l + (r - l)/2;
//       if( A[tailIndices[m]] >= key )
//          r = m;
//       else
//          l = m;
//    }
 
//    return r;
// }
 
// void LongestIncreasingSubsequence(int size) {
   
//     if (size == 1) {
//         printf("%d\n%lli\n",1,A[0]);
//     }
//    int len;
//    tailIndices[0] = 0;
//    prevIndices[0] = -1;
//    len = 1;
//    for( int i = 1; i < size; i++ ) {
//       if( abs(A[i] - A[tailIndices[0]]) < d) {
//          tailIndices[0] = i;
//       } else if (abs(A[i] > A[tailIndices[len-1]]) >= d) {
//          prevIndices[i] = tailIndices[len-1];
//          tailIndices[len++] = i;
//       } else {
//         int pos = GetCeilIndex(-1, len-1, A[i]);
//         prevIndices[i] = tailIndices[pos-1];
//         tailIndices[pos] = i;
//       }
//    } 
//    printf("%d\n",len);
//    vector <lli> vec;
//    for( int i = tailIndices[len-1]; i >= 0; i = prevIndices[i] )
//       vec.push_back(A[i]);
   
//    for (int i = vec.size() -1; i >= 0; i--) {
//     printf("%lli ",vec[i]);
//    }
//    printf("\n");
// }

int CeilIndex(int l, int r, int key) {
    int m;
 
    while( r - l > 1 ) {
        m = l + (r - l)/2;
        (A[m] >= key ? r : l) = m; // ternary expression returns an l-value
        // if (abs(A[m]))
    }
 
    return r;
}

int LongestIncreasingSubsequenceLength(int size) {
    // Add boundary case, when array size is one
 
    // int *tailTable   = new int[size];
    int len; // always points empty slot
 
    // memset(tailTable, 0, sizeof(tailTable[0])*size);
 
    tailTable[0] = A[0];
    len = 1;
    for( int i = 1; i < size; i++ ) {
        if( abs(A[i] - tailTable[0]) < d){
            // new smallest value
            // printf("F %lli\n",A[i]);
            tailTable[0] = A[i];
        }
        else if ( abs( A[i] - tailTable[len-1] ) >= d) {
            // A[i] wants to extend largest subsequence
            // printf("S %lli %lli\n", A[i],tailTable[len-1]);
            tailTable[len++] = A[i];
        }
        else{
            // A[i] wants to be current end candidate of an existing subsequence
            // It will replace ceil value in tailTable
            // printf("HERE %d\n",CeilIndex(-1, len-1, A[i]));
            tailTable[CeilIndex(-1, len-1, A[i])] = A[i];
            // tailTable[len-1] = A[i];
        }
    }
 
    // delete[] tailTable;
 
    return len;
}
int main () {
  scanf("%lli %lli", &n, &d);

  for (int i = 0; i < n; i++) {
    scanf("%lli", &A[i]);
  }
  // LongestIncreasingSubsequence(n);
  printf("%d\n",LongestIncreasingSubsequenceLength(n));
}