#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxn = 10000 + 7;

struct moues {
    int id, W, S;
    bool operator < (const moues &k) const {
        return W != k.W ? W < k.W : S > k.S;
    }
}m[maxn];

int dp[maxn];

int main() {
    int cnt(0), res(0);
    for( ; ~scanf("%d%d", &m[cnt].W, &m[cnt].S); ++cnt) m[cnt].id = cnt;
    sort(m, m + cnt);
    for(int i = 0; i < cnt; ++i) dp[i] = 1;
    for(int i = cnt - 1; i >= 0; --i) {
        for (int j = i + 1; j < cnt ; ++j) {
            if(m[i].W < m[j].W && m[i].S > m[j].S) dp[i] = max(dp[i], dp[j] + 1);
            res = max(res, dp[i]);
        }
    }
    printf("%d\n", res);
    for(int i = 0; i < cnt && res; i++) {
        if(dp[i] == res) { printf("%d\n", m[i].id + 1);  --res; }
    }
    return 0;
}