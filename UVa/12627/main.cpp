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
const int maxn = 400 + 7;
const double eps = 1E-6;

ull base[30 + 7];

void init() {
}

ull f(int k, int i) {
    if (i == 0) return 0ull;
    if (k == 0) return 1ull;
    if (i > (1 << (k - 1))) return f(k - 1, i - (1 << (k - 1))) + 2ull * base[k - 1];
    return 2ull * f(k - 1, i);
}

int main() {
    base[0] = 1ull;
    for (int i = 1; i <= 30; ++i) {
        base[i] = base[i - 1] * 3ull;
    }
    int T, Case(0);
    scanf("%d", &T);
    while (T--) {
        int k, a, b;
        scanf("%d%d%d", &k, &a, &b);
        printf("Case %d: %llu\n", ++Case, f(k, b) - f(k, a - 1));
    }
    return 0;
}
