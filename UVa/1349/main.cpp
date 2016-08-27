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

const int inf = 1 << 30;
const int maxn = 200 + 7;
const double eps = 1E-6;

struct Edge{
    int from, to, cap, flow, cost;
    Edge(int u, int v, int c, int f, int co) : from(u), to(v), cap(c), flow(f), cost(co) { }
};

int n, m;
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

bool bellmanFord(int s, int t, int &flow, int& cost) {
    for (int i = 0; i < maxn; ++i) d[i] = inf;
    CLR(a, 0);
    CLR(inqu, false);
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
    cost += d[t] * a[t];
    for (int u = t; u != s; u = edges[p[u]].from) {
        edges[p[u]].flow += a[t];
        edges[p[u] ^ 1].flow -= a[t];
    }
    return true;
}

int minCostMaxFlow(int s, int t, int& cost) {
    int flow = 0; cost = 0ll;
    while (bellmanFord(s, t, flow, cost)) ;
    return flow;
}

int main() {
    while (scanf("%d", &n) && n) {
        init();
        for (int i = 1; i <= n; ++i) {
            addEdge(0, i, 1, 0);
        }
        for (int i = 1; i <= n; ++i) {
            addEdge(i + n, maxn - 1, 1, 0);
        }
        for (int i = 1; i <= n; ++i) {
            int v, c;
            while (scanf("%d", &v) && v) {
                scanf("%d", &c);
                addEdge(i, v + n, 1, c);
            }
        }
        int ans;
        if (minCostMaxFlow(0, maxn - 1, ans) == n) printf("%d\n", ans);
        else printf("N\n");
    }
    return 0;
}
