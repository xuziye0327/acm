#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> ppi;

const int maxn = 107;
const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};

int n, m, t;
int d[maxn][maxn][1 << 6];
char ma[maxn][maxn];

int get_bit(int ch) {
    if (tolower(ch) == 'b') return 0;
    if (tolower(ch) == 'y') return 1;
    if (tolower(ch) == 'r') return 2;
    if (tolower(ch) == 'g') return 3;
}

int bfs(int x, int y) {
    memset(d, -1, sizeof d);
    queue<ppi> que;
    d[x][y][0] = 0;
    que.push(ppi(pii(x, y), 0));
    while (!que.empty()) {
        x = que.front().first.first, y = que.front().first.second;
        int sta = que.front().second;
//        cout << "x = " << x << ", y = " << y << ", sta = " << sta << ", d = " << d[x][y][sta] << endl;
        que.pop();
        if (ma[x][y] == 'X') return d[x][y][sta];
        for (int i = 0; i < 4; ++i) {
            int tx = x + dx[i];
            int ty = y + dy[i];
            if (tx < 1 || tx > n || ty < 1 || ty > m || ma[tx][ty] == '#') continue;
            if (ma[tx][ty] >= 'A' && ma[tx][ty] <= 'Z' && ma[tx][ty] != 'X') {
                int b = get_bit(ma[tx][ty]);
                if ((sta >> b) & 1) {
                    if (d[tx][ty][sta] == -1) {
                        d[tx][ty][sta] = d[x][y][sta] + 1;
                        que.push(ppi(pii(tx, ty), sta));
                    }
                }
            } else if (ma[tx][ty] >= 'a' && ma[tx][ty] <= 'z') {
                int b = get_bit(ma[tx][ty]);
                if (d[tx][ty][sta | (1 << b)] == -1) {
                    d[tx][ty][sta | (1 << b)] = d[x][y][sta] + 1;
                    que.push(ppi(pii(tx, ty), sta | (1 << b)));
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
    while (scanf("%d%d", &n, &m) && n) {
        for (int i = 1; i <= n; ++i) scanf("%s", ma[i] + 1);
        int ans;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (ma[i][j] == '*') ans = bfs(i, j);
            }
        }
        if (ans == -1) {
            printf("The poor student is trapped!\n");
        } else {
            printf("Escape possible in %d steps.\n", ans);
        }
    }
    return 0;
}
