#include <vector>
#include <iostream>
using namespace std;

#define N 10

struct point{
    int x, y;
    point(int x, int y) : x(x), y(y) {}
};

int detectIsland(int x, int y, bool (&D)[N][N], vector<point> &V){
    V.push_back(point(x, y));
    D[y][x] = 1;
    return 1;
}

int landfill(int x, int y, int (&A)[N][N]){

    vector<point> v = {point(x,y)};
    bool D[N][N]{};
    int count = 0;

    while(!v.empty()){
        point p = v.front();
        v.erase(v.begin());

        if(p.y>0   & A[p.y-1][p.x] == 1 & !D[p.y-1][p.x]) count += detectIsland(p.x,   p.y-1, D, v);
        if(p.y<N-1 & A[p.y+1][p.x] == 1 & !D[p.y+1][p.x]) count += detectIsland(p.x,   p.y+1, D, v);
        if(p.x>0   & A[p.y][p.x-1] == 1 & !D[p.y][p.x-1]) count += detectIsland(p.x-1, p.y,   D, v);
        if(p.x<N-1 & A[p.y][p.x+1] == 1 & !D[p.y][p.x+1]) count += detectIsland(p.x+1, p.y,   D, v);
    }

    vector<point>().swap(v);

    return count;
}

int main(void){
    int a[N][N]{};
    int num_island=0;

    for(int y=0; y<N; y++){
        for(int x=0; x<N; x++){
            char p;
            cin >> p;
            a[y][x] = p == 'o' ? 1 : 0 ; 
            num_island += p == 'o' ? 1 : 0 ;
        }
    }

    for(int y=0; y<N; y++){
        for(int x=0; x<N; x++){
            if(!a[y][x] & landfill(x,y,a)==num_island){
                std::cout << "YES" << endl;
                return 0;
            }
        }
    }

    std::cout << "NO" <<endl;

    return 0;
}