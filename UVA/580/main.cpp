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
#define BLANK bool blank = false
#define RANDOM srand((unsigned)time(NULL))

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;

const int inf = 1 << 27;
const ull INF = 1ULL << 57ULL;
const int maxn = 30 + 7;
const double eps = 1E-6;

int n;
int f[maxn];

int fast_power(int x, int k) {
    int a = 1;
    while (k) {
        if (k & 1) a *= x;
        x *= x;
        k >>= 1;
    }
    return a;
}

int main() {
    f[0] = f[1] = f[2] = 0;
    for (int p = 3; p <= 30; ++p) {
        f[p] = fast_power(2, p - 3);
        for (int i = 2; i <= p - 2; ++i) {
            f[p] += (fast_power(2, i - 2) - f[i - 2]) * fast_power(2, p - i - 2);
        }
    }
    while (scanf("%d", &n) && n) {
        printf("%d\n", f[n]);
    }
    return 0;
}
