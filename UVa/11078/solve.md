### 题目链接
<a href="https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=460&page=show_problem&problem=2019">HERE</a>

### 题目描述
给出长度为n的整数序列，找出A[i]-A[j]最大。

### 解题思路
创建一个数组维护A[i+1]-A[n-1]中的最小值。

``` cpp
#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 100007;

int A[maxn];
int B[maxn];

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &A[i]);
            B[i] = A[i];
        }
        for (int i = n - 2; i >= 0; --i) {
            B[i] = min(B[i], B[i + 1]);
        }
        int ans = -300007;
        for (int i = 0; i < n - 1; ++i) {
            ans = max(ans, A[i] - B[i + 1]);
        }
        printf("%d\n", ans);
    }
    return 0;
}
```