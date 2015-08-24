#include <bits/stdc++.h>

using namespace std;

const int maxn = 1000 + 7;

int n;

struct gamer {
    double x, y;
    int t;
    bool operator < (const gamer &k) const {
        return t < k.t;
    }
}g[maxn];

double length(const gamer &k1, const gamer &k2) {
    return sqrt((k1.x - k2.x) * (k1.x - k2.x) + (k1.y - k2.y) * (k1.y - k2.y));
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        for(int i = 0; i < n; i++) {
            scanf("%d%lf%lf", &g[i].t, &g[i].x, &g[i].y);
        }
        sort(g, g + n);
        double res(0.0);
        for(int i = 1; i < n; i++) {
            res = max(res, length(g[i], g[i - 1]) / (g[i].t - g[i - 1].t));
        }
        printf("%.10f\n", res);
    }
    return 0;
}