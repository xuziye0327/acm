#include <cstdio>

typedef unsigned long long ull;

const int maxn = 63 + 7;

ull d[maxn][maxn];

int main () {
    for (int i = 1; i < maxn; ++i) {
        for (int j = 1; j < maxn; ++j) {
            d[i][j] = d[i - 1][j - 1] + 1ull + d[i][j - 1];
        }
    }
    ull k, n;
    while (scanf("%llu%llu", &k, &n) && k) {
        bool flag = false;
        if (k > 63) k = 63;
        for (int i = 0; i <= 63; ++i) {
            if (d[k][i] >= n) {
                printf("%d\n", i);
                flag = true;
                break;
            }
        }
        if (!flag) printf("More than 63 trials needed.\n");
    }
    return 0;
}
