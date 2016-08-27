#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

const int maxn = 200 + 7;

struct Node {
    int cup[3], dist;
    bool operator < (const Node &k) const {
        return dist > k.dist;
    }
};

int ans[maxn];
bool vis[maxn][maxn];

void init() {
    memset(ans, -1, sizeof(ans));
    memset(vis, false, sizeof(vis));
}

void bfs(int a, int b, int c, int d) {
    init();
    int cup[3];
    cup[0] = a, cup[1] =  b, cup[2] = c;
    Node u;
    u.cup[0] = 0, u.cup[1] =  0, u.cup[2] = c, u.dist = 0;
    vis[0][0] = true;
    priority_queue<Node> que;
    while(!que.empty()) que.pop();
    que.push(u);

    while(!que.empty()) {
        u = que.top(); que.pop();
//        printf("dist = %d, nextdist = %d\n", u.dist, que.top().dist);
        for(int i = 0; i < 3; ++i) {
            int t = u.cup[i];
            if(ans[t] < 0 || ans[t] > u.dist) ans[t] = u.dist;
        }

        if (ans[d] >= 0) break;

        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j) if(i != j) {
                    if(u.cup[i] == 0 || u.cup[j] == cup[j]) continue;
                    int count = min(cup[j], u.cup[i] + u.cup[j]) - u.cup[j];
                    Node t = u;
                    t.dist += count;
                    t.cup[i] -= count;
                    t.cup[j] += count;

                    if(!vis[t.cup[0]][t.cup[1]]) {
                        vis[t.cup[0]][t.cup[1]] = true;
                        que.push(t);
                    }
                }
    }

    while(d >= 0) {
        if(ans[d] >= 0) {
            printf("%d %d\n", ans[d], d);
            return ;
        }
        --d;
    }
}

int main() {
    int a, b, c, d, Kase;
    scanf("%d", &Kase);
    while(Kase--) {
        scanf("%d%d%d%d", &a, &b, &c, &d);
        bfs(a, b, c, d);
    }
    return 0;
}