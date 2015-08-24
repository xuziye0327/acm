#include <iostream>
#include <queue>
#include <cstring>
#include <cstdio>

using namespace std;

typedef pair<int, int> P;
typedef pair<P, int> PP;

const int inf = 1 << 30;
const int maxn = 20 + 7;
const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};

int m, n, k;
int d[maxn][maxn];
int ma[maxn][maxn];

void init() {
    memset(ma, 0, sizeof(ma));
    for(int i = 0; i < maxn; ++i) {
        for(int j = 0; j < maxn; ++j) {
            d[i][j] = inf;
        }
    }
    d[1][1] = 0;
}

void bfs() {
    queue<PP> que;
    while(!que.empty()) que.pop();
    que.push(make_pair(make_pair(1, 1), k));

    while(!que.empty()) {
        int x = que.front().first.first, y = que.front().first.second;
        int kk = que.front().second;
        que.pop();
        for(int i = 0; i < 4; ++i) {
            int tx = x + dx[i], ty = y + dy[i];
            if(tx >= 1 && tx <= m && ty >= 1 && ty <= n) {
                if(!ma[tx][ty] && d[tx][ty] >= d[x][y] + 1) {
                    d[tx][ty] = d[x][y] + 1;
                    que.push(make_pair(make_pair(tx, ty), k));
                } else if(ma[tx][ty] && kk - 1 >= 0 && d[tx][ty] >= d[x][y] + 1) {
                    d[tx][ty] = d[x][y] + 1;
                    que.push(make_pair(make_pair(tx, ty), kk - 1));
                }
            }
        }
    }
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        init();
        scanf("%d%d%d", &m, &n, &k);
        for(int i = 1; i <= m; ++i) {
            for(int j = 1; j <= n; ++j) {
                scanf("%d", &ma[i][j]);
            }
        }
        bfs();
        printf("%d\n", d[m][n] >= inf ? -1 : d[m][n]);
    }
    return 0;
}