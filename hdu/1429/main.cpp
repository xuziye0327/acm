#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> ppi;

const int maxn = 27;
const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};

int n, m, t;
char ma[maxn][maxn];
int vis[maxn][maxn];

bool bfs(int x, int y) {
    memset(vis, -1, sizeof vis);
    vis[x][y] = 0;
    queue<pii> que;
    que.push(pii(x, y));
    while (!que.empty()) {
        x = que.front().first, y = que.front().second;
        que.pop();
        if (vis[x][y] >= t && ma[x][y] == '^') return false;
        for (int i = 0; i < 4; ++i) {
            int tx = x + dx[i];
            int ty = y + dy[i];
            if (tx < 1 || tx > n || ty < 1 || ty > m || ma[tx][ty] == '*') continue;
            if (vis[tx][ty] == -1) {
                vis[tx][ty] = vis[x][y] + 1;
                que.push(pii(tx, ty));
            }
        }
    }
    return true;
}

int d[maxn][maxn][1 << 11];

int bfs(int x, int y, const int sx, const int sy) {
    memset(d, -1, sizeof d);
    d[x][y][0] = 0;
    queue<ppi> que;
    que.push(ppi(pii(x, y), 0));
    while (!que.empty()) {
        int x = que.front().first.first, y = que.front().first.second;
        int sta = que.front().second;
        que.pop();
        if (ma[x][y] == '^') return d[x][y][sta];
        if ((d[x][y][sta] + 1) % t == 0) {
            continue;
        }
        for (int i = 0; i < 4; ++i) {
            int tx = x + dx[i];
            int ty = y + dy[i];
            if (tx < 1 || tx > n || ty < 1 || ty > m || ma[tx][ty] == '*') continue;
            if (ma[tx][ty] >= 'A' && ma[tx][ty] <= 'J') {
                if (d[tx][ty][sta] == -1 && ((sta >> (ma[tx][ty] - 'A')) & 1)) {
                    d[tx][ty][sta] = d[x][y][sta] + 1;
                    que.push(ppi(pii(tx, ty), sta));
                }
            } else if (ma[tx][ty] >= 'a' && ma[tx][ty] <= 'j') {
                if (d[tx][ty][sta | (1 << (ma[tx][ty] - 'a'))] == -1) {
                    d[tx][ty][sta | (1 << (ma[tx][ty] - 'a'))] = d[x][y][sta] + 1;
                    que.push(ppi(pii(tx, ty), sta | (1 << (ma[tx][ty] - 'a'))));
                }
            } else if (d[tx][ty][sta] == -1) {
                d[tx][ty][sta] = d[x][y][sta] + 1;
                que.push(ppi(pii(tx, ty), sta));
            }

        }
    }
    return -1;
}

int main(){
    while (~scanf("%d%d%d", &n, &m, &t)) {
        for (int i = 1; i <= n; ++i) scanf("%s", ma[i] + 1);
        bool flag = true;
        if (!flag) printf("-1\n");
        else {
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= m; ++j) {
                    if (ma[i][j] == '@') printf("%d\n", bfs(i, j, i, j));
                }
            }
        }
    }
    return 0;
}
