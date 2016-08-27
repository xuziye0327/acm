#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

const double eps = 1e-9;

double solve(double d, double x, double y, double l, double w) {
    double L = x / cos(d);
    double l1 = y - x * tan(d);
    double l2 = (l * cos(d) - l1) * sin(d);
    return L - w - l2;
}

int main() {
    double x, y, l, w;
    while (~scanf("%lf%lf%lf%lf", &x, &y, &l, &w)) {
        double L = 0.0, R = acos(-1) / 2.0;
        bool flag = true;
        while (L <= R - eps) {
            double mid = (L + R) / 2.0;
            double midmid = (mid + R) / 2.0;
            double l1 = solve(mid, x, y, l, w);
            double l2 = solve(midmid, x, y, l, w);
            if (l1 >= l2 + eps) L = mid;
            else R = midmid;
        }
        if (solve((L + R) / 2.0, x, y, l, w) >= eps) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}
