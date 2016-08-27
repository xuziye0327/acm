### 题目链接
<a href="http://acm.hdu.edu.cn/showproblem.php?pid=5212">HERE</a>

### 题目描述
给出n个数，求每两个数的gcd(a[i],a[j])*(gcd(a[i],a[j])-1)之和。

### 解题思路
如果gcd=x的数有k个，那么res就应该加上x*(x-1)*k^2个。
怎样求出gcd为x的数有多少个呢？
首先对于一个数x，能被它整除的数有k1个，然后对于2*x，能被它整除的数有k2个，以此类推。
那么gcd=x的数就有k1-k2-k3-k4...个。

``` cpp
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
```