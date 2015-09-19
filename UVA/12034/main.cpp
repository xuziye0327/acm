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
const int mod = 10056;
const double eps = 1E-6;

int n, f[maxn];
int C[maxn][maxn];

void init() {
    f[0] = f[1] = 1;
    for (int i = 0; i < maxn; ++i) {
        C[i][0] = 1;
        for (int j = 1; j <= i; ++j) C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
    }
    for (int i = 2; i < maxn; ++i) {
        for (int j = 1; j <= i; ++j) {
            f[i] += C[i][j] * f[i - j] % mod;
        }
        f[i] %= mod;
    }
}

int main() {
    init();
    int T, Kase(0);
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        printf("Case %d: %d\n", ++Kase, f[n]);
    }
    return 0;
}
