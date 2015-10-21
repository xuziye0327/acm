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

void init() {
}

ull gcd(ull a, ull b) {
    if (a < b) swap(a, b);
    return b == 0ULL ? a : gcd(b, a % b);
}

int getLen(ull x) {
    int len = 0;
    while (x) {
        ++len;
        x /= 10ULL;
    }
    return len;
}

int main() {
    ull n;
    while (~scanf("%llu", &n)) {
        ull g, a(0), b(1);
        for (ull i = 1; i <= n; ++i) {
            ull ta, tb;
            ta = a * i + 1 * b;
            tb = b * i;
            g = gcd(ta, tb);
            a = ta / g; b = tb / g;
        }
        a *= n;
        g = gcd(a, b);
        a /= g; b /= g;
        int lend = getLen(a / b);
        int lenb = getLen(b);
        if (a % b) {
            if (lend) for (int i = 0; i < lend + 1; ++i) printf(" ");
            printf("%llu\n", a % b);
            printf("%llu ",  a / b);
            for (int i = 0; i < lenb; ++i) printf("-");
            printf("\n");
            if (lend) for (int i = 0; i <= lend; ++i) printf(" ");
            printf("%llu\n", b);
        } else {
            printf("%llu\n", a / b);
        }
    }
    return 0;
}
