#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long ll;

const int maxn = 100007;
const ll INF = 1ll << 50ll;

struct Point {
    int x, y, n;
    bool operator < (const Point& k) const {
        return x != k.x ? x < k.x : y < k.y;
    }
}p[maxn], b[maxn];

int f[maxn], k;
int pa[maxn];
ll c[maxn];

struct BIT {
    int t[maxn];
    void clr() { memset(t, 0, sizeof(t)); }
    void update(int x, int y) {
        for ( ; x; x -= x & -x) {
            if (c[t[x]] > c[y]) t[x] = y;
        }
    }
    int query(int x) {
        int n = 0;
        for ( ; x < maxn; x += x & -x) {
            if (c[n] > c[t[x]]) n = t[x];
        }
        return n;
    }
}B;

struct Edge {
    int u, v;
    ll cost;
    bool operator < (const Edge& e) const {
        return cost < e.cost;
    }
}edges[maxn * 10];

inline void addEdge(int u, int v, ll cost) {
    edges[k].u = u, edges[k].v = v, edges[k++].cost = cost;
    edges[k].u = v, edges[k].v = u, edges[k++].cost = cost;
}

inline int getPa(int x) { return x == pa[x] ? x : pa[x] = getPa(pa[x]); }

inline void Swap(int &a, int &b) { a ^= b; b ^= a; a ^= b; }

int main() {
    int n, Case(0);
    while (scanf("%d", &n) && n) {
        k = 0;
        for (int i = 1; i <= n; ++i) {
            scanf("%d%d", &p[i].x, &p[i].y);
            p[i].n = i;
        }
        for (int dir = 1; dir <= 4; ++dir) {
            if (dir == 2 || dir == 4)
                for (int i = 1; i <= n; ++i) Swap(p[i].x, p[i].y);
            if (dir == 3)
                for (int i = 1; i <= n; ++i) p[i].x *= -1;
            sort(p + 1, p + 1 + n);
            for (int i = 1; i <= n; ++i) b[i].x = p[i].y - p[i].x, b[i].y = i, c[i] = p[i].x + p[i].y;
            sort(b + 1, b + 1 + n);
            for (int i = 1; i <= n; ++i) f[b[i].y] = i;
            c[0] = INF;
            B.clr();
            for (int i = n; i > 0; --i) {
                int x;
                if (x = B.query(f[i])) addEdge(p[x].n, p[i].n, c[x] - c[i]);
                B.update(f[i], i);
            }
        }
        for (int i = 0; i < maxn; ++i) pa[i] = i;
        sort(edges, edges + k);
        ll ans = 0;
        for (int i = 0; i < k; ++i) {
            Edge e = edges[i];
            int px = getPa(e.u);
            int py = getPa(e.v);
            if (px != py) {
                pa[px] = py;
                ans += e.cost;
            }
        }
        printf("Case %d: Total Weight = %lld\n", ++Case, ans);
    }
    return 0;
}
