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
const int maxn = (int)1E5 + 7;
const double eps = 1E-6;

int n, t;
vector<int> son[maxn];

void init() {
    for (int i = 0; i < maxn; ++i) son[i].clear();
}

int dp (int u) {
    if (!son[u].size()) return 1;
    int len = son[u].size();
    vector<int> d;
    for (int i = 0; i < len; ++i) {
        d.push_back(dp(son[u][i]));
    }
    sort(d.begin(), d.end());
    int c = len * t;
    (c % 100) ? c = c / 100 + 1 : c /= 100;
    int ans(0);
    for (int i = 0; i < c; ++i) {
        ans += d[i];
    }
    return ans;
}

int main() {
    while (scanf("%d%d", &n, &t) && n) {
        init();
        for (int i = 1; i <= n; ++i) {
            int p;
            scanf("%d", &p);
            son[p].push_back(i);
        }
        printf("%d\n", dp(0));
    }
    return 0;
}
