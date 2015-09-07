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

const int inf = 1 << 30;
const int maxn = 1000 + 7;
const double eps = 1E-6;

int n, m, t, tot, cnt;
int from[maxn];
int A[maxn][maxn], B[maxn][maxn];
char ma[maxn][maxn];
bool used[maxn];
vector<int> G[maxn];

void init () {
    cnt = 0;
    CLR(A, 0);
    CLR(B, 0);
    CLR(ma, 0);
    for (int i = 0; i < maxn; ++i) G[i].clear();
}

bool match(int x) {
    for (int i = 0; i < G[x].size(); ++i) {
        int u = G[x][i];
        if (!used[u]) {
            used[u] = true;
            if (from[u] == -1 || match(from[u])) {
                from[u] = x;
                return true;
            }
        }
    }
    return false;
}

int hungary() {
    tot = 0;
    CLR(from, -1);

    for (int i = 1; i <= cnt; ++i) {
        CLR(used, false);
        if (match(i)) ++tot;
    }
    return tot;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        init ();
        scanf("%d%d", &n, &m);
        int x, y;
        scanf("%d", &t);
        while (t--) {
            scanf("%d%d", &x, &y);
            ma[x][y] = '*';
        }
        scanf("%d", &t);
        while (t--) {
            scanf("%d%d", &x, &y);
            ma[x][y] = '#';
        }
        bool last = false;
        t = 1;
        for (int i = 1; i <= n; ++i) {
            bool ok = false;
            for (int j = 1; j <= m; ++j) {
                if (j == 1 && last) { ++t; last = false; }
                if (ma[i][j] == '*') { A[i][j] = t; ok = true; }
                if (ma[i][j] == '#' && ok) { ++t; ok = false; }
            }
            if (ok) last = true;
        }
        cnt = t;
        t = 1;
        last = false;
        for (int i = 1; i <= m; ++i) {
            bool ok = false;
            for (int j = 1; j <= n; ++j) {
                if (j == 1 && last) { ++t; last = false; }
                if (ma[j][i] == '*') { B[j][i] = t; ok = true; }
                if (ma[j][i] == '#' && ok) { ++t; ok = false; }
            }
            if (ok) last = true;
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (A[i][j] && B[i][j]) G[A[i][j]].push_back(B[i][j]);
            }
        }
        printf("%d\n", hungary());
    }
    return 0;
}
