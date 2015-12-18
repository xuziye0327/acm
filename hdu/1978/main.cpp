#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int  mod = 10000;
const int maxn = 100 + 7;

int n, m;
int dp[maxn][maxn];
int ma[maxn][maxn];

void init() {
    memset(dp, 0, sizeof(dp));
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        init();
        scanf("%d%d", &n, &m);
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                scanf("%d", &ma[i][j]);
            }
        }
        dp[0][0] = 1;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                for (int k = 0; k <= ma[i][j]; ++k) {
                    if(k + i >= n) break;
                    for (int l = 0; l <= ma[i][j] - k; ++l) {
                        if(l + j >= m) break;
                        if(!k && !l) continue;
                        dp[i + k][j + l] += dp[i][j] % mod;
                    }
                }
            }
        }
        printf("%d\n", dp[n - 1][m - 1] % mod);
    }
    return 0;
}