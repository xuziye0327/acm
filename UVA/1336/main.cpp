#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

const int maxn = 1000 + 7;

struct Pos {
    double x, c, d;
    bool operator < (const Pos& k) const {
        return x < k.x;
    }
} pos[maxn];

double sum[maxn];
double d[maxn][maxn][2];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif // ONLINE_JUDGE
    int n;
    double v, x;
    while (~scanf("%d%lf%lf", &n, &v, &x) && n) {
        for (int i = 1; i <= n; ++i) {
            scanf("%lf%lf%lf", &pos[i].x, &pos[i].c, &pos[i].d);
        }
        sort(pos + 1, pos + n + 1);
        for (int i = 1; i <= n; ++i) {
            sum[i] = sum[i - 1] + pos[i].d;
        }
        for (int i = 1; i <= n; ++i) {
            d[i][i][0] = d[i][i][1] = fabs(x - pos[i].x) / v * sum[n] + pos[i].c;
        }
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j + i <= n; ++j) {
                int l = j, r = j + i;
                double t, tl, tr;

                t = (pos[l + 1].x - pos[l].x) / v;
                tl = d[l + 1][r][0] + (sum[l] + sum[n] - sum[r]) * t + pos[l].c;
                t = (pos[r].x - pos[l].x) / v;
                tr = d[l + 1][r][1] + (sum[l] + sum[n] - sum[r]) * t + pos[l].c;
                d[l][r][0] = min(tl, tr);

                t = (pos[r].x - pos[r - 1].x) / v;
                tr = d[l][r - 1][1] + (sum[l - 1] + sum[n] - sum[r - 1]) * t + pos[r].c;
                t = (pos[r].x - pos[l].x) / v;
                tl = d[l][r - 1][0] + (sum[l - 1] + sum[n] - sum[r - 1]) * t + pos[r].c;
                d[l][r][1] = min(tl, tr);
            }
        }
        printf("%d\n", (int)min(d[1][n][0], d[1][n][1]));
    }
    return 0;
}
