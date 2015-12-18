#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 20 + 7;

int n;
int a[maxn], b[maxn];
int suma[maxn], sumb[maxn];
int dp[maxn][maxn][maxn][maxn];

void init() {
    memset(dp, 0, sizeof(dp));
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    memset(suma, 0, sizeof(suma));
    memset(sumb, 0, sizeof(sumb));
}

int dfs(int l1, int r1, int l2, int r2) {
    if(dp[l1][r1][l2][r2]) return dp[l1][r1][l2][r2];
    int temp(0);
    if(l1 <= r1) temp += suma[r1] - suma[l1 - 1];
    if(l2 <= r2) temp += sumb[r2] - sumb[l2 - 1];
    int res(0);
    if(l1 <= r1) {
        res = max(res, temp - dfs(l1 + 1, r1, l2, r2));
        res = max(res, temp - dfs(l1, r1 - 1, l2, r2));
    }
    if(l2 <= r2) {
        res = max(res, temp - dfs(l1, r1, l2 + 1, r2));
        res = max(res, temp - dfs(l1, r1, l2, r2 - 1));
    }
    return dp[l1][r1][l2][r2] = res;
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        init();
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i) {
            scanf("%d", &a[i]);
            suma[i] += suma[i - 1] + a[i];
        }
        for(int i = 1; i <= n; ++i) {
            scanf("%d", &b[i]);
            sumb[i] += sumb[i - 1] + b[i];
        }
        printf("%d\n", dfs(1, n, 1, n));
    }
    return 0;
}