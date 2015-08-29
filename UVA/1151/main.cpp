#include <iostream>
#include <cstdio>

#include <cstring>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <ctime>

#include <stack>
#include <queue>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define MP(x,y) make_pair(x,y)
#define CLR(a, b) memset(a, b, sizeof(a))
#define HERE printf("here!\n")
#define RANDOM srand((unsigned)time(NULL))

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;

const int inf = 1 << 30;
const int maxn = 1000 + 7;
const double eps = 1E-8;

struct Edge {
    int u, v, cost;
    bool operator < (const Edge& k) const {
        return cost < k.cost;
    }
}edge[maxn * maxn];

struct Buy{
    int n, C, v[maxn];
}buy[10];

struct Point{
    int x, y;
}point[maxn];

int n, q, res, ecnt;
int fa[maxn];
vector<Edge> mintree;

void init() {
    ecnt = 0;
    res = inf;
    mintree.clear();
}

void init_union_check() {
    for (int i = 0; i < maxn; ++i) {
        fa[i] = i;
    }
}

int fin(int x) { return x == fa[x] ? x : fa[x] = fin(fa[x]); }

int dis(const Point &k1, const Point &k2) {
    return (k1.x - k2.x) * (k1.x - k2.x) + (k1.y - k2.y) * (k1.y - k2.y);
}

void add_edge(int u, int v, int cost) {
    edge[ecnt].u = u; edge[ecnt].v = v; edge[ecnt++].cost = cost;
}

int kru() {
    int ans(0);
    sort(edge, edge + ecnt);
    init_union_check();

    for (int i = 0; i < ecnt; ++i) {
        int x = fin(edge[i].u), y = fin(edge[i].v);
        if (x != y) {
            fa[x] = y;
            mintree.push_back(edge[i]);
            ans += edge[i].cost;
        }
    }

    return ans;
}

int kru2() {
    int ans(0);
    sort(edge, edge + ecnt);
    init_union_check();

    for (int i = 0; i < ecnt; ++i) {
        int x = fin(edge[i].u), y = fin(edge[i].v);
        if (x != y) {
            fa[x] = y;
            ans += edge[i].cost;
        }
    }

    return ans;
}

void solve() {
    res = min(res, kru());

    for (int s = 1; s < (1 << q); ++s) {
        ecnt = 0;
        CLR(edge, 0);
        int cost(0);
        for (int i = 0; i < mintree.size(); ++i) {
            add_edge(mintree[i].u, mintree[i].v, mintree[i].cost);
        }
        for (int j = 0; j < q; ++j) {
            if (((s >> j) & 1) == 0) continue ;
            for (int k = 0; k < buy[j].n; ++k) {
                for (int i = k + 1; i < buy[j].n; ++i) {
                    int u = buy[j].v[k], v = buy[j].v[i];
                    add_edge(u, v, 0);
                }
            }
            cost += buy[j].C;
        }
        res = min(res, cost + kru2());
    }

    printf("%d\n", res);
}

int main() {
    int T;
    bool Kase(false);
    scanf("%d", &T);
    while (T--) {
        if (Kase) printf("\n");
        Kase = true;
        init();
        scanf("%d%d", &n, &q);
        for (int i = 0; i < q; ++i) {
            Buy &b = buy[i];
            scanf("%d%d", &b.n, &b.C);
            for (int j = 0; j < b.n; ++j) {
                scanf("%d", &b.v[j]);
            }
        }
        for (int k = 1; k <= n; ++k) {
            Point &p = point[k];
            scanf("%d%d", &p.x, &p.y);
        }
        for (int l = 1; l <= n; ++l) {
            for (int i = l + 1; i <= n; ++i) {
                int cost = dis(point[i], point[l]);
                add_edge(l, i, cost);
            }
        }
        solve();
    }
    return 0;
}
