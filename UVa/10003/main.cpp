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
const int maxn = 50 + 7;
const double eps = 1E-6;

int n, L;
int a[maxn], d[maxn][maxn];

void init() {
    CLR(a, 0);
    for (int i = 0; i < maxn; ++i) {
        for (int j = 0; j < maxn; ++j) {
            i == j - 1 ? d[i][j] = 0 : d[i][j] = inf;
        }
    }
}

int main() {
    while (~scanf("%d", &L) && L) {
        init();
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &a[i]);
        }
        a[n + 1] = L;
        for (int i = 2; i <= n + 1; ++i) {
            for (int j = 0; j <= n + 1; ++j) {
                int beg = j, end = j + i;
                if (end > n + 1) continue;
                for (int k = beg; k <= end; ++k) {
                    d[beg][end] = min(d[beg][end], d[beg][k] + d[k][end] + a[end] - a[beg]);
                }
            }
        }
        printf("The minimum cutting is %d.\n", d[0][n + 1]);
    }
    return 0;
}
