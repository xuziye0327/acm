### 题目链接
<a href="http://acm.hdu.edu.cn/showproblem.php?pid=2438">HERE</a>

### 题目描述
给出一个直角路口和一辆车的信息，问这辆车能否拐过去。

### 解题思路
不会画图就不画了。
让汽车贴着墙的时候转弯，设已经转过的角度为d，那么就可以求出左上的那个点到汽车上边的距离，找出这个距离的最小值，如果最小值小于零，车不能通过。

``` cpp
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

const double eps = 1e-9;

double solve(double d, double x, double y, double l, double w) {
    double L = x / cos(d);
    double l1 = y - x * tan(d);
    double l2 = (l * cos(d) - l1) * sin(d);
    return L - w - l2;
}

int main() {
    double x, y, l, w;
    while (~scanf("%lf%lf%lf%lf", &x, &y, &l, &w)) {
        double L = 0.0, R = acos(-1) / 2.0;
        bool flag = true;
        while (L <= R - eps) {
            double mid = (L + R) / 2.0;
            double midmid = (mid + R) / 2.0;
            double l1 = solve(mid, x, y, l, w);
            double l2 = solve(midmid, x, y, l, w);
            if (l1 >= l2 + eps) L = mid;
            else R = midmid;
        }
        if (solve((L + R) / 2.0, x, y, l, w) >= eps) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}
```