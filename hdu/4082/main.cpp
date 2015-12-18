#include <iostream>
#include <cstdio>
#include <set>
#include <cstring>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;

typedef pair<int, int> P;

const int inf = 1e6;
const double eps = 1e-6;
const int maxn = 18 + 7;

int n;
int co[3];
P point[maxn];
set<P> s;
map<pair<pair<int, int>, int>, int> ma;

double dist(P p1, P p2) {
    double x1 = (double) p1.first, y1 = (double) p1.second;
    double x2 = (double) p2.first, y2 = (double) p2.second;
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main() {
    while(~scanf("%d", &n) && n) {
        memset(point, 0, sizeof(point));
        int cnt(0), res(0);
        ma.clear();
        s.clear();
        for(int i = 0; i < n; ++i) {
            int x, y;
            scanf("%d%d", &x, &y);
            if(s.count(make_pair(x, y))) continue;
            s.insert(make_pair(x, y));
            point[cnt++] = make_pair(x, y);
        }
        sort(point, point + cnt);
        for(int i = 0; i < cnt; ++i) {
            for(int j = i + 1; j < cnt; ++j) {
                for(int k = j + 1; k < cnt; ++k) {
                    double a = dist(point[i], point[j]);
                    double b = dist(point[i], point[k]);
                    double c = dist(point[k], point[j]);
                    if(a + b <= c + eps || b + c <= a + eps || a + c <= b + eps) continue;
                    co[0] = ((b * b + c * c - a * a) / (2.0 * b * c) * inf);
                    co[1] = ((b * b + a * a - c * c) / (2.0 * b * a) * inf);
                    co[2] = ((c * c + a * a - b * b) / (2.0 * a * c) * inf);
                    sort(co, co + 3);
                    if(!ma.count(make_pair(make_pair(co[0], co[1]), co[2]))) ma[make_pair(make_pair(co[0], co[1]), co[2])] = 1;
                    else ++ma[make_pair(make_pair(co[0], co[1]), co[2])];
                }
            }
        }
        map<pair<pair<int, int>, int>, int> :: iterator it = ma.begin();
        for(; it != ma.end(); it++) {
            res = max(res, (*it).second);
        }
        printf("%d\n", res);
    }
    return 0;
}