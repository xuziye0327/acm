#include <bits/stdc++.h>

using namespace std;

const int mod = (int)1e9 + 7;
const int maxn = 2000 + 7;

int T[maxn], dp[maxn];

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        memset(dp, 0, sizeof(dp));
        int N, sum(0);
        scanf("%d", &N);
        for(int i = 0; i < N; i++) {
            scanf("%d", &T[i]);
            sum += T[i];
        }
        sum /= 2;
        dp[0] = 1;
        for(int i = 0; i < N; i++) {
            for (int j = sum; j >= 0; --j) {
                for (int k = 1; k <= T[i]; ++k) {
                    if(j - k < 0) break;
                    dp[j] = (dp[j] + dp[j - k]) % mod;
                }
            }
        }
        printf("%d\n", dp[sum]);
    }
    return 0;
}