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
	ifstream in("input.txt");
	cin.rdbuf(in.rdbuf());
	
	ll dst[3]{};

	for(int i=0; i<3; i++){
		cin >> N;
        vector<pair<int, int>> B(N);
        int p;
		for(int n=0; n<N; n++){
			cin >> p;
            B[n] = make_pair(p, n+1);
            // bit[n+1] = 1;
            add(B[n].first, 1);
            // cout << B[n].first << " ";
		}

        sort(B.begin(), B.end());

        // cout <<  endl;
        // for(int n=1; n<=N; n++) cout << bit[n] << " ";

        // cout << endl;
        for (int n = 0; n < N; ++n){
            int range_l = sum(B[n].second) -1;
            dst[i] += min(range_l, sum(N) -1 - range_l);
            add(B[n].second, -1);
        }
        // for(int n=1; n<=N; n++) cout << bit[n] << " ";
        // cout << endl;
        // cout << dst[i] << endl;
	}

    // 答え合わせ
	ifstream an("answer.txt");
	cin.rdbuf(an.rdbuf());
	for(int i=0; i<3; i++){
		int ans;
		cin >> ans;
		cout << "No." << i << ": " << dst[i];
		if(dst[i]==ans) cout <<  " " << "OK\n";
		else cout << " " << "NG\n";
	}
    
	return 0;
}	