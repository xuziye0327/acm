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
const int maxn = 1000 + 7;
const double eps = 1E-6;

int dp[maxn];
char str[maxn];
bool S[maxn][maxn];

void init() {
    CLR(S, false);
    for (int i = 0; i < maxn; ++i)
        dp[i] = inf;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        init();
        scanf("%s", str + 1);
        int len = strlen(str + 1);
        for (int i = 1; i <= len; ++i) {
            for (int j = 0; (i - j) >= 1 && (i + j) <= len; ++j) {
                if (str[i - j] != str[i + j]) break;
                S[i - j][i + j] = true;
            }
            for (int j = 0; (i - j) >= 1 && (i + j + 1) <= len; ++j) {
                if (str[i - j] != str[i + j + 1]) break;
                S[i - j][i + j + 1] = true;
            }
        }
        dp[0] = 0;
        for (int i = 1; i <= len; ++i) {
            for (int j = 0; j + 1 <= i; ++j) {
                if (S[j + 1][i]) dp[i] = min(dp[i], dp[j] + 1);
            }
        }
        printf("%d\n", dp[len]);
    }
    return 0;
}
