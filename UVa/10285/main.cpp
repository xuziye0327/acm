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
const int maxn = 100 + 7;
const double eps = 1E-6;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

int r, c;
int d[maxn][maxn];
char str[maxn];
int ma[maxn][maxn];

void init() {
    CLR(d, 0);
}

int dfs (int x, int y) {
    if (d[x][y]) return d[x][y];

    for (int i = 0; i < 4; ++i) {
        int tx = x + dx[i], ty = y + dy[i];
        if (tx > 0 && tx <= r && ty > 0 && ty <= c) {
            if (ma[tx][ty] < ma[x][y]) {
                d[x][y] = max(d[x][y], dfs(tx, ty) + 1);
            }
        }
    }

    return d[x][y];
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        init();
        scanf("%s%d%d", str, &r, &c);
        for (int i = 1; i <= r; ++i) {
            for (int j = 1; j <= c; ++j) {
                scanf("%d", &ma[i][j]);
            }
        }
        int res = 0;
        for (int i = 1; i <= r; ++i) {
            for (int j = 1; j <= c; ++j) {
                res = max(res, dfs(i, j));
            }
        }
        printf("%s: %d\n", str, res + 1);
    }
    return 0;
}
