#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxn = 40 + 7;

int a[7];
int ma[7][maxn];
int d[maxn][maxn][maxn][maxn];

void init() {
    memset(a, 0, sizeof(a));
    memset(d, 0, sizeof(d));
    memset(ma, 0, sizeof(ma));
}

int dp(int sta, const int n) {
    int &ans = d[a[1]][a[2]][a[3]][a[4]];
    if (ans) return ans;

    int cnt = 0;
    for (int i = 1; i <= 20; ++i)
        if (sta & (1 << i)) ++cnt;
    if (cnt == 5) return 0;

    for (int i = 1; i <= 4; ++i) {
        if (a[i] < n) {
            if (sta & (1 << (ma[i][a[i] + 1]))) {
                ++a[i];
                ans = max(ans, dp(sta ^ (1 << ma[i][a[i]]), n) + 1);
                --a[i];
            } else {
                ++a[i];
                ans = max(ans, dp(sta ^ (1 << ma[i][a[i]]), n));
                --a[i];
            }
        }
    }

    return ans;
}

int main () {
    int n;
    while (~scanf("%d", &n) && n) {
        init();
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= 4; ++j) {
                scanf("%d", &ma[j][i]);
            }
        }
        printf("%d\n", dp(0, n));
    }
    return 0;
}
