#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

const int maxn = 1000 * 40 + 7;

int t, N;
int k[40 + 7];
double P;
double dp[40 + 7][maxn];

int main() {
    scanf("%d", &t);
    while(t--) {
        memset(dp, 0, sizeof(dp));
        scanf("%d%lf", &N, &P);
        for(int i = 0; i < N; ++i) {
            scanf("%d", &k[i]);
        }
        dp[0][0] = 1.0;
        for(int i = 1; i <= N; ++i) {
            for(int j = 0; j < maxn; ++j) {
                dp[i][j] = dp[i - 1][j] / 2.0;
                if(j >= k[i - 1]) dp[i][j] += dp[i - 1][j - k[i - 1]] / 2.0;
            }
        }
        int ans(0);
        double res = 0.0;
        for(int i = 0; i < maxn; ++i) {
            res += dp[N][i];
            if(res >= P) { ans = i; break; }
        }
//        printf("%.4f\n", res);
        printf("%d\n", ans);
    }
    return 0;
}