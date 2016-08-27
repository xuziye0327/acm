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
const int maxn = 400 + 7;
const double eps = 1E-6;

void init() {
}

int main() {
    int Kase(0);
    ull N;
    while (scanf("%llu", &N) && N) {
        init();
        int cnt(0);
        ull ans(0ull);
        if (N == 1) ans = 2;
        for (ull i = 2; i * i <= N; ++i) {
            ull t(0ull);
            while (N % i == 0ull) {
                if (!t) t = 1;
                N /= i;
                t *= i;
            }
            if (t) ++cnt;
            ans += t;
        }
        if (N != 1ull) { ans += N; ++cnt; }
        if (cnt == 1) ++ans;
        printf("Case %d: %llu\n", ++Kase, ans);
    }
    return 0;
}
