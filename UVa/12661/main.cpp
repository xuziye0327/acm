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
#define BLANK bool blank = false
#define RANDOM srand((unsigned)time(NULL))

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;
typedef pair<int, ull> PP;

const int inf = 1 << 30;
const ull INF = 1ULL << 60ULL;
const int maxn = 300 + 7;
const double eps = 1E-6;

struct Edge{
    int to;
    ull a, b, t;
    Edge (int v, ull a_, ull b_, ull t_) : to(v), a(a_), b(b_), t(t_) { }
};

ull d[maxn];
vector<Edge> G[maxn];

void init() {
    for (int i = 0; i < maxn; ++i) G[i].clear();
}

void dij(int s, int t) {
    for (int i = 0; i < maxn; ++i) d[i] = INF;
    d[s] = 0ULL;
    queue<int> Q;
    Q.push(s);

    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        for (int i = 0; i < G[u].size(); ++i) {
            Edge e = G[u][i];
            ull t1 = d[u] % (e.a + e.b);
            ull t2(INF);
            if (t1 < e.a) {
                if (t1 + e.t <= e.a) {
                    t2 = e.t;
                } else if (e.t <= e.a) {
                    t2 = (e.a + e.b) - t1 + e.t;
                }
                if (d[e.to] > d[u] + t2) {
                    d[e.to] = d[u] + t2;
                    Q.push(e.to);
                }
            } else {
                if (e.t <= e.a) {
                    t2 = (e.a + e.b) - t1 + e.t;
                }
                if (d[e.to] > d[u] + t2) {
                    d[e.to] = d[u] + t2;
                    Q.push(e.to);
                }
            }
        }
    }
}

int main() {
    int Kase(0);
    int n, m, s, t;
    while (~scanf("%d%d%d%d", &n, &m, &s, &t)) {
        init();
        for (int i = 0; i < m; ++i) {
            int u, v;
            ull a, b, cost;
            scanf("%d%d%llu%llu%llu", &u, &v, &a, &b, &cost);
            G[u].push_back(Edge(v, a, b, cost));
        }
        dij(s, t);
        printf("Case %d: %llu\n", ++Kase, d[t]);
    }
    return 0;
}
