#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = 107;

int n, k;
int a[maxn];
int d[maxn][maxn * 2][2];
vector<int> G[maxn];

void init() {
    memset(a, 0, sizeof(a));
    memset(d, 0, sizeof(d));
    for (int i = 0; i < maxn; ++i) G[i].clear();
}

void dfs(int root, int pa) {
    for (int i = 0; i <= k; ++i) {
        d[root][i][0] = d[root][i][1] = a[root];
    }

    for (int u = 0; u < G[root].size(); ++u) {
        int v = G[root][u];
        if (v == pa) continue;

        dfs(v, root);

        for (int i = k; i >= 1; --i) {
            for (int j = 1; j <= i; ++j) {
                if (j >= 2) {
                    d[root][i][0] = max(d[root][i][0], d[root][i - j][0] + d[v][j - 2][0]);
                    d[root][i][1] = max(d[root][i][1], d[root][i - j][1] + d[v][j - 2][0]);
                }
                d[root][i][1] = max(d[root][i][1], d[root][i - j][0] + d[v][j - 1][1]);
            }
        }
    }
}

int main() {
    while (~scanf("%d%d", &n, &k)) {
        init();
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &a[i]);
        }
        for (int i = 1; i < n; ++i) {
            int u, v;
            scanf("%d%d", &u, &v);
            G[u].push_back(v);
            G[v].push_back(u);
        }

        dfs(1, 1);

        printf("%d\n", max(d[1][k][0], d[1][k][1]));
    }
    return 0;
}
