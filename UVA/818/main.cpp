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
const int maxn = 15 + 7;

int N, ans;
bool used[maxn];
bool G[maxn][maxn];

void init() {
    ans = inf;
    CLR(G, false);
    CLR(used, false);
}

bool connect(int s) {
    for (int i = 1; i <= N; ++i) {
        if (s & (1 << (i - 1))) continue;
        int cnt(0);
        for(int j = 1; j <= N; ++j) {
            if(i == j) continue;
            if (s & (1 << (j - 1))) continue;
            if(G[i][j]) ++cnt;
        }
        if (cnt > 2) return true;
    }
    return false;
}

bool dfs(int s, int now, int from) {
    used[now] = true;
    for(int i = 1; i <= N; ++i) {
        if(i == from) continue;
        if(s & (1 << (i - 1))) continue;
        if(G[now][i]) {
            if(used[i]) return true;
            return dfs(s, i, now);
        }
    }
    return false;
}

bool circle(int s) {
    for(int i = 1; i <= N; ++i) {
        if(s & (1 << (i - 1))) continue;
        CLR(used, false);
        if(dfs(s, i, i)) return true;
    }
    return false;
}

void dfs2(int u, int s) {
    used[u] = true;
    for (int i = 1; i <= N; ++i) {
        if (s & (1 << (i - 1))) continue;
        if(used[i]) continue;
        if(G[u][i]) dfs2(i, s);
    }
}

int count(int s) {
    return s == 0 ? s : count(s >> 1) + (s & 1);
}

int main() {
    int Kase(0);
    while(~scanf("%d", &N) && N) {
        init();
        int u, v;
        while(scanf("%d%d", &u, &v) && u != -1) {
            G[u][v] = G[v][u] = true;
        }
        for(int i = 0; i < (1 << N); ++i) {
            if (connect(i) || circle(i)) continue;
            int open = count(i), cn(0);
            CLR(used, false);
            for(int j = 1; j <= N; ++j) {
                if (i & (1 << (j - 1))) continue;
                if(used[j]) continue;
                dfs2(j, i);
                ++cn;
            }
            if(open + 1 >= cn)
                ans = min(ans, count(i));
        }
        printf("Set %d: Minimum links to open is %d\n", ++Kase, ans);
    }
    return 0;
}