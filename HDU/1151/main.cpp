#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>

using namespace std;

const int maxn = 120 + 7;

int n, m;
int from[maxn];
bool used[maxn];
vector<int> g[maxn];

bool match(int x) {
    for(int i = 0; i < g[x].size(); ++i) {
        if(!used[g[x][i]]) {
            used[g[x][i]] = true;
            if(from[g[x][i]] == -1 || match(from[g[x][i]])) {
                from[g[x][i]] = x;
                return true;
            }
        }
    }
    return false;
}

int hunary() {
    int tot(0);
    memset(from, -1, sizeof(from));
    for(int i = 1; i <= n; ++i) {
        memset(used, 0, sizeof(used));
        if(match(i)) ++tot;
    }
    return tot;
}
int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        for(int i = 0; i < maxn; ++i) g[i].clear();

        scanf("%d%d", &n, &m);

        for(int i = 0; i < m; ++i) {
            int u, v;
            scanf("%d%d", &u, &v);
            g[u].push_back(v);
        }

        printf("%d\n", n - hunary());
    }
    return 0;
}