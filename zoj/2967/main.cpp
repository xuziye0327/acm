#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <stack>
#include <map>

using namespace std;

const int inf = 1 << 30;
const int maxn = 5000 + 7;
const double eps = 1e-6;

struct Line{
    double a, b, x;
    Line(double a_, double b_, double x_) : a(a_), b(b_), x(x_) {}
};

int n;
map<double, double> L;
stack<Line> sta;

void init() {
    L.clear();
}

double cross(double k1, double b1, double k2, double b2) {
    return (b2 - b1) / (k1 - k2);
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        init();
        scanf("%d", &n);
        for(int i = 0; i < n; ++i) {
            double a, b;
            scanf("%lf%lf", &a, &b);
            if(!L.count(a)) L[a] = b;
            else L[a] = max(L[a], b);
        }
        map<double, double> :: iterator it = L.begin();
        sta.push(Line((*it).first, (*it).second, inf * (-1.0)));
        for( ++it; it != L.end(); ++it) {
            double k1 = (*it).first, b1 = (*it).second;
            while(!sta.empty()) {
                Line l = sta.top();
                double k2 = l.a, b2 = l.b;
                double x = cross(k1, b1, k2, b2);
                if (x <= l.x + eps) sta.pop();
                else { sta.push(Line(k1, b1, x)); break; }
            }
            if(sta.empty()) sta.push(Line(k1, b1, inf * (-1.0)));
        }
        int cnt(0);
        while(!sta.empty()) { ++cnt; sta.pop(); }
        printf("%d\n", cnt);
    }
    return 0;
}