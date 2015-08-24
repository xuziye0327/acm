#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int n;
int dp[11 + 7][100000 + 7], ma[11 + 7][100000 + 7];

int main() {
    while(~scanf("%d", &n) && n) {
        memset(dp, 0, sizeof(dp));
        memset(ma, 0, sizeof(ma));
        for(int i = 0; i < n; i++) {
            int x, T;
            scanf("%d%d", &x, &T);
            ++ma[x][T];
        }
        for(int i = 100000; i >= 0; --i) {
            for(int j = 0; j <= 10; ++j) {
                dp[j][i] = max(dp[j][i], dp[j][i + 1] + ma[j][i]);
                if(j != 10)
                    dp[j][i] = max(dp[j][i], dp[j + 1][i + 1] + ma[j][i]);
                if(j !=  0)
                    dp[j][i] = max(dp[j][i], dp[j - 1][i + 1] + ma[j][i]);
            }
        }
        printf("%d\n", dp[5][0]);
    }
    return 0;
}