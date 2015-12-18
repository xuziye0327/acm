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
const int maxn = (1 << 20) + 7;
const double eps = 1E-6;

struct Edge {
    int to, cost;
};

int n, m, maxx;
int d[maxn];
char s[20 + 7], e[20 + 7];
vector<Edge> G[maxn];

void init() {
    maxx = 1 << n;
    CLR(d, 0);
    for (int i = 0; i < maxn; ++i) G[i].clear();
    for (int i = 0; i < maxn; ++i) d[i] = inf;
}

void dij() {
    d[maxx - 1] = 0;
    priority_queue<P, vector<P>, greater<P> > que;
    que.push(P(0, maxx - 1));

    while (!que.empty()) {
        P p = que.top(); que.pop();
        int v = p.second;
        if (d[v] < p.first) continue;
        for (int i = 0; i < G[v].size(); ++i) {
            Edge edge = G[v][i];
            if (d[edge.to] > d[v] + edge.cost) {
                d[edge.to] = d[v] + edge.cost;
                que.push(P(d[edge.to], edge.to));
            }
        }
    }
}

int main() {
    int Kase(0);
    while (scanf("%d%d", &n, &m) && n) {
        init();
        for (int i = 0; i < m; ++i) {
            int c;
            scanf("%d%s%s", &c, s, e);
            for (int j = 0; j < maxx; ++j) {
                int t = j;
                bool flag = true;
                for (int k = 0; k < n; ++k) {
                    if (s[n - k - 1] == '0') continue;
                    if (s[n - k - 1] == '+' && ((t >> k) & 1)) continue;
                    if (s[n - k - 1] == '-' && ((t >> k) & 1) == 0) continue;
                    flag = false;
                    break;
                }
                if (flag) {
                    for (int k = 0; k < n; ++k) {
                        if (e[n - k - 1] == '-') t &= ~(1 << k);
                        if (e[n - k - 1] == '+') t |= (1 << k);
                    }
                    Edge edge;
                    edge.to = t; edge.cost = c;
                    G[j].push_back(edge);
                }
            }
        }

        dij();

        printf("Product %d\n", ++Kase);
        if (d[0] >= inf) printf("Bugs cannot be fixed.\n\n");
        else printf("Fastest sequence takes %d seconds.\n\n", d[0]);
    }
    return 0;
}