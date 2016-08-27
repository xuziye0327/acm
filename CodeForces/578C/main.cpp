#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdlib>

using namespace std;

const int maxn = 200007;
const int  inf = 1 << 27;
const double EPS = 1e-6;

int n;
double a[maxn], sum[maxn];

double solve(double t) {
    double minn = 0, maxx = 0, tmaxx = 0, tminn = 0;

    for (int i = 1; i <= n; ++i) {
        sum[i] = sum[i - 1] + a[i] - t;
        maxx = max(maxx, sum[i] - tminn);
        minn = min(minn, sum[i] - tmaxx);
        tmaxx = max(tmaxx, sum[i]);
        tminn = min(tminn, sum[i]);
    }

    return max(fabs(maxx), fabs(minn));
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%lf", &a[i]);
    }

    double l = -1e4, r = 1e4;
    double eps = EPS / n;

    while (l < r - eps) {
        double mid = (l + r) / 2.0;
        double midmid = (mid + r) / 2.0;
        double t1 = solve(mid);
        double t2 = solve(midmid);

        if (t1 < t2) {
            r = midmid;
        } else {
            l = mid;
        }
    }

    printf("%.6f\n", solve((l + r) / 2.0));
    return 0;
}
