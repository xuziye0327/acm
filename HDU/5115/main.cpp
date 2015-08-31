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
const int maxn = 200 + 7;
const double eps = 1E-6;

int n;
int a[maxn], b[maxn];
int dp[maxn][maxn];

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        for (int i = 0; i < maxn; ++i)
            for (int j = 0; j < maxn; ++j) dp[i][j] = inf;
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
        for (int i = 1; i <= n; ++i) scanf("%d", &b[i]);
        a[0] = a[n + 1] = 0;
        b[0] = b[n + 1] = 0;
        for (int i = 1; i <= n; ++i) dp[i][i] = a[i] + b[i - 1] + b[i + 1];
        for (int j = 1; j <= n; ++j) {
            for (int i = 1; i < j; ++i) {
                dp[i][j] = min(a[i] + b[i - 1] + b[j + 1] + dp[i + 1][j], a[j] + b[i - 1] + b[j + 1] + dp[i][j - 1]);
                for (int k = i + 1; k < j; ++k) {
                    dp[i][j] = min(dp[i][j], dp[i][k - 1] + dp[k + 1][j] + a[k] + b[i - 1] + b[j + 1]);
                }
            }
        }
        printf("%d\n", dp[1][n]);
    }
    return 0;
}
