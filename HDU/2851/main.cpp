#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int  inf = 0xfffffff;
const int maxn = 2000 + 7;

struct line {
    int s, e, w;
};

bool arrive(const line &l1, const line &l2) {
    return (l1.e <= l2.e && l1.e >= l2.s);
}

int n, m;
int dp[maxn];
line ma[maxn];

void init() {
    fill(dp, dp + maxn, inf);
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        init();
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; ++i) {
                scanf("%d%d%d", &ma[i].s, &ma[i].e, &ma[i].w);
        }
        dp[1] = ma[1].w;
        for(int i = 2; i <= n; ++i) {
            for(int j = 1; j < i; ++j) {
                if(arrive(ma[j], ma[i])) {
                    dp[i] = min(dp[i], dp[j] + ma[i].w);
                }
            }
        }
        for(int i = 0; i < m; ++i) {
            int che;
            scanf("%d", &che);
            printf("%d\n", dp[che] < inf ? dp[che] : -1);
        }
    }
    return 0;
}