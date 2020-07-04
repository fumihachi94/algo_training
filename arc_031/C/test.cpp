#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
#define ll long long
#define ld long double
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repo(i,n) for(int i = 1; i < (int)(n); i++)
#define pb push_back
#define mp make_pair
#define np next_permutation
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define uniq(v) v.erase(unique(v.begin(),v.end()),v.end())
#define lb(v,x) (lower_bound(v.begin(),v.end(),x)-v.begin())
#define ub(v,x) (upper_bound(v.begin(),v.end(),x)-v.begin())
const ll mod=1000000007;
//const ll mod=998244353;
const ld pi=acos(-1.0);
const ll INF = 1LL<<61;
template<class T>bool chmax(T &a, const T &b) { 
  if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) {
  if (b<a) { a=b; return 1; } return 0; }
ll gcd(ll x, ll y) { return y ? gcd(y, x % y) : x; }
ll lcm(ll x, ll y) { return x / gcd(x, y) * y; }
ll jou(ll N, ll P){if(P==0) return 1;
  if(P%2==0){ll t = jou(N, P/2);return t*t % mod;
  }return (N * jou(N, P-1)) % mod;}  //jou(n,mod-2)で逆元
//intの最大値2147483647 ≒ 2×10^9
//long longの最大値9223372036854775807 ≒ 9×10^18
//'大文字'+=32;    で小文字に
//  cout << fixed << setprecision (20);   小数点以下2０桁まで
//実行時間制約2秒では２×10^8回くらいまで計算できる



//————————Fenwick  BIT  転倒数———————————————————————

template<typename T>
class BIT{
  public:
    int N;
    vector<T> data;
    BIT(T _N):N(_N){
        data.assign(N+1, 0);
    };
    
    // a is 1-indexed
    void add(int a, T w){
        for(int x = a; x <= N; x += x & -x) data[x] += w;
    }
    // 1-indexed sum of prefix [0, a]
    T sum(int a){
        T res = 0;
        for(int x = a; x > 0; x -= x & -x) res += data[x];
        return res;
    }
    // 1-indexed sum of range [l, r]
    T sum(int l, int r){return sum(r) - sum(l-1);}

    // 0-indexed add
    void add0(int a, T w){add(a + 1, w);}
    // 0-indexed sum
    T sum0(int a){return sum(a + 1);}
    // 0-indexed sum of range
    T sum0(int l, int r){return sum0(r) - sum0(l-1);}

    //1-indexed でv1+v2+...+vx >= w となる最小のx
    T blb(T w) {
      if(w <= 0) return 0;
      int res = 0;
      int i=1;
      while(i*2 <= N) {i *= 2;}
      //i は N以下の最大の２べき
      for(int k = i; k > 0; k /= 2) {
        if(res + k <= N && data[res + k] < w) {
          w -= data[res + k];
          res += k;
        }
      }
      return res+1;
    }

    /* debug */
    void print() {
        rep(i,N) cout << sum0(i,i) << ",";
        cout << endl;
    }

};



int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin>>n;

  vector<ll> p(n);
  rep(i,n){
    cin>>p[i];
  }

    //qに座標圧縮
    vector<ll> q(n);
    vector<pair<ll, int>> vp;    
    rep(i,n){
      vp.pb(mp(p[i], i));
    }
    sort(all(vp));
    rep(i,n) q[i]=vp[i].se;

  BIT<ll> bit(n);
  rep(i,n){
    bit.add0(i,1);
  }
  ll ans=0;
  rep(i,n){
      if(q[i]!=0) ans+=max(min(bit.sum0(q[i]-1),n-i-1-bit.sum0(q[i]-1)),0ll);
      bit.add0(q[i],-1);
  }

  cout << ans << endl;
}
