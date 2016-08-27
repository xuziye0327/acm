### 题目链接
<a href="https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=460&page=show_problem&problem=2544">HERE</a>

### 题目描述
给出n和k，每次取k*k的前n位，记为k。求k的最大值。

### 解题思路
不难想到k的取值这肯定是个循环。当出现循环时跳出就可以。
这个过程可以用set来操作。但是还有个更巧妙的方法：Floyd判圈法。
Floyd判圈法：想象两个小盆友跑步，设为k1和k2。k2的速度是k1的两倍。如果跑道有环那么k2肯定会追上k1。根据这个思想，就可以判断循环的结束（当k2追上k1时结束）。

``` cpp
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
```