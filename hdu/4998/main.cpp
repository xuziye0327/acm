#include <cstdio>
#include <algorithm>
#include <iostream>
#include <string.h>
#include <cmath>
#define eps 1e-8
#define zero(x) (((x) > 0 ? (x) : (-x)) < eps)
using namespace std;
const double PI = acos(-1.0);
int t,n;
struct point{
    double x,y;
};
struct line {
    point a, b;
};

point symmetric_point(point p1, point l1, point l2) {
    point ret;
    if(l1.x > l2.x - eps && l1.x < l2.x + eps) {
        ret.x = (2 * l1.x - p1.x);
        ret.y = p1.y;
    } else {
        double k = (l1.y - l2.y) / (l1.x - l2.x);
        ret.x = (2 * k *k * l1.x + 2 * k * p1.y - 2 * k * l1.y - k * k * p1.x + p1.x) / (1 + k * k);
        ret.y = p1.y - (ret.x - p1.x) / k;
    }
    return ret;
}

point intersection(point u1, point u2, point v1, point v2) {
    point ret = u1;
    double t = ((u1.x - v1.x) * (v1.y - v2.y) - (u1.y - v1.y) * (v1.x - v2.x)) /
               ((u1.x - u2.x) * (v1.y - v2.y) - (u1.y - u2.y) * (v1.x - v2.x));
    ret.x += (u2.x - u1.x) * t;
    ret.y += (u2.y - u1.y) * t;
    return ret;
}

const int maxn = 10 + 7;

double p_p[maxn];
point p_t[maxn];
point p_c_1, p_c_2, p_c_e_1, p_c_e_2;

point rota(const point p0, point p, double rad) {
    line midl;
    double k;
    double midrad;
    if(p0.x > p.x - eps && p0.x < p.x + eps) {
        midrad = rad / 2 + PI / 2;
    } else {
        midrad = rad / 2 + atan((p0.y - p.y) / (p0.x - p.x));
    }
    if(fabs(midrad) > PI / 2 - eps && fabs(midrad) < PI / 2 + eps) {
        point t_p;
        t_p.x = p0.x; t_p.y = p0.y + 1.0;
        midl.a = t_p; midl.b = p0;
        return symmetric_point(p, midl.a, midl.b);
    } else {
        k = tan(midrad);
    }
    double t_x(0.0);
    while(t_x > p0.x - eps && t_x < p0.x + eps) t_x += 1.0;
    point t_p;
    t_p.x = t_x; t_p.y = k * (t_x - p0.x) + p0.y;
    midl.a = t_p; midl.b = p0;
    return symmetric_point(p, midl.a, midl.b);
}

line p90(point p1, point p2) {
    point pt, midp;
    line ret;
    midp.x = (p1.x + p2.x) / 2.0;
    midp.y = (p1.y + p2.y) / 2.0;
    ret.a = midp;
    double k;
    if(p1.x > p2.x - eps && p1.x < p2.x + eps) {
        pt = midp; pt.y++;
        ret.b = pt;
    } else if(p1.y > p2.y - eps && p1.y < p2.y + eps) {
        pt = midp; pt.x++;
        ret.b = pt;
    } else {
        k = (p1.y - p2.y) / (p1.x - p2.x);
        k = -1.0 / k;
        pt.x = (midp.x + 1.0); pt.y = k * (pt.x - midp.x) + midp.y;
        ret.b = pt;
    }
    return ret;
}

int main(){
    scanf("%d",&t);
    while (t--){
        int n;
        scanf("%d", &n);
        double p(0.0);
        for(int i = 0; i < n; i++) {
            scanf("%lf%lf%lf", &p_t[i].x, &p_t[i].y, &p_p[i]);
            p += p_p[i];
            if(p >= 2 * PI) p -= 2 * PI;
        }
        p_c_1.x = p_c_e_1.x = 100.0; p_c_1.y = p_c_e_1.y = 100.0;
        p_c_2.x = p_c_e_2.x = 376.0; p_c_2.y = p_c_e_2.y = 279.0;
        for(int i = 0; i < n; i++) {
            p_c_e_1 = rota(p_t[i], p_c_e_1, p_p[i]);
            p_c_e_2 = rota(p_t[i], p_c_e_2, p_p[i]);
        }
        line res1, res2;
        res1 = p90(p_c_1, p_c_e_1);
        res2 = p90(p_c_2, p_c_e_2);
        point res = intersection(res1.a, res1.b, res2.a, res2.b);
        printf("%.10f %.10f %.10f\n", res.x, res.y, p);
    }
    return 0;
}