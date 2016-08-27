#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const double eps = 1e-8;

double dis(double x, double H, double h, double D) {
    double l = x * h / (H - h);
    if (l <= D - x - eps) return l;
    else {
        double w = l - (D - x);
        return (D - x) + w * H / (x + l);
    }
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        double H, h, D;
        scanf("%lf%lf%lf", &H, &h, &D);
        double l = 0.0, r = D;
        while (l <= r - eps) {
            double mid = (l + r) / 2.0;
            double midmid = (mid + r) / 2.0;
            double l1 = dis(mid, H, h, D);
            double l2 = dis(midmid, H, h, D);
            if (l1 >= l2 + eps) r = midmid;
            else l = mid;
        }
        printf("%.3f\n", dis((l + r) / 2.0, H, h, D));
    }
    return 0;
}
