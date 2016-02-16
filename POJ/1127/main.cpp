/* ***********************************************
Author        :myz
Created Time  :2016年02月12日 星期五 14时34分05秒
File Name     :a.cpp
************************************************ */

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Point {
    double x, y;
    Point() { }
    Point(double x_, double y_) : x(x_), y(y_) { }
};

struct Line {
    Point a, b;
};

double mult(Point a, Point b, Point c) {
    return (a.x - c.x) * (b.y - c.y) - (b.x - c.x) * (a.y - c.y);
}

bool intersect(Point aa, Point bb, Point cc, Point dd) {
    return max(aa.x, bb.x) >= min(cc.x, dd.x) && 
        max(aa.y, bb.y) >= min(cc.y, dd.y) && 
        max(cc.x, dd.x) >= min(aa.x, bb.x) && 
        max(cc.y, dd.y) >= min(aa.y, bb.y) && 
        mult(cc, bb, aa) * mult(bb, dd, aa) >= 0 &&
        mult(aa, dd, cc) * mult(dd, bb, cc) >= 0;
}

Line l[27];
int pa[27];

int findPa(int x) { return x == pa[x] ? x : pa[x] = findPa(pa[x]); }

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n;
    while (~scanf("%d", &n) && n) {
        for (int i = 1; i <= n; ++i) {
            pa[i] = i;
        }
        for (int i = 1; i <= n; ++i) {
            Point p1, p2;
            scanf("%lf%lf", &p1.x, &p1.y);
            scanf("%lf%lf", &p2.x, &p2.y);
            l[i].a = p1;
            l[i].b = p2;
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = i + 1; j <= n; ++j) {
                if (intersect(l[i].a, l[i].b, l[j].a, l[j].b)) {
                    pa[findPa(i)] = findPa(j);
                }
            }
        }
        int x, y;
        while (scanf("%d%d", &x, &y) && x) {
            printf("%s\n", findPa(x) == findPa(y) ? "CONNECTED" : "NOT CONNECTED");
        }
    }
    return 0;
}
