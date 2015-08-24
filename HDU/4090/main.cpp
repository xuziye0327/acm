#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <cstring>
#include <map>

using namespace std;

typedef pair<int, int> P;
typedef unsigned long long ull;

const ull base = 31;
const int maxn = 8 + 7;
const int dx[] = {0, 0, 1, -1, 1, 1, -1, -1};
const int dy[] = {1, -1, 0, 0, 1, -1, 1, -1};

int n, m, k, ans;
int ma[maxn][maxn];
int temp[maxn * 100][maxn][maxn];
map<ull, int> hashmap;
bool used[maxn][maxn];

struct point {
    int x, y;
};

int bfs1(int x, int y) {
    memset(used, false, sizeof(used));
    point p;
    p.x = x; p.y = y;
    int cnt(0), num(ma[x][y]);
    queue<point> que;
    que.push(p);
    used[x][y] = true;

    while(!que.empty()) {
        ++cnt;
        x = que.front().x, y = que.front().y;
        que.pop();
        for(int i = 0; i < 8; ++i) {
            int tx = x + dx[i], ty = y + dy[i];
            if(tx >= 1 && tx <= n && ty >= 1 && ty <= m) {
                if(used[tx][ty]) continue;
                if(ma[tx][ty] != num) continue;
                used[tx][ty] = true;
                p.x = tx; p.y = ty;
                que.push(p);
            }
        }
    }

    return cnt;
}

int bfs2(int x, int y) {
    memset(used, false, sizeof(used));
    point p;
    p.x = x; p.y = y;
    int cnt(0), num(ma[x][y]);
    queue<point> que;
    que.push(p);
    used[x][y] = true;

    while(!que.empty()) {
        ++cnt;
        x = que.front().x, y = que.front().y;
        que.pop();
        ma[x][y] = 0;
        for(int i = 0; i < 8; ++i) {
            int tx = x + dx[i], ty = y + dy[i];
            if(tx >= 1 && tx <= n && ty >= 1 && ty <= m) {
                if(used[tx][ty]) continue;
                if(ma[tx][ty] != num) continue;
                used[tx][ty] = true;
                p.x = tx; p.y = ty;
                que.push(p);
            }
        }
    }

    for(int i = 1; i <= m; ++i) {
        for(int j = n - 1; j >= 1; --j) {
            if(!ma[j][i]) continue;
            int pos = j;
            while(pos < n && !ma[pos + 1][i]) {
                ma[pos + 1][i] = ma[pos][i];
                ma[pos++][i] = 0;
            }
        }
    }

    for(int i = 2; i <= m; ++i) {
        int pos = i;
        while(pos > 1 && !ma[n][pos - 1]) {
            for(int j = 1; j <= n; ++j) {
                ma[j][pos - 1] = ma[j][pos];
                ma[j][pos] = 0;
            }
            --pos;
        }
    }

    return cnt * cnt;
}

int c() {
    int res(0);
    int cnt[10];
    memset(cnt, 0, sizeof(cnt));
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            ++cnt[ma[i][j]];
        }
    }
    for(int i = 1; i <= k; ++i) {
        res += cnt[i] * cnt[i];
    }
    return res;
}

ull gethash() {
    ull nbase(1);
    ull res(0);
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            res += nbase * ma[i][j];
            nbase *= base;
        }
    }
    return res;
}

void dfs(int x, int y, int sco, int d) {
    bool ok = true;
    sco += bfs2(x, y);
    memcpy(temp[d], ma, sizeof(ma));

    if(sco + c() <= ans) return ;

    ull sta = gethash();
    if(hashmap.count(sta) && hashmap[sta] >= sco) return ;
    else hashmap[sta] = sco;

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            if(ma[i][j] && bfs1(i, j) >= 3) {
                if(ma[i][j] == ma[i - 1][j] || ma[i][j] == ma[i - 1][j - 1] || ma[i][j] == ma[i - 1][j + 1] || ma[i][j] == ma[i][j - 1]) {
                    continue;
                }
                ok = false;
                dfs(i, j, sco, d + 1);
                memcpy(ma, temp[d], sizeof(ma));
            }
        }
    }

    if(ok) ans = max(ans, sco);
}

int main() {
    while(~scanf("%d%d%d", &n, &m, &k)) {
        ans = 0;
        hashmap.clear();
        for(int i = 1; i <= n; ++i) for(int j = 1; j <= m; ++j) scanf("%d", &ma[i][j]);
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= m; ++j) {
                if(ma[i][j] && bfs1(i, j) >= 3) {
                    if(ma[i][j] == ma[i - 1][j] || ma[i][j] == ma[i - 1][j - 1] || ma[i][j] == ma[i - 1][j + 1] || ma[i][j] == ma[i][j - 1]) {
                        continue;
                    }
                    if(c() <= ans) continue;
                    memcpy(temp[0], ma, sizeof(ma));
                    dfs(i, j, 0, 1);
                    memcpy(ma, temp[0], sizeof(ma));
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}