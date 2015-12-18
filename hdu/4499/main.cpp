#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 5 + 7;

int ans, temp;
int N, M, Q;
int ma[maxn][maxn];
int from[maxn];
bool used[maxn];
vector<int> G[maxn];

void init() {
    memset(ma, 0, sizeof(ma));
}

void dfs(int x, int y) {
    if(x == N && y == M - 1) {
        temp = 0;
        for(int i = 0; i < maxn; ++i) {
            for(int j = 0; j < maxn; ++j) {
                if(ma[i][j] == 1) {
                    ++temp;
                }
            }
        }
        ans = max(ans, temp);
        return;
    }
    if(x == N) { x = 0; ++y; }
    if(ma[x][y] == -1) dfs(x + 1, y);
    else {
        bool ok = true, flag = false;
        for(int i = y - 1; i >= 0; --i) {
            if(!flag && !ma[x][i]) continue;
            if(!flag && ma[x][i]) flag = true;
            else if(flag && ma[x][i] == -1) break;
            else if(flag && ma[x][i] == 1) { ok = false; break; }
        }
        flag = false;
        if(ok) {
            for(int i = x - 1; i >= 0; --i) {
                if(!flag && !ma[i][y]) continue;
                if(!flag && ma[i][y]) flag = true;
                else if(flag && ma[i][y] == -1) break;
                else if(flag && ma[i][y] == 1) { ok = false; break; }
            }
        }
        if(ok) {
            ma[x][y] = 1;
            dfs(x + 1, y);
        }
        ma[x][y] = 0;
        dfs(x + 1, y);
    }
}

int main() {
    while(~scanf("%d%d%d", &N, &M, &Q)) {
        ans = 0;
        temp = 0;
        init();
        for(int i = 0; i < Q; ++i) {
            int u, v;
            scanf("%d%d", &u, &v);
            ma[u][v] = -1;
        }
        dfs(0, 0);
        printf("%d\n", ans);
    }
    return 0;
}