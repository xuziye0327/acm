#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

const int maxn = 100 + 7;

vector<int> g[maxn];

int n, m, k;
int from[maxn];
bool used[maxn];

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

int hungary() {
    int tot(0);
    memset(from, -1, sizeof(from));
    for(int i = 0; i < n; ++i) {
        memset(used, 0, sizeof(used));
        if(match(i)) ++tot;
    }
    return tot;
}

int main() {
    while(~scanf("%d", &n) && n) {
        scanf("%d%d", &m, &k);
        for(int i = 0; i < maxn; ++i) g[i].clear();

        for(int i = 0; i < k; ++i) {
            int t, u, v;
            scanf("%d%d%d", &t, &u, &v);
            if(u && v)
                g[u].push_back(v);
        }

        printf("%d\n", hungary());
    }
    return 0;
}