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
const int maxn = 40 + 7;
const double eps = 1E-6;

struct Edge {
    int from, to, cap, flow;
    Edge (int u, int v, int c, int f) : from(u), to(v), cap(c), flow(f) { }
};

int R, C;
int a[maxn], b[maxn], A[maxn], B[maxn];
int m;
int p[maxn], flo[maxn];
vector<int> G[maxn];
vector<Edge> edges;

void init() {
    CLR(a, 0);
    CLR(b, 0);
    CLR(A, 0);
    CLR(B, 0);
    edges.clear();
    for (int i = 0; i < maxn; ++i) G[i].clear();
}

void addEdge(int from, int to, int cap) {
    edges.push_back(Edge(from, to, cap, 0));
    edges.push_back(Edge(to, from, 0, 0));
    m = edges.size();
    G[from].push_back(m - 2);
    G[to].push_back(m - 1);
}

void maxFlow(int s, int t) {
    for ( ; ;) {
        CLR(flo, 0);
        queue<int> Q;
        flo[s] = inf;
        Q.push(s);
        while (!Q.empty()) {
            int x = Q.front(); Q.pop();
            for (int i = 0; i < G[x].size(); ++i) {
                Edge &e = edges[G[x][i]];
                if (!flo[e.to] && e.cap > e.flow) {
                    p[e.to] = G[x][i];
                    flo[e.to] = min(flo[x], e.cap - e.flow);
                    Q.push(e.to);
                }
            }
            if (flo[t]) break;
        }
        if (!flo[t]) return ;
        for (int u = t; u != s; u = edges[p[u]].from) {
            edges[p[u]].flow += flo[t];
            edges[p[u] ^ 1].flow -= flo[t];
        }
    }
}

int main() {
    int T, Kase(0);
    scanf("%d", &T);
    while (T--) {
        init();
        if (Kase) printf("\n");
        scanf("%d%d", &R, &C);
        int k = 0;
        for (int i = 1; i <= R; ++i) {
            scanf("%d", &a[i]);
            A[i] = a[i] - a[i - 1];
            addEdge(0, ++k, A[i] - C);
        }
        for (int i = 1; i <= C; ++i) {
            scanf("%d", &b[i]);
            B[i] = b[i] - b[i - 1];
            addEdge(++k, maxn - 1, B[i] - R);
        }
        for (int i = 1; i <= R; ++i) {
            for (int j = 1; j <= C; ++j) {
                addEdge(i, R + j, 19);
            }
        }
        int kk = 0;
        maxFlow(0, maxn - 1);
        printf("Matrix %d\n", ++Kase);
        for (int i = 1; i <= R; ++i) {
            for (int j = 1; j <= C; ++j) {
                if (j != 1) printf(" ");
                printf("%d", edges[(R + C) * 2 + kk * 2].flow + 1);
                ++kk;
            }
            printf("\n");
        }
    }
    return 0;
}
