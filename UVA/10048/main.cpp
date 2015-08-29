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

const int inf = 1 << 25;
const int maxn = 100 + 7;

int C, S, Q;
int d[maxn][maxn];

void init() {
    for (int i = 0; i < maxn; ++i) {
        for (int j = 0; j < maxn; ++j) {
            d[i][j] = i == j ? 0 : inf;
        }
    }
}

void floyd() {
    for (int k = 1; k <= C; ++k) {
        for (int i = 1; i <= C; ++i) {
            for (int j = 1; j <= C; ++j) {
                d[i][j] = min(d[i][j], max(d[i][k], d[k][j]));
            }
        }
    }
}

int main() {
    int Kase(0);
    while (scanf("%d%d%d", &C, &S, &Q) && C) {
        if(Kase) printf("\n");
        printf("Case #%d\n", ++Kase);
        init();
        for (int i = 0; i < S; ++i) {
            int u, v, c;
            scanf("%d%d%d", &u, &v, &c);
            d[u][v] = d[v][u] = min(c, d[u][v]);
        }
        floyd();
        while (Q--) {
            int u, v;
            scanf("%d%d", &u, &v);
            if(d[u][v] < inf) printf("%d\n", d[u][v]);
            else printf("no path\n");
        }
    }
    return 0;
}
