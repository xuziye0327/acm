#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> ppi;
typedef pair<pii, pii> ppp;

const int maxn = 27;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

const int to_left[] = {2, 3, 1, 0};
const int to_right[] = {3, 2, 0, 1};

int n, m;
int d[maxn][maxn][4][5];
char ma[maxn][maxn];

/**
0 N
1 S
2 W
3 E
**/
int bfs(int x, int y) {
    memset(d, 0x3f3f3f, sizeof d);
    d[x][y][0][0] = 0;
    queue<ppp> que;
    que.push(ppp(pii(x, y), pii(0, 0)));

    while (!que.empty()) {
        x = que.front().first.first, y = que.front().first.second;
        int dir = que.front().second.first, col = que.front().second.second;
        que.pop();
        if (ma[x][y] == 'T' && col == 0) return d[x][y][dir][col];
        if (d[x][y][to_left[dir]][col] > d[x][y][dir][col] + 1) {
            d[x][y][to_left[dir]][col] = d[x][y][dir][col] + 1;
            que.push(ppp(pii(x, y), pii(to_left[dir], col)));
        }
        if (d[x][y][to_right[dir]][col] > d[x][y][dir][col] + 1) {
            d[x][y][to_right[dir]][col] = d[x][y][dir][col] + 1;
            que.push(ppp(pii(x, y), pii(to_right[dir], col)));
        }
        if (x + dx[dir] < 1 || x + dx[dir] > n || y + dy[dir] < 1 || y + dy[dir] > m || ma[x + dx[dir]][y + dy[dir]] == '#') continue;
        if (d[x + dx[dir]][y + dy[dir]][dir][(col + 1) % 5] > d[x][y][dir][col] + 1) {
            d[x + dx[dir]][y + dy[dir]][dir][(col + 1) % 5] = d[x][y][dir][col] + 1;
            que.push(ppp(pii(x + dx[dir], y + dy[dir]), pii(dir, (col + 1) % 5)));
        }
    }
    return -1;
}

int main(){
    int Case(0);
    while (scanf("%d%d", &n, &m) && n) {
        for (int i = 1; i <= n; ++i) scanf("%s", ma[i] + 1);
        int ans;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (ma[i][j] == 'S') ans = bfs(i, j);
            }
        }
        if (Case) printf("\n");
        printf("Case #%d\n", ++Case);
        if (ans == -1) printf("destination not reachable\n");
        else printf("minimum time = %d sec\n", ans);
    }
    return 0;
}
