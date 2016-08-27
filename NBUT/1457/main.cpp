#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

typedef unsigned long long ull;

const int maxn = 1e5 + 7;

struct Point {
    int x, y, id;
    bool operator < (const Point &k) const {
        return x != k.x ? x < k.x : y < k.y;
    }
}p[maxn], d[maxn], tp[maxn];

struct Edge {
    int u, v, cost;
    Edge() : u(0), v(0), cost(0) { }
    Edge(int _u, int _v, int _cost) : u(_u), v(_v), cost(_cost) { }
    bool operator < (const Edge &k) const {
        return cost < k.cost;
    }
}edges[maxn * 10];

struct eEdge {
    int node, next;
}eedges[maxn * 10];

int k, ek;
int c[maxn], t[maxn];
int a[maxn], b[maxn], f[maxn], types[maxn];
int pa[maxn], head[maxn];
bool used[maxn];
ull ans;
ull res[maxn];

void update(int x, int y) {
    for ( ; x; x -= x & -x) {
        if (c[t[x]] > c[y]) t[x] = y;
    }
}

int query(int x) {
    int ret = 0;
    for ( ; x < maxn; x += x & -x) {
        if (c[ret] > c[t[x]]) ret = t[x];
    }
    return ret;
}

void addEdge(int u, int v, int cost) {
    edges[k++] = Edge(u, v, cost);
    edges[k++] = Edge(v, u, cost);
}

void addEedge(int u, int v) {
    eedges[++ek].node = v; eedges[ek].next = head[u];
    head[u] = ek;
}

int findPa(int x) { return x == pa[x] ? x : pa[x] = findPa(pa[x]); }

ull getAns(int x) {
    ull xx = (ull) x;
    return xx * xx * xx;
}

void del(int l, int r) {
    for ( ; l <= r; ++l) {
        ans -= getAns(types[a[l]]);
        ans += getAns(--types[a[l]]);
    }
}

void add(int l, int r) {
    for ( ; l <= r; ++l) {
        ans -= getAns(types[a[l]]);
        ans += getAns(++types[a[l]]);
    }
}

void dfs(int x, int l, int r) {
    used[x] = true;
    if (l < tp[x].x) {
        del(l, tp[x].x - 1);
    }
    if (tp[x].x < l) {
        add(tp[x].x, l - 1);
    }
    if (r < tp[x].y) {
        add(r + 1, tp[x].y);
    }
    if (tp[x].y < r) {
        del(tp[x].y + 1, r);
    }
    res[x] = ans;
    for (int i = head[x]; i; i = eedges[i].next) {
        eEdge e = eedges[i];
        if (!used[e.node]) dfs(e.node, tp[x].x, tp[x].y);
    }
    if (l < tp[x].x) {
        add(l, tp[x].x - 1);
    }
    if (tp[x].x < l) {
        del(tp[x].x, l - 1);
    }
    if (r < tp[x].y) {
        del(r + 1, tp[x].y);
    }
    if (tp[x].y < r) {
        add(tp[x].y + 1, r);
    }
}

void init() {
    ans = 0;
    k = ek = 0;
    memset(head, 0, sizeof(head));
    memset(types, 0, sizeof(types));
    memset(used, false, sizeof(used));
}

int main() {
//    freopen("in.txt", "r", stdin);
    int n;
    while (~scanf("%d", &n)) {
        init();
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &a[i]);
            b[i] = a[i];
        }
        sort(b + 1, b + 1 + n);
        int m = unique(b + 1, b + 1 + n) - (b + 1);
        for (int i = 1; i <= n; ++i)
            a[i] = lower_bound(b + 1, b + 1 + m, a[i]) - (b + 1);
        int q;
        scanf("%d", &q);
        for (int i = 1; i <= q; ++i) {
            scanf("%d%d", &p[i].x, &p[i].y);
            p[i].id = i;
            tp[i] = p[i];
        }
        for (int dir = 1; dir <= 4; ++dir) {
            if (dir == 2 || dir == 4) {
                for (int i = 1; i <= q; ++i) swap(p[i].x, p[i].y);
            }
            if (dir == 3) {
                for (int i = 1; i <= q; ++i) p[i].x *= -1;
            }
            sort(p + 1, p + 1 + q);
            for (int i = 1; i <= q; ++i) {
                d[i].x = p[i].y - p[i].x;
                d[i].y = i;
                c[i] = p[i].x + p[i].y;
            }
            sort(d + 1, d + 1 + q);
            c[0] = maxn * 10;
            memset(t, 0, sizeof(t));
            for (int i = 1; i <= q; ++i) f[d[i].y] = i;
            for (int i = q; i >= 1; --i) {
                if (int x = query(f[i])) addEdge(p[x].id, p[i].id, c[x] - c[i]);
                update(f[i], i);
            }
        }
        sort(edges, edges + k);
        for (int i = 0; i < maxn; ++i) pa[i] = i;
        for (int i = 0; i < k; ++i) {
            Edge e = edges[i];
            int tx = findPa(e.u);
            int ty = findPa(e.v);
            if (tx != ty) {
                pa[tx] = ty;
                addEedge(e.u, e.v);
                addEedge(e.v, e.u);
            }
        }
        types[a[1]]++;
        ans = 1ull;
        dfs(1, 1, 1);
        for (int i = 1; i <= q; ++i) {
            printf("%I64u\n", res[i]);
        }
    }
    return 0;
}
