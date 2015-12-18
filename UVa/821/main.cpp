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
#define BLANK bool blank = false
#define RANDOM srand((unsigned)time(NULL))

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;
typedef pair<double, double> PP;

const int inf = 1 << 27;
const ull INF = 1ULL << 57ULL;
const int maxn = 100 + 7;
const double eps = 1E-6;

int cnt;
double d[maxn][maxn];
map<int, int> table;

void init() {
    cnt = 0;
    table.clear();
    for (int i = 0; i < maxn; ++i)
        for (int j = 0; j < maxn; ++j) d[i][j] = (i == j ? 0.0 : (double)inf);
}

int main() {
    int x, y, Kase(0);
    while (scanf("%d%d", &x, &y) && x) {
        init();
        if (!table.count(x)) table[x] = (int)table.size();
        if (!table.count(y)) table[y] = (int)table.size();
        d[table[x]][table[y]] = 1.0;
        while (scanf("%d%d", &x, &y) && x) {
            if (!table.count(x)) table[x] = (int)table.size();
            if (!table.count(y)) table[y] = (int)table.size();
            d[table[x]][table[y]] = 1.0;
        }
        for (int k = 1; k <= table.size(); ++k) {
            for (int i = 1; i <= table.size(); ++i) {
                for (int j = 1; j <= table.size(); ++j) {
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                }
            }
        }
        double res(0.0), ecnt(0.0);
        for (int i = 1; i <= table.size(); ++i) {
            for (int j = 1; j <= table.size(); ++j) {
                if (i == j) continue ;
                res += d[i][j];
                ecnt += 1.0;
//                printf("d[i][j] = %.2f\n", d[i][j]);
            }
        }
        printf("Case %d: average length between pages = %.3f clicks\n", ++Kase, res / ecnt);
    }
    return 0;
}
