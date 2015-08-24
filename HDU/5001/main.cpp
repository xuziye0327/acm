#include <bits/stdc++.h>

using namespace std;

const int maxn = 50 + 7;

int n, m, d;
double cnt[maxn], dp[10000 + 7][maxn];
bool G[maxn][maxn];

void init() {
    for(int i = 0; i < maxn; i++) cnt[i] = 0;
    for(int i = 0; i < maxn; i++)
        for(int j = 0; j < maxn; j++) G[i][j] = false;
    for(int i = 0; i < 10000 + 7; i++)
        for(int j = 0; j < maxn; j++) dp[i][j] = 0;
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d%d", &n, &m, &d);
        init();
        for(int i = 0; i < m; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            G[u][v] = G[v][u] = true;
            cnt[u]++; cnt[v]++;
        }
        for(int vis = 1; vis <= n; vis++) {
            memset(dp, 0, sizeof(dp));
            for(int i = 0; i < maxn; i++) dp[0][i] = 1.0 / (double)n;
            for(int i = 1; i <= d; i++) {
                for(int j = 1; j <= n; j++) {
                    for(int k = 1; k <= n; k++) {
                        if(vis == k) continue;
                        if(G[k][j])
                        dp[i][j] += dp[i - 1][k] * 1.0 / cnt[k];
                    }
                }
            }
            double sum(0.0);
            for(int i = 0; i <= d; i++) {
                sum += dp[i][vis];
            }
            printf("%.10f\n", 1.0 - sum);
        }
    }
    return 0;
}