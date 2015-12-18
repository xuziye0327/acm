#include <bits/stdc++.h>

using namespace std;

const int maxn = 10001;
const int  mod = 10007;

typedef long long ll;

int d[maxn], cnt[maxn];

int main() {
    int n;
    while (~scanf("%d", &n)) {
        memset(d, 0, sizeof(d));
        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; i < n; ++i) {
            int x;
            scanf("%d", &x);
            ++cnt[x];
        }
        for (int i = 2; i < maxn; ++i) {
            for (int j = i; j < maxn; j += i) {
                d[i] += cnt[j];
            }
            d[i] *= d[i];
        }
        int ans = 0;
        for (int i = maxn - 1; i > 1; --i) {
            for (int j = i + i; j < maxn; j += i) {
                d[i] -= d[j];
            }
            ans = (ans + (ll)i * (i - 1) * d[i] % mod) % mod;
        }
        printf("%d\n", ans);
    }
    return 0;
}
