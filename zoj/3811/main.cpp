#include <bits/stdc++.h>

using namespace std;

const int maxn = 100000 + 7;
const char output[2][5] = {"No", "Yes"};

int n, m, k, l;

int pos[maxn];
bool isk[maxn], vis[maxn];
vector<int> G[maxn];

void init() {
    for(int i = 0; i < maxn; i++) G[i].clear();
    fill(pos, pos + maxn, 0);
    fill(isk, isk + maxn, true);
    fill(vis, vis + maxn, false);
}

void bfs(int x) {
    queue<int> que;
    que.push(x);
    vis[x] = true;

    while(!que.empty()) {
        int u = que.front(); que.pop();

        for(int i = 0; i < G[u].size(); i++)
            if(!vis[G[u][i]]) {
                vis[G[u][i]] = true;

                if(!isk[G[u][i]]) continue;
                que.push(G[u][i]);
            }
    }
}

int main () {
    int t;
    scanf("%d", &t);
    while(t--) {
        init();
        bool ok = true;
        scanf("%d%d%d", &n, &m, &k);
        for(int i = 0; i < k; i++) scanf("%d");
        for(int i = 0; i < m; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
        scanf("%d", &l);
        for(int i = 0; i < l; i++) {
            scanf("%d", &pos[i]);
            isk[pos[i]] = false;
        }
        if(l != k) { ok = false; }
        else {
            vis[pos[0]] = true;
            for(int i = 0; i < l; i++) {
                if(!vis[pos[i]]) { ok = false; break; }
                bfs(pos[i]);
            }
            for(int i = 1; i <= n; i++) {
                if(!vis[i]) ok = false;
            }
        }

        printf("%s\n", output[ok]);
    }
    return 0;
}