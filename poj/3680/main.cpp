#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef long long ll;

const int maxn = 407;
const int maxm = 100007;
const int inf = 233333333;

int n, k;

struct Edge {
    int from, to, cap, flow, cost;
    Edge (int u, int v, int c, int f, int co) : from(u), to(v), cap(c), flow(f), cost(co) { }
};

int m;
int a[maxn], d[maxn], p[maxn];
bool inqu[maxn];
vector<int> G[maxn];
vector<Edge> edges;

void init() {
    edges.clear();
    for (int i = 0; i < maxn; ++i) G[i].clear();
}

void addEdge(int from, int to, int cap, int cost) {
    edges.push_back(Edge(from, to, cap, 0, cost));
    edges.push_back(Edge(to, from, 0, 0, -cost));
    m = edges.size();
    G[from].push_back(m - 2);
    G[to].push_back(m - 1);
}

bool bellmanFord(int s, int t, int& flow, ll& cost) {
    for (int i = 0; i <= maxn; ++i) d[i] = inf;
    memset(a, 0, sizeof(a));
    memset(inqu, false, sizeof(inqu));
    d[s] = 0; p[s] = 0; a[s] = inf; inqu[s] = true;

    queue<int> Q;
    Q.push(s);
    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        inqu[u] = false;
        for (int i = 0; i < G[u].size(); ++i) {
            Edge& e = edges[G[u][i]];
            if (e.cap > e.flow && d[e.to] > d[u] + e.cost) {
                d[e.to] = d[u] + e.cost;
                p[e.to] = G[u][i];
                a[e.to] = min(a[u], e.cap - e.flow);
                if (!inqu[e.to]) { Q.push(e.to); inqu[e.to] = true; }
            }
        }
    }
    if (d[t] == inf) return false;
    flow += a[t];
    cost += (ll) d[t] * (ll) a[t];
    for (int u = t; u != s; u = edges[p[u]].from) {
        edges[p[u]].flow += a[t];
        edges[p[u] ^ 1].flow -= a[t];
    }
    return true;
}

int minCostMaxflow(int s, int t, ll& cost) {
    int flow = 0; cost = 0;
    while (bellmanFord(s, t, flow, cost)) ;
    return flow;
}

int l[maxn], r[maxn], w[maxn];
int x[maxn];

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &k);
        init();
        int cnt = 0;
        for (int i = 1; i <= n; ++i) {
            scanf("%d%d%d", &l[i], &r[i], &w[i]);
            x[cnt++] = l[i];
            x[cnt++] = r[i];
        }
        sort(x, x + cnt);
        cnt = unique(x, x + cnt) - x;
        for (int i = 1; i <= cnt; ++i) {
            addEdge(i - 1, i, k, 0);
        }
        for (int i = 1; i <= n; ++i) {
            int a = lower_bound(x, x + cnt, l[i]) - x + 1;
            int b = lower_bound(x, x + cnt, r[i]) - x + 1;
            addEdge(a, b, 1, -w[i]);
        }
        ll res = 0;
        int flow = minCostMaxflow(0, cnt, res);
        printf("%I64d\n", -res);
    }
    return 0;
}
