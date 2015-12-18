#include <cstdio>
#include <algorithm>

using namespace std;

typedef unsigned long long ull;

ull next(ull d, ull k) {
    k = k * k;
    while (k >= d) k /= 10ull;
    return k;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        ull k, d(1);
        scanf("%d%llu", &n, &k);
        while (n--) d *= 10ull;
        ull ans = k;
        ull k1 = k, k2 = k;
        while (true) {
            k1 = next(d, k1);
            k2 = next(d, k2);
            ans = max(ans, k2);
            k2 = next(d, k2);
            ans = max(ans, k2);
            if (k1 == k2) break;
        }
        printf("%llu\n", ans);
    }
    return 0;
}
