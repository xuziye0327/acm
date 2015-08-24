#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int maxn = 40 + 7;

struct point {
    int x, y;
};

struct line {
    int x1, y1, x2, y2;
    int dis;
    bool operator < (const line &k) const {
        if(dis != k.dis) return dis < k.dis;
        else if(x1 != k.x1) return x1 < k.x1;
        else if(y1 != k.y1) return y1 < k.y1;
        else if(x2 != k.x2) return x2 < k.x2;
        return y2 < k.y2;
    }
}l[maxn * maxn * maxn * maxn];

char isl[maxn][maxn];
vector<point> C, H;

int main() {
    int M, N;
    while(~scanf("%d%d", &M, &N) && M) {
        C.clear();
        H.clear();
        for(int i = 0; i < M; ++i)
            scanf("%s", isl[i]);
        for(int i = 0; i < M; ++i) {
            for(int j = 0; j < N; ++j) {
                point t;
                t.x = i; t.y = j;
                if(isl[i][j] == 'C') C.push_back(t);
                else if(isl[i][j] == 'H') H.push_back(t);
            }
        }
        int cnt(0);
        for(int i = 0; i < H.size(); ++i) {
            for(int j = 0; j < C.size(); ++j) {
                l[cnt].x1 = H[i].x; l[cnt].y1 = H[i].y;
                l[cnt].x2 = C[j].x; l[cnt].y2 = C[j].y;
                l[cnt].dis = abs(l[cnt].x1 - l[cnt].x2) + abs(l[cnt].y1 - l[cnt].y2);
                ++cnt;
            }
        }
        sort(l, l + cnt);
        printf("%d %d %d %d\n", l[0].x1, l[0].y1, l[0].x2, l[0].y2);
    }
    return 0;
}