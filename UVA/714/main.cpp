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
const int maxn = 500 + 7;
const double eps = 1E-6;

int k, m;
ull a[maxn];
bool used[maxn];

void init() {
    for (int i = 0; i < maxn; ++i) used[i] = true;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        init();
        ull l(0), r(0), mid;
        scanf("%d%d", &k, &m);
        for (int i = 1; i <= k; ++i) {
            scanf("%llu", &a[i]);
            r += a[i];
        }
        while (l < r) {
            mid = (r + l) / 2ull;
            int s(1);
            ull t(0);
            for (int i = 1; i <= k; ++i) {
                if (t + a[i] <= mid) {
                    t += a[i];
                } else {
                    t = a[i];
                    if (t > mid) s = m;
                    ++s;
                }
            }
            if (s > m) {
                l = mid + 1ull;
            } else {
                r = mid;
            }
        }
        int cnt = m;
        ull t = (0);
        for (int i = k; i > 0; --i) {
            if (i + 1 == cnt) break;
            if (t + a[i] <= l) {
                used[i] = false;
                t += a[i];
            } else {
                t = a[i];
                cnt--;
            }
        }
        for (int i = 1; i <= k; ++i) {
            if (i != 1) printf(" ");
            printf("%llu", a[i]);
            if (used[i]) printf(" /");
        }
        printf("\n");
    }
    return 0;
}