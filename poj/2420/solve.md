### 题目链接
<a href="http://poj.org/problem?id=2420">HERE</a>

### 题目描述
求平面上一坐标到给出的n个点距离和最短。

### 解题思路
模拟退火水题。

``` cpp
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;

const int maxn = 107;
const double T = 100.0;
const double inf = 1e9;
const double eps = 1e-9;
const double delt = 0.99;
const double dx[] = {0.0, 0.0, -1.0, 1.0};
const double dy[] = {-1.0, 1.0, 0.0, 0.0};

struct Point {
    double x, y;
}p[maxn];

int n;

double dist(Point p1, Point p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

double getSum(Point t) {
    double sum = 0.0;
    for (int i = 0; i < n; ++i) {
        sum += dist(t, p[i]);
    }
    return sum;
}

int main() {
    while (~scanf("%d", &n)) {
        for (int i = 0; i < n; ++i) {
            scanf("%lf%lf", &p[i].x, &p[i].y);
        }
        Point s = p[0];
        double t = T;
        double ans = inf;
        while (t > eps) {
            bool flag = false;
            for (int i = 0; i < 4; ++i) {
                Point tp = s;
                tp.x += dx[i] * t;
                tp.y += dy[i] * t;
                double sum = getSum(tp);
                if (sum < ans + eps) {
                    ans = sum;
                    s = tp;
                    flag = true;
                }
            }
            t *= delt;
        }
        printf("%.0f\n", ans);
    }
    return 0;
}
```