#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

const int maxn = 1000 + 7;

int n, from[maxn];
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

int hungary() {
    int tot = 0;
    memset(from, -1, sizeof(from));
    for(int i = 0; i < n; ++i) {
        memset(used, 0, sizeof(used));
        if(match(i)) ++tot;
    }
    return tot;
}

int main() {
    while(~scanf("%d", &n)) {
        for(int i = 0; i < maxn; ++i) g[i].clear();
        int u, t, v;
        for(int i = 0; i < n; ++i) {
            scanf("%d: (%d)", &u, &t);
            for(int j = 0; j < t; ++j) {
                scanf("%d", &v);
                g[u].push_back(v);
            }
        }
        printf("%d\n", n - hungary() / 2);
    }
    return 0;
}