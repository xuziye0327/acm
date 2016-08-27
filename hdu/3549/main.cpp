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
const int maxn = 1000 + 7;
const double eps = 1E-6;

struct Edge {
    int from, to, cap, flow;
    Edge (int u, int v, int c, int f) : from(u), to(v), cap(c), flow(f) { }
};

int N, M;
int m;
int a[maxn], p[maxn];
vector<int> G[maxn];
vector<Edge> edges;

void init() {
    for (int i = 0; i < maxn; ++i) G[i].clear();
    edges.clear();
}

void addEdge(int from, int to, int cap){
    edges.push_back(Edge(from, to, cap, 0));
    edges.push_back(Edge(to, from, 0, 0));
    m = edges.size();
    G[from].push_back(m - 2);
    G[to].push_back(m - 1);
};

int maxFlow(int s, int t) {
    int flow(0);
    for ( ; ;) {
        CLR(a, 0);
        queue<int> Q;
        Q.push(s);
        a[s] = inf;
        while (!Q.empty()) {
            int x = Q.front(); Q.pop();
            for (int i = 0; i < G[x].size(); ++i) {
                Edge &e = edges[G[x][i]];
                if (!a[e.to] && e.cap > e.flow) {
                    p[e.to] = G[x][i];
                    a[e.to] = min(a[x], e.cap - e.flow);
                    Q.push(e.to);
                }
            }
            if (a[t]) break;
        }
        if (!a[t]) break;
        for (int u = t; u != s; u = edges[p[u]].from) {
            edges[p[u]].flow += a[t];
            edges[p[u] ^ 1].flow -= a[t];
        }
        flow += a[t];
    }
    return flow;
}

int main() {
    int T, Kase(0);
    scanf("%d", &T);
    while (T--) {
        init();
        scanf("%d%d", &N, &M);
        for (int i = 0; i < M; ++i) {
            int x, y, c;
            scanf("%d%d%d", &x, &y, &c);
            addEdge(x, y, c);
        }
        printf("Case %d: %d\n", ++Kase, maxFlow(1, N));
    }
    return 0;
}
