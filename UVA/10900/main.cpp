#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 30 + 7;

double res[maxn];

int main() {
    int n;
    double t;
    while (scanf("%d%lf", &n, &t) && n) {
        res[n] = 1 << n;
        for (int i = n - 1; i >= 0; --i) {
            double p0 = (1 << i) / res[i + 1];
            p0 = max(t, p0);
            double p1 = (p0 - t) / (1.0 - t);
            res[i] = (1 << i) * p1 + (1.0 + p0) / 2.0 * res[i + 1] * (1.0 - p1);
        }
        printf("%.3f\n", res[0]);
    }
    return 0;
}
