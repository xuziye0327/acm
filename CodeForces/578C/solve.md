### 题目链接
<a href="http://codeforces.com/problemset/problem/578/C">HERE</a>

### 题目描述
给出一个序列，找到一数k，使整个序列所有子区间内和的最大绝对值最小。

### 解题思路
很容易就想到要求的是整个序列减去一个k后，连续区间和的最大最小值。
然后三分判断k的取值。
此题最需要注意的一点是eps的取值跟n的大小有关。
如果eps太大，则会超时；太小就会wa。

``` cpp
#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdlib>

using namespace std;

const int maxn = 200007;
const int  inf = 1 << 27;
const double EPS = 1e-6;

int n;
double a[maxn], sum[maxn];

double solve(double t) {
    double minn = 0, maxx = 0, tmaxx = 0, tminn = 0;

    for (int i = 1; i <= n; ++i) {
        sum[i] = sum[i - 1] + a[i] - t;
        maxx = max(maxx, sum[i] - tminn);
        minn = min(minn, sum[i] - tmaxx);
        tmaxx = max(tmaxx, sum[i]);
        tminn = min(tminn, sum[i]);
    }

    return max(fabs(maxx), fabs(minn));
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%lf", &a[i]);
    }

    double l = -1e4, r = 1e4;
    double eps = EPS / n;

    while (l < r - eps) {
        double mid = (l + r) / 2.0;
        double midmid = (mid + r) / 2.0;
        double t1 = solve(mid);
        double t2 = solve(midmid);

        if (t1 < t2) {
            r = midmid;
        } else {
            l = mid;
        }
    }

    printf("%.6f\n", solve((l + r) / 2.0));
    return 0;
}
```