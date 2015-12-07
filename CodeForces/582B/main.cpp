#include <bits/stdc++.h>

using namespace std;

const int maxn = 107;
const int  inf = 1 << 27;

int n, T;
int a[maxn];
int ma[maxn][maxn];

void mul(int t1[maxn][maxn], int t2[maxn][maxn]) {
    int t[maxn][maxn], ret[maxn][maxn];
    memset(t, 0, sizeof(t));
    memset(ret, 0, sizeof(ret));

    for (int j = 1; j <= n; ++j) {
        for (int i = 1; i <= n; ++i) {
            for (int k = 1; k <= n; ++k) {
                if (a[i] <= a[k] && a[k] <= a[j]) {
                    t[i][j] = max(t[i][j], t2[k][j]);
                }
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            for (int k = 1; k <= n; ++k) {
                if (a[i] <= a[k] && a[k] <= a[j]) {
                    ret[i][j] = max(ret[i][j], t1[i][k] + t[k][j]);
                }
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            t1[i][j] = ret[i][j];
        }
    }
}

int solve(int t) {
    int ret[maxn][maxn];
    memset(ret, 0, sizeof(ret));

    while (t) {
        if (t & 1) {
            mul(ret, ma);
        }
        mul(ma, ma);
        t >>= 1;
    }

    int ans = 0;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            ans = max(ans, ret[i][j]);
        }
    }

    return ans;
}

int main() {
    memset(a, 0, sizeof(a));
    memset(ma, 0, sizeof(ma));
    scanf("%d%d", &n, &T);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; ++i) {
        ma[i][i] = 1;
        for (int j = i + 1; j <= n; ++j) {
            for (int k = i; k < j; ++k) {
                if (a[i] <= a[k] && a[k] <= a[j]) {
                    ma[i][j] = max(ma[i][j], ma[i][k] + 1);
                }
            }
        }
    }
    printf("%d", solve(T));
    return 0;
}
