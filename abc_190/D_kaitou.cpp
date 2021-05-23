#include <iostream>
#include <cmath>
using namespace std;
using ll = int64_t;
int main(){
    ll N;
    cin >> N;
    while(N % 2 == 0) N /= 2;
    ll sq = sqrt(N), ans = 0;
    for(ll i = 1; i <= sq; i+=2) if(N % i == 0) ans += 2;
    if(sq * sq == N) ans--;
    cout << ans * 2 << endl;
}