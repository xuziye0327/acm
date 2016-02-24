### 题目链接
<a href="http://poj.org/problem?id=2486">HERE</a>

### 题目描述
一棵树，n个点，每个点有x个苹果，一妹子只能走k步，问她最多能吃多少个苹果。

### 解题思路
乍看上去就是个背包。可是嘞，弱菜还不是会。
dp做的少，完全没有头绪，看了题解才做出来。
设d[i][j][0]表示在i点走j步后回到i点得到的最大的数量。其中在i的son中走了k步。则d[i][j][0]=d[i][j-k][0]+d[son][k-2][0]。k-2是因为从i到k，然后从k回到i需要减去的两步。
设d[i][j][1]表示在i点走j步后不会到i的得到的最大数量。这个状态分两种情况。先在i点走过的son中走j-k步，回到i，再在当前son中走k步，不回到i。即d[i][j][1]=d[i][j-k][0]+d[son][k-1][1]。这里k-1是因为不再从son走到i了；剩下的一种情况就是反过来，走完当前son再走其它的son。d[i][j][1]=d[i][j-k][1]+d[son][k-2][0]。

``` cpp
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
```