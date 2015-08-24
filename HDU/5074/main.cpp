#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 50 + 7;

int n, m;
int a[maxn * 2], sc[maxn][maxn], dp[maxn * 2][maxn];

void init() {
    memset(a, 0, sizeof(a));
    memset(sc, 0, sizeof(sc));
    memset(dp, 0, sizeof(dp));
}

void input() {
    scanf("%d%d", &n, &m);

    for(int i = 1; i <= m; ++i)
        for (int j = 1; j <= m; ++j)
            scanf("%d", &sc[i][j]);

    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
}

void solve() {
    int res(0);

    for(int i = 1; i < n; ++i) {
        if(a[i] > 0 && a[i - 1] > 0) {
            dp[i][a[i]] = dp[i - 1][a[i - 1]] + sc[a[i - 1]][a[i]];
        }
        else if(a[i] > 0 && a[i - 1] < 0) {
            for (int j = 1; j <= m; ++j) {
                dp[i][a[i]] = max(dp[i][a[i]], dp[i - 1][j] + sc[j][a[i]]);
            }
        } else if(a[i] < 0 && a[i - 1] > 0) {
            for(int j = 1; j <= m; ++j) {
                dp[i][j] = max(dp[i][j], dp[i - 1][a[i - 1]] + sc[a[i - 1]][j]);
            }
        } else {
            for(int j = 1; j <= m; ++j) {
                for(int k = 1; k <= m; ++k) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][k] + sc[k][j]);
                }
            }
        }
    }

    for(int i = 1; i <= m; i++) res = max(res, dp[n - 1][i]);
    printf("%d\n", res);
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        init();
        input();
        solve();
    }
    return 0;
}