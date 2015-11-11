### 题目链接
<a href="http://www.lydsy.com/JudgeOnline/problem.php?id=2038">HERE</a>

### 题目描述
中文题就不描述了- -

### 解题思路
传说中的莫队算法。
求出曼哈顿距离最小生成树，根据生成树的树边计算。时间复杂度O(n^1.5)。

``` cpp
#include <cstdio>
#include <algorithm>
#include <cstring>
#define HERE printf("HERE!\n")

using namespace std;

typedef long long ll;

const int maxn = 50007;
const int  inf = 1 << 27;

struct Point {
    int x, y, id;
    bool operator < (const Point& p) const {
        return x != p.x ? x < p.x : y < p.y;
    }
} p[maxn], b[maxn], temp[maxn];

struct Edge {
    int u, v, cost;
    Edge() { }
    Edge(int _u, int _v, int _cost) : u(_u), v(_v), cost(_cost) { }
    bool operator < (const Edge& e) const {
        return cost < e.cost;
    }
}edges[maxn * 10];

struct linkEdge {
    int next, node;
}ledges[maxn * 10];

int k, ecnt, cur;
int t[maxn], f[maxn], fa[maxn];
int cor[maxn];
int cost[maxn];
int head[maxn];
ll c[maxn], ans[maxn];
bool vis[maxn];

int query(int pos) {
    int ret = 0;
    for ( ; pos < maxn; pos += pos & -pos)
        if (cost[ret] > cost[t[pos]]) ret = t[pos];
    return ret;
}

void update(int pos, int val) {
    for ( ; pos; pos -= pos & -pos)
        if (cost[t[pos]] > cost[val]) t[pos] = val;
}

void addEdge(int u, int v, int cost) {
    edges[k++] = Edge(u, v, cost);
    edges[k++] = Edge(v, u, cost);
}

int findFa(int x) { return x == fa[x] ? x : fa[x] = findFa(fa[x]); }

void addLedge(int u, int v) {
    ledges[++ecnt].next = head[u];
    head[u] = ecnt; ledges[ecnt].node = v;
}

void add(int l, int r) {
    for (int i = l; i <= r; ++i) {
        cur -= c[cor[i]] * (c[cor[i]] - 1ll);
        ++c[cor[i]];
        cur += c[cor[i]] * (c[cor[i]] - 1ll);
    }
}

void mul(int l, int r) {
    for (int i = l; i <= r; ++i) {
        cur -= c[cor[i]] * (c[cor[i]] - 1ll);
        --c[cor[i]];
        cur += c[cor[i]] * (c[cor[i]] - 1ll);
    }
}

void dfs(int x, int l, int r) {
    vis[x] = true;
    if (r < temp[x].y) {
        add(r + 1, temp[x].y);
    }
    if (r > temp[x].y) {
        mul(temp[x].y + 1, r);
    }
    if (l > temp[x].x) {
        add(temp[x].x, l - 1);
    }
    if (l < temp[x].x) {
        mul(l, temp[x].x - 1);
    }
    ans[x] = cur;
    for (int i = head[x]; i; i = ledges[i].next) {
        linkEdge e = ledges[i];
        if (vis[e.node]) continue;
        dfs(e.node, temp[x].x, temp[x].y);
    }
    if (r < temp[x].y) {
        mul(r + 1, temp[x].y);
    }
    if (r > temp[x].y) {
        add(temp[x].y + 1, r);
    }
    if (l > temp[x].x) {
        mul(temp[x].x, l - 1);
    }
    if (l < temp[x].x) {
        add(l, temp[x].x - 1);
    }
}

ll gcd(ll x, ll y) { return y == 0 ? x : gcd(y, x % y); }

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &cor[i]);
    }
    for (int i = 1; i <= m; ++i) {
        scanf("%d%d", &p[i].x, &p[i].y);
        p[i].id = i;
        temp[i] = p[i];
    }
    k = 0;
    for (int dir = 1; dir <= 4; ++dir) {
        if (dir == 2 || dir == 4)
            for (int i = 1; i <= m; ++i)
                swap(p[i].x, p[i].y);
        if (dir == 3)
            for (int i = 1; i <= m; ++i)
                p[i].x *= -1;
        sort(p + 1, p + 1 + m);
        for (int i = 1; i <= m; ++i) {
            b[i].x = p[i].y - p[i].x;
            b[i].y = i;
            cost[i] = p[i].x + p[i].y;
        }
        cost[0] = inf;
        sort(b + 1, b + 1 + m);
        for (int i = 1; i <= m; ++i) f[b[i].y] = i;
        memset(t, 0, sizeof(t));
        for (int i = m; i > 0; --i) {
            int x;
            if (x = query(f[i])) addEdge(p[x].id, p[i].id, cost[x] - cost[i]);
            update(f[i], i);
        }
    }
    for (int i = 1; i <= m; ++i) p[i].y *= -1;
    sort(edges, edges + k);
    for (int i = 0; i < maxn; ++i) fa[i] = i;
    for (int i = 0; i < k; ++i) {
        Edge e = edges[i];
        int px = findFa(e.u);
        int py = findFa(e.v);
        if (px != py) {
            addLedge(e.u, e.v);
            addLedge(e.v, e.u);
            fa[px] = py;
        }
    }
    cur = 0ll;
    ++c[cor[1]];
    dfs(1, 1, 1);
    for (int i = 1; i <= m; ++i) {
        ll x = ans[i];
        ll y = (ll)(temp[i].y - temp[i].x + 1) * (ll)(temp[i].y - temp[i].x);
        if (x == 0) printf("0/1\n");
        else printf("%lld/%lld\n", x / gcd(x, y), y / gcd(x, y));
    }
    return 0;
}
```