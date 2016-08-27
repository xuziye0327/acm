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
const int maxn = 2000 + 7;
const double eps = 1E-6;

int phi[maxn];

void init() {
}

void phi_table() {
    for (int i = 2; i <= maxn; ++i) phi[i] = 0;
    phi[1] = 1;
    for (int i = 2; i <= maxn; ++i) if (!phi[i]) {
        for (int j = i; j <= maxn; j += i) {
            if (!phi[j]) phi[j] = j;
            phi[j] = phi[j] / i * (i - 1);
        }
    }
}

int gcd(int a, int b) {
    if (a < b) swap(a, b);
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    phi_table();
    int a, b;
    while (scanf("%d%d", &a, &b) && a) {
        double aa = (double) a, bb = (double) b;
        double K(1.0), N(aa * bb * 4.0 + (aa + bb) * 2.0);
        for (int i = 1; i <= a; ++i) {
            int k = b / i;
            K += k * phi[i] * 1.0;
            for (int j = k * i + 1; j <= b; ++j) {
                if (gcd(j, i) == 1) ++K;
            }
        }
        K *= 4.0;
        printf("%.7f\n", K / N);
    }
    return 0;
}
