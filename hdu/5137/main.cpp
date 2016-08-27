#include <bits/stdc++.h>

using namespace std;

const int maxn = 30 + 7;
const int inf = 1 << 27;

struct edge { int to; int cost; };
typedef pair<int, int> P;

int V, E, res;
vector<edge> G[maxn];
int d[maxn];

void dijkstra(int s, int no) {
    priority_queue<P, vector<P>, greater<P> > que;
    fill(d, d + V + 1, inf);
    d[s] = 0;
    que.push(P(0, s));

    while(!que.empty()) {
        P p = que.top(); que.pop();
        int v = p.second;
        if(d[v] < p.first) continue;
        for(int i = 0; i < G[v].size(); i++) {
            if(G[v][i].to == no) continue;
            edge e = G[v][i];
            if(d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to], e.to));
            }
        }
    }
}

void init() {
    for(int i = 0; i < maxn; i++) G[i].clear();
    res = 0;
}

int main() {
    while(~scanf("%d%d", &V, &E) && V) {
        init();
        for(int i = 0; i < E; i++) {
            int from, to, cost;
            scanf("%d%d%d", &from, &to, &cost);
            edge e;
            e.to = to;
            e.cost = cost;
            G[from].push_back(e);
            e.to =  from;
            G[to].push_back(e);
        }
        for(int i = 2; i < V; i++) {
            dijkstra(1, i);
            res = max(res, d[V]);
        }
        if(res >= inf) printf("Inf\n");
        else printf("%d\n", res);
    }
    return 0;
}
