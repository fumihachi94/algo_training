#include<bits/stdc++.h>

using namespace std;
using ll = long long;

template<class T> 
class SegTree{

    private:

        int n;
        int m;
        int depth;
        T def;
        vector<T> data;
        function<T(T,T)> calculate;
        function<T(T,T)> update;

        T rec(int l, int r, int node, int node_l, int node_r) {
            if (node_r <= l || node_l >= r) return def;
            if (node_l >= l && node_r <= r) return data[node];
            int mid = (node_l + node_r) / 2;
            return calculate(
                rec(l, r, node * 2, node_l, mid),
                rec(l, r, node * 2 + 1, mid, node_r));
        }

        void _assign(int index, T val){
            index += n;
            data[index] = update(data[index], val);
            for(;index /= 2;)
                data[index] = calculate(data[index * 2],data[index * 2 + 1]);
        }

        void _print() {
            cerr << "[";
            for(int i = 0; i < m; i++) {
                cerr << data[i + n] << (i != m - 1 ? "," : "]\n");
            }
        }

        void _show() {
            vector<string> res(depth + 1);
            vector<int> width(depth + 1);
            width[depth-1] = 3;
            for(int i = depth-2; i >= 0; i--)width[i] = width[i + 1] * 2 + 2;

            for(int i = 0; i < depth; i++) {
                int start = 1<<i, end = 1<<(i + 1);
                for(int j = start; j < end; j++) {
                    int d = 0, cur = (data[j] == 0 ? 1 : data[j]);
                    while(cur){cur/=10,d++;}
                    int wid = width[i] - d;
                    cerr << '[' << right << string(wid/2,' ') << data[j] << string(wid - wid/2, ' ') << ']';
                }
                cerr << endl;
            }
        }

        int _lower_right(int index, T val) {
            int lef = index, rig = n; //ooooxx
            while(rig - lef > 1) {
                int mid = (rig + lef) / 2;
                (get(index, mid) < val ? lef : rig) = mid;
            }
            return rig;
        }

        int _upper_right(int index, T val) {
            int lef = index, rig = n; //ooooxx
            while(rig - lef > 1) {
                int mid = (rig + lef) / 2;
                (get(index, mid) <= val ? lef : rig) = mid;
            }
            return rig;
        }

    public:


        SegTree(vector<T> a, T _def, function<T(T,T)> _calculate, function<T(T,T)> _update):
        def(_def), calculate(_calculate), update(_update) {
            m = a.size();
            for (n = 1; n < (int) a.size(); n *= 2, depth++);
            data.resize(n * 2, def);
            for (int i = 0; i < (int) a.size(); i++) data[i + n] = a[i];
            for (int i = n - 1; i >= 1; i--)
                data[i] = calculate(data[i * 2], data[i * 2 + 1]);
        }
        

        //区間取得
        T get(int l,int r){
            if(l == r)return def;
            return rec(l,r,1,0,n);
        }
        
        //一点更新
        void assign(int index, T val){
            _assign(index, val);
        }

        void print() {
            _print();
        }

        void show() {
            _show();
        }

        T operator[] (int i){
            return data[i + n];
        }

        //get(index, right) >= valとなるような最小のright 
        int lower_right(int index, T val) {
            return _lower_right(index, val);
        }

        //get(index, right) > valとなるような最小のright
        int upper_right(int index, T val) {
            return _upper_right(index, val);
        }

};


int main()
{
    int n; cin >> n;
    vector<pair<int,int>> a(n); //val : index;
    for(int i = 0; i < n; i++) {
        int t; cin >> t;
        a[i] = {t, i};
    }
    sort(a.begin(), a.end());
    SegTree<int> tree(vector<int>(n, 1), 0, [](int a, int b){return a + b;}, [](int a, int b){return b;});

    ll ans = 0;
    for(int i = 0; i < n; i++) {
        int ind = a[i].second;
        ans += min(tree.get(ind + 1, n), tree.get(0, ind));
        tree.assign(ind, 0);
    }
    cout << ans << endl;

}
