#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm> 
#include <map>
using namespace std; 
#define ll long long

int N;
int bit[100010];

void add(int a, int w) {
    for (int x = a; x <= N; x += x & -x) bit[x] += w;
}

int sum(int a) {
    int ret = 0;
    for (int x = a; x > 0; x -= x & -x) ret += bit[x];
    return ret;
}


int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int p;
  ll ans=0;
  
  cin >> N;
  vector<pair<int, int>> B(N);
  
  for(int n=0; n<N; n++){
    cin >> p;
    B[n] = make_pair(p, n+1);
    add(B[n].first, 1);
   }
  
  sort(B.begin(), B.end());
  
  for (int n = 0; n < N; ++n){
    int range_l = sum(B[n].second) -1;
    ans += min(range_l, sum(N) -1 - range_l);
    add(B[n].second, -1);
  }
  cout << ans << endl;
  
  return 0;
}	