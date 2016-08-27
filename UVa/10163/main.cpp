#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxn = 30 + 7;

int ans;
int P[maxn];
int d[maxn][maxn * 3];
int g[maxn][maxn * 3];

int main () {
    int n, m;
    while (scanf("%d%d", &n, &m) && n) {
        memset(d, 0, sizeof(d));
        memset(g, 0xf, sizeof(g));
        for (int i = 1; i <= m; ++i) {
            scanf("%d", &P[i]);
        }
        for (int i = 1; i <= m; ++i) {
            d[i - 1][0] = 0xfffff;
            for (int j = 1; j <= n; ++j) {
                d[i][j] = d[i - 1][j];
                for (int k = 1; k <= j; ++k) {
                    d[i][j] = max(d[i][j], min(d[i - 1][j - k], P[i] / k));
                }
            }
        }
        for (int i = 1; i <= m; ++i) {
            g[i - 1][0] = 0;
            for (int j = 1; j <= n; ++j) {
                g[i][j] = g[i - 1][j];
                for (int k = 1; k <= j; ++k) {
                    if (P[i] / k >= d[m][n])
                        g[i][j] = min(g[i][j], g[i - 1][j - k] + P[i]);
                }
            }
        }
        printf("%d %d\n", d[m][n], d[m][n] == 0 ? 0 : g[m][n]);
    }
    return 0;
}
