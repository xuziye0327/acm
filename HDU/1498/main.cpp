#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

const int maxn = 100 + 7;

int n, k;
int ma[maxn][maxn];
int from[maxn];
bool used[maxn];
vector<int> G[maxn];
queue<int> ans;

void initG() {
    for(int i = 0; i < maxn; ++i) G[i].clear();
}

bool match(int x) {
    for(int i = 0; i < G[x].size(); ++i) {
        int t = G[x][i];
        if(!used[t]) {
            used[t] = true;
            if(from[t] == -1 || match(from[t])) {
                from[t] = x;
                return true;
            }
        }
    }
    return false;
}

int hungary() {
    int res(0);
    memset(from, -1, sizeof(from));
    for(int i = 1; i <= n; ++i) {
        memset(used, false, sizeof(used));
        if(match(i)) ++res;
    }
    return res;
}

int main() {
    while(~scanf("%d%d", &n, &k) && n) {
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= n; ++j) {
                scanf("%d", &ma[i][j]);
            }
        }
        for(int l = 1; l <= 50; ++l) {
            initG();
            for(int i = 1; i <= n; ++i) {
                for(int j = 1; j <= n; ++j) {
                    if(ma[i][j] == l) G[i].push_back(j);
                }
            }
            if(hungary() > k) ans.push(l);
        }
        if(ans.empty()) printf("-1");
        else {
            bool b = false;
            while(!ans.empty()) {
                if(b) printf(" ");
                printf("%d", ans.front());
                ans.pop();
                b = true;
            }
        }
        printf("\n");
    }
    return 0;
}