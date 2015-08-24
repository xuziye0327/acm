#include <bits/stdc++.h>

using namespace std;

const double ips = 1e-7;
const int maxn = 50 + 7;

double a[maxn];

bool cmp(const double &k1, const double &k2)  {
    return k1 > k2 + ips;
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        for(int i = 0; i < n; i++) {
            scanf("%lf", &a[i]);
        }
        sort(a, a + n, cmp);
        double sum(0);
        for(int i = 0; i < n; i++) {
            double t(1.0);
            for(int j = 0; j < i; j++) t *= 0.95;
            sum += a[i] * t;
        }
        printf("%.10f\n", sum);
    }
    return 0;
}