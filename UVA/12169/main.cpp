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

/*
const int inf = 1 << 27;
const ull INF = 1ULL << 57ULL;
const int maxn = 200 + 7;
const int mod = 10001;
const double eps = 1E-6;

int x[maxn];

int main() {
    int n;
    while (~scanf("%d", &n)) {
        for (int i = 1; i <= 2 * n; i += 2) {
            scanf("%d", &x[i]);
        }
        int a, b;
        for (a = 0; a < mod; ++a) {
            bool flag(true);
            for (b = 0; b < mod; ++b) {
                flag = true;
                for (int i = 2; i <= 2 * n; ++i) {
                    if (i & 1){
                        if (x[i] != (a * x[i - 1] + b) % mod) {
                            flag = false;
                            break;
                        }
                    } else {
                        x[i] = (a * x[i - 1] + b) % mod;
                    }

                }
                if (flag) break;
            }
            if (flag) break;
        }
        for (int i = 2; i <= 2 * n; i += 2) printf("%d\n", x[i]);
    }
    return 0;
}
*/

const int inf = 1 << 27;
const ull INF = 1ULL << 57ULL;
const int maxn = 200 + 7;
const ull mod = 10001;
const double eps = 1E-6;

ull x[maxn];

void gcd(ull a, ull b, ull &d, ull &x, ull &y) {
    if (!b) { d = a; x = 1ull; y = 0ull; }
    else { gcd(b, a % b, d, y, x); y -= x * (a / b); }
}

int main() {
    int n;
    while (~scanf("%d", &n)) {
        for (int i = 1; i <= 2 * n; i += 2) {
            scanf("%llu", &x[i]);
        }
        for (ull a = 0; a < mod; ++a) {
            bool flag = true;
            ull k, g, b, c = x[3] - a * a * x[1];
            gcd(mod, a + 1, g, k, b);
            if (c % g) continue;
            b = b * c / g;
            b %= mod;
            for (int i = 2; i <= 2 * n; ++i) {
                if (i & 1) {
                    if (x[i] != (a * x[i - 1] + b) % mod) {
                        flag = false;
                        break;
                    }
                } else {
                    x[i] = (a * x[i - 1] + b) % mod;
                }
            }
            if (flag) break;
        }
        for (int i = 2; i <= 2 * n; i += 2) printf("%d\n", x[i]);
    }
    return 0;
}