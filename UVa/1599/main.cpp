#include <iostream>
#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>

using namespace std;

typedef pair<int, int> P;

const int      inf = 1 << 30;
const int maxn = 100000 + 7;

struct edge {
    int v, cost, color;
    edge(int v_ = 0, int cost_ = 1, int color_ = 0) : v(v_), cost(cost_), color(color_) { }
};

int n, m;
int d[maxn], ans[maxn];
bool used[maxn];
vector<edge> G[maxn];

void init() {
    for(int i = 0; i < maxn; ++i) {
        d[i] = inf;
        ans[i] = inf;
        used[i] = false;
        G[i].clear();
    }
}

void dij() {
    d[n] = 0;
    priority_queue<P, vector<P>, greater<P> > que;
    que.push(make_pair(n, 0));

    while(!que.empty()) {
        P p = que.top(); que.pop();
        int v = p.first;
        if(d[v] < p.second) continue;
        for(int i = 0; i < G[v].size(); ++i) {
            edge e = G[v][i];
            if(d[e.v] > d[v] + e.cost) {
                d[e.v] = d[v] + e.cost;
                que.push(make_pair(e.v, d[e.v]));
            }
        }
    }
}

void bfs() {
    queue<int> que;
    while(!que.empty()) que.pop();
    que.push(1);

    while(!que.empty()) {
        int u = que.front(); que.pop();
        if(d[u] == 0) return ;
        int color = inf;
        for(int i = 0; i < G[u].size(); ++i) {
            edge e = G[u][i];
            if(d[e.v] == d[u] - 1) color = min(color, e.color);
        }
        if(ans[d[u] - 1] >= color) {
            ans[d[u] - 1] = color;
        } else continue;
        for(int i = 0; i < G[u].size(); ++i) {
            edge e = G[u][i];
            if(d[e.v] == d[u] - 1 && color == e.color && !used[e.v]) {
                que.push(e.v);
                used[e.v] = true;
            }
        }
    }
}


int main() {
    while(~scanf("%d%d", &n, &m)) {
        init();
        for(int i = 0; i < m; ++i) {
            int u, v, color;
            scanf("%d%d%d", &u, &v, &color);
            G[u].push_back(edge(v, 1, color));
            G[v].push_back(edge(u, 1, color));
        }
        dij();
        bfs();
        printf("%d\n", d[1]);
        for(int i = d[1] - 1; i >= 0; --i) {
            if(i != d[1] - 1) printf(" ");
            printf("%d", ans[i]);
        }
        printf("\n");
    }
    return 0;
}