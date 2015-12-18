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

const int inf = 1 << 28;
const ull INF = 1ULL << 60ULL;
const int maxn = 2500 + 7;
const double eps = 1E-6;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

struct Edge {
    int from, to, cap, flow;
    Edge (int u, int t, int c, int f) : from(u), to(t), cap(c), flow(f) { }
};

int m;
int h, w, d, f, b;
int a[maxn], p[maxn];
char ma[50 + 7][50 + 7];
vector<int> G[maxn];
vector<Edge> edges;

void init() {
    edges.clear();
    for (int i = 0; i < maxn; ++i) G[i].clear();
}

int getV(int x, int y) {
    return (x - 1) * w + y;
}

void addEdge (int from, int to, int cap) {
    edges.push_back(Edge(from, to, cap, 0));
    edges.push_back(Edge(to, from, 0, 0));
    m = edges.size();
    G[from].push_back(m - 2);
    G[to].push_back(m - 1);
}

int maxFlow(int s, int t) {
    int flow(0);
    for ( ; ;) {
        CLR(a, 0);
        a[s] = inf;
        queue<int> Q;
        Q.push(s);

        while (!Q.empty()) {
            int x = Q.front(); Q.pop();
            for (int i = 0; i < G[x].size(); ++i) {
                Edge& e = edges[G[x][i]];
                if (!a[e.to] && e.cap > e.flow) {
                    p[e.to] = G[x][i];
                    a[e.to] = min(a[x], e.cap - e.flow);
                    Q.push(e.to);
                }
            }
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
    int T;
    scanf("%d", &T);
    while (T--) {
        init();
        scanf("%d%d", &w, &h);
        scanf("%d%d%d", &d, &f, &b);
        for (int i = 1; i <= h; ++i) scanf("%s", ma[i] + 1);
        int ans = 0;
        for (int i = 1; i <= h; ++i) {
            for (int j = 1; j <= w; ++j) {
                if (i == 1 || j == 1 || i == h || j == w) {
                    if (ma[i][j] == '.') { ma[i][j] = '#'; ans += f; }
                    addEdge(0, getV(i, j), inf);
                } else {
                    if (ma[i][j] == '#') {
                        addEdge(0, getV(i, j), d);
                    } else {
                        addEdge(getV(i, j), maxn - 1, f);
                    }
                }
                for (int k = 0; k < 4; ++k) {
                    if (i + dx[k] > 0 && i + dx[k] <= h && j + dy[k] > 0 && j + dy[k] <= w) {
                        addEdge(getV(i, j), getV(i + dx[k], j + dy[k]), b);
                    }
                }
            }
        }
        printf("%d\n", ans + maxFlow(0, maxn - 1));
    }
    return 0;
}
