#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const double eps = 1e-9;
const double inf = 1e9;

struct Point {
    double x, y;
    Point() : x(0.0), y(0.0) { }
    Point(double x_, double y_) : x(x_), y(y_) { }
    bool operator == (const Point p) const {
        return fabs(x - p.x) < eps && fabs(y - p.y) < eps;
    }
}a, b, c, d;

double p, q, r;

double dist(Point p1, Point p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

Point getMidPoint(Point p1, Point p2) {
    return Point((p1.x + p2.x) / 2.0, (p1.y + p2.y) / 2.0);
}

double getDist(Point p1, Point p2) {
    return dist(p1, p2) / r + dist(p2, d) / q;
}

double solve(Point tp) {
    double l1 = dist(tp, a) / p;
    Point lp = c;
    Point rp = d;
    while (true) {
        Point mid = getMidPoint(lp, rp);
        Point midmid = getMidPoint(mid, rp);
        if (mid == midmid) break;
        double t1 = getDist(tp, mid);
        double t2 = getDist(tp, midmid);
        if (t1 < t2 - eps) rp = midmid;
        else lp = mid;
    }
    return l1 + getDist(tp, getMidPoint(lp, rp));
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%lf%lf%lf%lf", &a.x, &a.y, &b.x, &b.y);
        scanf("%lf%lf%lf%lf", &c.x, &c.y, &d.x, &d.y);
        scanf("%lf%lf%lf", &p, &q, &r);
        Point lp = a;
        Point rp = b;
        while (true) {
            Point mid = getMidPoint(lp, rp);
            Point midmid = getMidPoint(mid, rp);
            if (mid == midmid) break;
            double t1 = solve(mid);
            double t2 = solve(midmid);
            if (t1 < t2 - eps) rp = midmid;
            else lp = mid;
        }
        printf("%.2f\n", solve(getMidPoint(lp, rp)));
    }
    return 0;
}
