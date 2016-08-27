### 题目链接
<a href="http://poj.org/problem?id=3241">HERE</a>

### 题目描述
求曼哈顿距离最小生成树上第K大边。

### 解题思路
曼哈顿距离最小生成树模板题。

``` cpp
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxn = 10007;

int t, c[maxn], f[maxn];
int fa[maxn];

struct BIT {
    int t[maxn];
    void clr () { memset(t, 0, sizeof(t)); }
    void update (int x, int y) {
        for ( ; x; x -= (x & -x)) if (c[y] < c[t[x]]) t[x] = y;
    }
    int query (int x) {
        int y = 0;
        for ( ; x < maxn; x += x & -x) {
            if (c[y] > c[t[x]]) y = t[x];
        }
        return y;
    }
}B;

struct Point {
    int x, y, n;
    bool operator < (const Point& k) const {
        return x != k.x ? x < k.x : y < k.y;
    }
}p[maxn], d[maxn];

struct Edge {
    int from, to, dist;
    Edge () : from(0), to(0), dist(0) { }
    Edge (int f, int t, int d) : from(f), to(t), dist(d) { }
    bool operator < (const Edge& e) const {
        return dist < e.dist;
    }
}edges[maxn * 10];

void add_edge(int from, int to, int dist) {
    edges[t++] = Edge(from, to, dist);
    edges[t++] = Edge(to, from, dist);
}

int unionFind(int x) { return x == fa[x] ? x : fa[x] = unionFind(fa[x]); }

int main() {
    t = 0;
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d", &p[i].x, &p[i].y);
        p[i].n = i;
    }
    for (int dir = 1; dir <= 4; ++dir) {
        if (dir == 2 || dir == 4) {
            for (int i = 1; i <= n; ++i) {
                swap(p[i].x, p[i].y);
            }
        }
        if (dir == 3) {
            for (int i = 1; i <= n; ++i) {
                p[i].x *= -1;
            }
        }
        sort(p + 1, p + 1 + n);
        for (int i = 1; i <= n; ++i) {
            d[i].x = p[i].y - p[i].x;
            d[i].y = i;
            c[i] = p[i].x + p[i].y;
        }
        sort(d + 1, d + 1 + n);
        for (int i = 1; i <= n; ++i) {
            f[d[i].y] = i;
        }
        c[0] = 0x3f3f3f;
        B.clr();
        for (int i = n; i >= 1; --i) {
            int x;
            if (x = B.query(f[i])) add_edge(p[x].n, p[i].n, c[x] - c[i]);
            B.update(f[i], i);
        }
    }
    for (int i = 0; i < maxn; ++i) fa[i] = i;
    sort(edges, edges + t);
    int lc = n - k;
    for (int i = 0; i < t; ++i) {
        Edge e = edges[i];
        int px = unionFind(e.from);
        int py = unionFind(e.to);
        if (px != py) {
            --lc;
            if (lc == 0) {
                printf("%d\n", e.dist);
                break;
            }
            fa[px] = py;
        }
    }
    return 0;
}
```