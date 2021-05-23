// AtCoder Beginner Contest 190
// D - Staircase Sequences
// https://atcoder.jp/contests/abc190/tasks/abc190_d
//
// @fumiya_sato

#include <iostream>
#include <math.h>

typedef long long ll;
using namespace std;

int main(void){
  ulong N, ans=0;
  cin >> N;

  uint sz = uint((sqrt(1+8*N)-1)/2)+1;
  cout << "size : " << sz << endl;
  ulong sum_tmp[sz] = {0};
  ulong st = 0;
  uint count = 0;

  for(ulong n=0; n<N; n++){
    for(ulong m=0; m<=n; m++){
      uint k = m%sz;
      cout << k << ", ";
      sum_tmp[k] += n+1;
      if(sum_tmp[k] == N) {
        count++;
        // cout << k << ":" << sum_tmp[k] <<endl;
      } 
      if(sum_tmp[k] >= N){
        sum_tmp[k] = 0;
      }
    }
  }

  // for(ulong n=0; n<N; n++){
  //   cout << n+1 << ":" << sum_tmp[n] << endl;
  // }

  cout << "ans=" << count*2 << endl;

  return 0;
}