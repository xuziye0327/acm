#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxn = 200 + 7;

int a[maxn];
int d[maxn][maxn][maxn];

int dp(int l, int r, int k) {
    if (l > r) return 0;
    if (d[l][r][k]) return d[l][r][k];

    int p = r;
    for ( ; ; ) {
        if (a[p - 1] != a[p]) break;
        --p;
    }

    d[l][r][k] = dp(l, p - 1, 0) + (r - p + 1 + k) * (r - p + 1 + k);

    for (int q = p - 1; q >= l; --q) {
        if (a[q] == a[r] && a[q] != a[q + 1]) {
            d[l][r][k] = max(d[l][r][k], dp(q + 1, p - 1, 0) + dp(l, q, r - p + 1 + k));
        }
    }

    return d[l][r][k];
}

int main () {
    int T, Case(0);
    scanf("%d", &T);
    while (T--) {
        memset(a, 0, sizeof(a));
        memset(d, 0, sizeof(d));
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
        printf("Case %d: %d\n", ++Case, dp(1, n, 0));
    }
    return 0;
}
