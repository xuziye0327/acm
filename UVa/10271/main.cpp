#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxn = 1100 + 7;

int ma[maxn * 5];
int dp[maxn * 5][maxn];

int main () {
    int T;
    scanf("%d", &T);
    while (T--) {
        memset(dp, 0x3f, sizeof(dp));
        int k, n;
        scanf("%d%d", &k, &n);
        k += 8;
        for (int i = n; i >= 1; --i) {
            scanf("%d", &ma[i]);
        }
        for (int i = 0; i < maxn * 5; ++i) dp[i][0] = 0;
        for (int i = 3; i <= n; ++i) {
            for (int j = 1; j <= k && j * 3 <= i; ++j) {
                    dp[i][j] = min(dp[i - 1][j], dp[i - 2][j - 1] + (ma[i - 1] - ma[i]) * (ma[i - 1] - ma[i]));
            }
        }
        printf("%d\n", dp[n][k]);
    }
    return 0;

}
