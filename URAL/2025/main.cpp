#include <cstdio>
#include <cstring>
#include <cmath>

const int maxn = 10000 + 7;

typedef unsigned long long ull;

int T, n, k;
ull ans[maxn];

int main() {
    scanf("%d", &T);
    while(T--) {
        ull res(0);
        scanf("%d%d", &n, &k);
        for(int i = 0; i < k; ++i) {
            ans[i] = n / k;
            if(i < n % k) ++ans[i];
        }
        for(int i = 0; i < k; ++i) {
            n -= ans[i];
            res += ans[i] * n;
        }
        printf("%I64u\n", res);
    }
    return 0;
}