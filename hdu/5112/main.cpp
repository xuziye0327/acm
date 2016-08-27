#include <iostream>
#include <cstdio>

#include <cstring>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <ctime>

#include <stack>
#include <queue>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define MP(x,y) make_pair(x,y)
#define CLR(a, b) memset(a, b, sizeof(a))
#define HERE printf("here!\n")
#define RANDOM srand((unsigned)time(NULL))

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;

const int inf = 1 << 30;
const int maxn = 10000 + 7;
const double eps = 1E-6;

struct Point {
    double t, x;
    bool operator < (const Point &k) const {
        return t < k.t;
    }
}p[maxn];

int main() {
    int T, Kase(0);
    scanf("%d", &T);
    while(T--) {
        int N;
        scanf("%d", &N);
        for(int i = 0; i < N; ++i) {
            scanf("%lf%lf", &p[i].t, &p[i].x);
        }
        sort(p, p + N);
        double res (0.0);
        for(int i = 1; i < N; ++i) {
            double t = fabs(p[i].x - p[i - 1].x) / (p[i].t - p[i - 1].t);
            if(t >= res - eps) res = t;
        }
        printf("Case #%d: %.2f\n", ++Kase, res);
    }
    return 0;
}