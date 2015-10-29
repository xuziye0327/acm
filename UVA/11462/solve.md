### 题目链接
<a href="https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=460&page=show_problem&problem=2457">HERE</a>

### 题目描述
输入n个(1-100)的数，从小到大排序。

### 解题思路
由于内存限制，把所有数存下来是不可能了，但可以发现要排序的数不大于100，所以可以把所有数的个数存下来。

``` cpp
#include <cstdio>
#include <cstring>

const int maxn = 107;

int cnt[maxn];

int main() {
    int n;
    while (scanf("%d", &n) && n) {
        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; i < n; ++i) {
            int x;
            scanf("%d", &x);
            ++cnt[x];
        }
        bool flag = false;
        for (int i = 1; i <= 100; ++i) {
            for (int j = 0; j < cnt[i]; ++j) {
                if (flag) printf(" ");
                flag = true;
                printf("%d", i);
            }
        }
        printf("\n");
    }
    return 0;
}
```