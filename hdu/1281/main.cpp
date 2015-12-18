#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 100 + 7;

int N, M, K;
int from[maxn];
bool used[maxn], g[maxn][maxn];

bool match(int x) {
    for(int i = 1; i <= M; ++i) {
        if(!used[i] && g[x][i]) {
            used[i] = true;
            if(from[i] == -1 || match(from[i])) {
                from[i] = x;
                return true;
            }
        }
    }
    return false;
}

int hungary() {
    int tot(0);
    memset(from, -1, sizeof(from));
    for(int i = 1; i <= N; ++i) {
        memset(used, 0, sizeof(used));
        if(match(i)) ++tot;
    }
    return tot;
}

int main() {
    int kase(0);
    while(~scanf("%d%d%d", &N, &M, &K)) {

        memset(g, 0, sizeof(g));

        for(int i = 0; i < K; ++i) {
            int u, v;
            scanf("%d%d", &u, &v);
            g[u][v] = true;
        }

        int C(0), L(hungary());

        for(int i = 1; i <= N; ++i) {
            for(int j = 1; j <= M; ++j) {
                if(g[i][j]) {
                    g[i][j] = false;
                    if(L > hungary()) ++C;
                    g[i][j] = true;
                }
            }
        }

        printf("Board %d have %d important blanks for %d chessmen.\n", ++kase, C, L);
    }
    return 0;
}