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

const int inf = 1 << 27;
const ull INF = 1ULL << 57ULL;
const int maxn = 20 + 7;
const double eps = 1E-6;

void init() {
}

double dis(double xa, double ya, double xb, double yb) {
    return sqrt((xa - xb) * (xa - xb) + (ya - yb) * (ya - yb));
}

int main() {
    int n;
    while (scanf("%d", &n) && n) {
        double x, xa, ya, xb, yb;
        scanf("%lf%lf%lf%lf", &xa, &ya, &xb, &yb);
        double s(0.0), l(0.0);
        for (int i = 0; i < n; ++i) {
            scanf("%lf", &x);
            l += x;
            s += x * x / 2.0;
        }
        double k1 = ya / xa, k2 = yb / xb;
        if (k1 > k2) swap(k1, k2);
        double x1 = (k2 + 1.0) * l / (k2 - k1), y1 = x1 * k1;
        double x2 = (k1 + 1.0) * l / (k2 - k1), y2 = x2 * k2;
        double S = (x1 * y2 - x2 * y1) / 2.0;
        printf("%.3f\n", S - s);
    }
    return 0;
}
