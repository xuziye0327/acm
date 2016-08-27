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

const int inf = 1 << 20;
const int maxn = 40 + 7;
const double eps = 1E-6;

int n, m;
int k[maxn];
ull dp[2][inf + 7];

int main() {
    int T, Kase(0);
    scanf("%d", &T);
    while(T--){
        CLR(dp, 0);
        ull ans(0);
        bool flag = true;
        scanf("%d%d", &n, &m);
        for(int i = 0; i < n; ++i) scanf("%d", &k[i]);
        dp[!flag][0] = 1;
        for(int i = 0; i < n; ++i) {
            memcpy(dp[flag], dp[!flag], sizeof(dp[0]));
            for (int j = 0; j < inf; ++j) {
                dp[flag][k[i] ^ j] += dp[!flag][j];
            }
            flag = !flag;
        }
        for (int l = m; l < inf; ++l) {
            ans += dp[!flag][l];
        }
        printf("Case #%d: %I64u\n",++Kase,ans);
    }
    return 0;
}