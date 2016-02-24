#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

const int maxn = 37;
const double eps = 1e-9;

struct Point {
    double x, y;
} p[maxn];

int n;

double dist(Point p1, Point p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

Point whirl(Point p0, Point p, double d) {
    double x = (p.x - p0.x) * cos(d) - (p.y - p0.y) * sin(d) + p0.x;
    double y = (p.x - p0.x) * sin(d) + (p.y - p0.y) * cos(d) + p0.y;
    Point rp;
    rp.x = x;
    rp.y = y;
    return rp;
}

double solve(double d) {
    Point tp[maxn];
    for (int i = 0; i < n; ++i) {
        tp[i] = p[i];
    }
    for (int i = 1; i < n; ++i) {
        tp[i] = whirl(tp[0], tp[i], d);
    }
    double l = 0.0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            l = max(l, max(fabs(tp[i].x - tp[j].x), fabs(tp[i].y - tp[j].y)));
        }
    }
    return l * l;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {

        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%lf%lf", &p[i].x, &p[i].y);
        }

        double l = 0.0, r = 360.0;
        while (l < r - eps) {
            double mid = (l + r) / 2.0;
            double midmid = (mid + r) / 2.0;
            double d1 = solve(mid);
            double d2 = solve(midmid);
            if (d1 > d2 + eps) l = mid;
            else r = midmid;
        }

        printf("%.2f\n", solve((l + r) / 2.0));
    }
    return 0;
}
