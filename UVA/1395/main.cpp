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
const int maxn = 100 + 7;

struct Edge{
    int u, v, w;
    bool operator < (const Edge &k) const {
        return w < k.w;
    }
}edge[maxn * maxn];

int n, m, res;
int fa[maxn];

void init_union_find() {
    for (int i = 0; i < maxn; ++i) {
        fa[i] = i;
    }
}

int fin(int x) { return  x == fa[x] ? x : fa[x] = fin(fa[x]); }

bool check() {
    int pos;
    for (int i = 1; i <= n; ++i) {
        if(i == 1) pos = fin(i);
        else if(pos != fin(i)) return false;
    }
    return true;
}

void solve() {
    sort(edge, edge + m);
    res = inf;
    for (int i = 0; i < m; ++i) {
        Edge e = edge[i];
        init_union_find();
        fa[e.u] = e.v;
        for (int j = i + 1; j <= m; ++j) {
            if(check()) {
                res = min(res, edge[j - 1].w - edge[i].w);
                break;
            }
            if (j == m) break;
            e = edge[j];
            int x = fin(e.u), y = fin(e.v);
            if(x == y) continue;
            fa[x] = y;
        }
    }
}

int main() {
    while (scanf("%d%d", &n, &m) && n){
        for (int i = 0; i < m; ++i) {
            Edge &e = edge[i];
            scanf("%d%d%d", &e.u, &e.v, &e.w);
        }
        solve();
        printf("%d\n", res < inf ? res : -1);
    }
    return 0;
}
