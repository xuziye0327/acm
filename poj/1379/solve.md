### 题目链接
<a href="http://poj.org/problem?id=1379">HERE</a>

### 题目描述
给出x,y。在(0,0)到(x,y)的矩形区域内找到距离给出的m个点最小距离最大的点。

### 解题思路
模拟退火。
随机生成多个随机的点，然后再生成点的一定区域内再生成多个随机点，找出这些点中最优的点。

``` CPP
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#define RANDOM (rand() * 1.0) / RAND_MAX

using namespace std;

const int maxn = 1007;
const int INIF = 30;
const double pi = acos(-1);
const double eps = 1e-5;
const double inf = 1e20;

struct Point {
    double x, y, d;
    Point() : x(0), y(0), d(inf) { }
}p[maxn], op[INIF];

double dist(Point p1, Point p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int m;
        double x, y;
        scanf("%lf%lf%d", &x, &y, &m);
        for (int i = 0; i < m; ++i) {
            scanf("%lf%lf", &p[i].x, &p[i].y);
        }

        double t = sqrt(x * x + y * y);

        for (int i = 0; i < INIF; ++i) {
            op[i].x = RANDOM * x;
            op[i].y = RANDOM * y;
            op[i].d = inf;
            for (int j = 0; j < m; ++j) {
                op[i].d = min(op[i].d, dist(p[j], op[i]));
            }
        }

        while (t > eps) {
            for (int i = 0; i < INIF; ++i) {
                Point tp;
                for (int j = 0; j < INIF; ++j) {
                    double det = RANDOM * 2.0 * pi;
                    tp.x = op[i].x + t * cos(det);
                    tp.y = op[i].y + t * sin(det);
                    if (tp.x < 0 || tp.y < 0 || tp.x > x || tp.y > y) continue;
                    for (int k = 0; k < m; ++k) {
                        if (k == 0) tp.d = dist(tp, p[k]);
                        else tp.d = min(tp.d, dist(tp, p[k]));
                    }
                    if (tp.d > op[i].d) {
                        op[i] = tp;
                    }
                }
            }
            t *= 0.8;
        }
        int id = 0;
        for (int i = 1; i < INIF; ++i) {
            if (op[id].d < op[i].d) id = i;
        }
        printf("The safest point is (%.1f, %.1f).\n", op[id].x, op[id].y);
    }
    return 0;
}
```