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
const int maxn = 100000 + 7;
const double eps = 1E-6;

double ans[maxn];

void init() {
    CLR(ans, 0);
    ans[1] = 1.0;
    for (int i = 2; i < maxn; ++i) {
        ans[i] = (2.0 * i - 3.0) * ans[i - 1] / (2.0 * i - 2.0);
    }
}

int main() {
    init();
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        printf("%.4f\n", 1.0 - ans[n / 2]);
    }
    return 0;
}
