#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> ppi;

const int maxn = 1007;
const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};

int n, m;
int f[maxn][maxn];
int d[maxn][maxn];
char ma[maxn][maxn];

void bfs() {
    memset(f, 0x3f3f, sizeof f);
    queue<pii> que;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (ma[i][j] == 'F') {
                f[i][j] = 1;
                que.push(pii(i, j));
            }
        }
    }
    while (!que.empty()) {
        int x = que.front().first, y = que.front().second;
        que.pop();
        for (int i = 0; i < 4; ++i) {
            int tx = x + dx[i];
            int ty = y + dy[i];
            if (tx < 1 || tx > n || ty < 1 || ty > m || ma[tx][ty] == '#') continue;
            if (f[x][y] + 1 < f[tx][ty]) {
                f[tx][ty] = f[x][y] + 1;
                que.push(pii(tx, ty));
            }
        }
    }
}

int bfs(int x, int y) {
    memset(d, -1, sizeof d);
    queue<pii> que;
    que.push(pii(x, y));
    d[x][y] = 1;

    while (!que.empty()) {
        x = que.front().first, y = que.front().second;
        que.pop();
        if (x == 1 || x == n || y == 1 || y == m) return d[x][y];
        for (int i = 0; i < 4; ++i) {
            int tx = x + dx[i];
            int ty = y + dy[i];
            if (tx < 1 || tx > n || ty < 1 || ty > m || ma[tx][ty] == '#' || f[tx][ty] <= d[x][y] + 1) continue;
            if (d[tx][ty] == -1) {
                d[tx][ty] = d[x][y] + 1;
                que.push(pii(tx, ty));
            }
        }
    }
    return -1;
}

int main(){
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; ++i) scanf("%s", ma[i] + 1);
        bfs();
        int ans;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (ma[i][j] == 'J') ans = bfs(i, j);
            }
        }
        if (ans == -1) printf("IMPOSSIBLE\n");
        else printf("%d\n", ans);
    }
    return 0;
}
