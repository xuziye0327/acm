#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const int maxn = 1000 + 7;

struct Point {
    double x, y, w;
}p[maxn];

struct Edge {
    int u, v;
    double dist;
    bool operator < (const Edge &e) const {
        return dist < e.dist;
    }
}e[maxn * maxn];

int n, ecnt;
int pa[maxn];
bool vis[maxn];
double g[maxn][maxn];
double dist[maxn][maxn];
vector<int> G[maxn];

void init() {
    for(int i = 0; i < maxn; ++i) { pa[i] = i; G[i].clear(); }
    ecnt = 0;
    memset(p, 0, sizeof(p));
    memset(g, 0, sizeof(g));
    memset(dist, 0, sizeof(dist));
}

int fin(int x) { return x == pa[x] ? x : pa[x] = fin(pa[x]); }

void dfs(int u, int rt) {
    vis[u] = true;
    for(int i = 0; i < G[u].size(); ++i) {
        int v = G[u][i];
        if(!vis[v]) {
            g[rt][v] = max(g[rt][u], dist[u][v]);
            dfs(v, rt);
        }
    }
}

double Kruskal() {
    sort(e, e + ecnt);

    double ans(0.0);
    double sum(0.0);

    for(int i = 0; i < ecnt; ++i) {
        int x = fin(e[i].u), y = fin(e[i].v);
        if(x != y) {
            pa[x] = y;
            sum += e[i].dist;
            G[e[i].u].push_back(e[i].v);
            G[e[i].v].push_back(e[i].u);
            dist[e[i].u][e[i].v] = dist[e[i].v][e[i].u] = e[i].dist;
        }
    }

    for(int u = 0; u < n; ++u) {
        memset(vis, false, sizeof(vis));
        dfs(u, u);
    }

    for(int i = 0; i < n; ++i) {
        for(int j = i + 1; j < n; ++j) {
            ans = max(ans, (p[i].w + p[j].w) / (sum - g[i][j]));
        }
    }

    return ans;
}

int main (){
    int T;
    scanf("%d", &T);
    while(T--) {
        init();
        scanf("%d", &n);
        for(int i = 0; i < n; ++i) scanf("%lf%lf%lf", &p[i].x, &p[i].y, &p[i].w);
        for(int i = 0; i < n; ++i)
            for(int j = i + 1; j < n; ++j) {
                double d = sqrt((p[i].x - p[j].x) * (p[i].x - p[j].x) + (p[i].y - p[j].y) * (p[i].y - p[j].y));
                e[ecnt].u = i; e[ecnt].v = j; e[ecnt++].dist = d;
            }
        printf("%.2f\n", Kruskal());
    }
    return 0;
};