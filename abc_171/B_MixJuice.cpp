#include <memory>
#include <iostream>
using namespace std;

int main(void){
    
    int N, K, ans=0;

    cin >> N >> K;

    std::shared_ptr<int> p(new int[N], std::default_delete<int[]>());

    for(int i=0; i<N; i++){
        cin >> p.get()[i];
    }

    for(int j=0; j<K; j++){
        int pmin = 1001;
        int num = 0;
        for(int i=0;i<N; i++){
            if(p.get()[i]<pmin && p.get()[i]!=0){
                pmin = p.get()[i];
                num = i;
            }
        }
        ans += pmin;
        p.get()[num] = 0;
    }

    cout << ans << endl;

    return 0;
}

/*
Input 例
5 4 
10 20 11 23 40
*/