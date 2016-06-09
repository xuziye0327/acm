### 题目连接
<a href="http://acm.hdu.edu.cn/showproblem.php?pid=1392">HERE</a>

### 题目描述
n棵树，求要把这些树包围起来所需的最小周长。

### 解题思路
求凸包，有坑点，n = 2的时候输出两点距离就行。

''' cpp
/* ***********************************************
Author        :xuziye0327
Created Time  :2016年06月08日 星期三 19时24分10秒
File Name     :main.cpp
************************************************ */

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

const int maxn = 107;

struct Point {
	double x, y;
	Point(double x = 0, double y = 0) : x(x), y(y) {}
	bool operator < (const Point &k) const {
		return x == k.x ? y < k.y : x < k.x;
	}
	Point operator - (const Point& a) {
		return Point(x - a.x, y - a.y);
	}
}point[maxn], ans[maxn];

double Cross(Point a, Point b) { return a.x * b.y - a.y * b.x; }

int ConvexHull(Point *p, int n, Point* ch) {
	sort(p, p + n);
	int m = 0;
	for (int i = 0; i < n; ++i) {
		while (m > 1 && Cross(ch[m - 1] - ch[m - 2], p[i] - ch[m - 2]) <= 0) --m;
		ch[m++] = p[i];
	}
	int k = m;
	for (int i = n - 2; i >= 0; --i) {
		while (m > k && Cross(ch[m - 1] - ch[m - 2], p[i] - ch[m - 2]) <= 0) --m;
		ch[m++] = p[i];
	}
	if (n > 1) --m;
	return m;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	int n;
	while (scanf("%d", &n) && n) {
	 	for (int i = 0; i < n; ++i) {
			scanf("%lf%lf", &point[i].x, &point[i].y);
		}
		int m = ConvexHull(point, n, ans);
		double dis = 0;
		for (int i = 0; i < m; ++i) {
			Point a = ans[i], b = ans[(i + 1) % m]; 
			dis += sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
		}
		printf ("%.2lf\n", n == 2 ? dis / 2.0 : dis);
	}
    return 0;
}

'''
