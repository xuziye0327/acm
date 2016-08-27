#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

typedef unsigned long long ull;

const int maxn = 2007;

int d[maxn];
int a[maxn], b[maxn], w[maxn];

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int m, n;
        memset(d, 0, sizeof(d));
        scanf("%d%d", &m, &n);
        for (int i = 1; i <= n; ++i) {
            scanf("%d%d%d", &w[i], &a[i], &b[i]);
            for (int j = m; j >= w[i]; --j) {
                d[j] = max(d[j], d[j - w[i]] + a[i] + b[i]);
            }
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= m; ++j) {
                if (j >= w[i]) d[j] = max(d[j], d[j - w[i]] + a[i]);
            }
        }
        int ans = 0;
        for (int i = 0; i <= m; ++i) ans = max(ans, d[i]);
        printf("%d\n", ans);
    }
    return 0;
}
