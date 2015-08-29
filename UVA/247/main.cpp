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
const int maxn = 25 + 7;
const double eps = 1E-6;

int n, m;
bool used[maxn];
bool G[maxn][maxn];
map<string, int> map1;
map<int, string> map2;

void init() {
    map1.clear();
    map2.clear();
    CLR(G, false);
    CLR(used, false);
}

void Floyd() {
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (G[i][k] && G[k][j]) G[i][j] = true;
            }
        }
    }
}

void dfs(int pos, int d) {
    if (d) printf(", ");
    cout << map2[pos];
    used[pos] = true;
    for (int i = 1; i <= n; ++i) if (!used[i] && G[i][pos] && G[pos][i]) {
            dfs(i, d + 1);
    }
}

int main() {
    int Kase(0);
    while (scanf("%d%d", &n, &m) && n) {
        init();
        if (Kase) printf("\n");
        for (int i = 0; i < m; ++i) {
            string t1, t2;
            cin >> t1 >> t2;
            if (!map1.count(t1)) {
                map1[t1] = map1.size();
                map2[map1[t1]] = t1;
            }
            if (!map1.count(t2)) {
                map1[t2] = map1.size();
                map2[map1[t2]] = t2;
            }
            G[map1[t1]][map1[t2]] = true;
        }
        Floyd();
        printf("Calling circles for data set %d:\n", ++Kase);
        for (int i = 1; i <= n; ++i) {
            if (!used[i]) {
                dfs(i, 0);
                printf("\n");
            }
        }
    }
    return 0;
}
