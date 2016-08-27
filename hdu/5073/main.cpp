#include <bits/stdc++.h>

using namespace std;

const int maxn = 50000 + 7;

int n, k;
double a[maxn];
double sum1[maxn], sum2[maxn];

void init() {
    memset(a, 0, sizeof(a));
    memset(sum1, 0, sizeof(sum1));
    memset(sum2, 0, sizeof(sum2));
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        init();
        scanf("%d%d", &n, &k);
        for(int i = 1; i <= n; i++) {
            scanf("%lf", &a[i]);
        }
        sort(a + 1, a + n + 1);
        for(int i = 1; i <= n; i++) {
            sum1[i] = sum1[i - 1] + a[i];
            sum2[i] = sum2[i - 1] + a[i] * a[i];
        }
        double res(1e20);
        if(n == k) { res = 0.0; }
        else {
            for(int i = 1; i <= k + 1; i++) {
                double s1 = sum1[i + n - k - 1] - sum1[i - 1];
                double s2 = sum2[i + n - k - 1] - sum2[i - 1];
                double ans = s2 - s1 * s1 / (n - k);
                res = min(res, ans);
            }
        }
        printf("%.10f\n", res);
    }
    return 0;
}