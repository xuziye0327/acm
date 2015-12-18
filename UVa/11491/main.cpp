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
const int maxn = (int)(1e5) + 7;
const double eps = 1E-6;

int n, d;
char str[maxn];
bool del[maxn];

void init() {
    CLR(del, false);
}

int main() {
    freopen("testin", "r", stdin);
    freopen("testout", "w", stdout);
    while (scanf("%d%d", &n, &d) && n) {
        init();
        int last = n - d;
        scanf("%s", str);
        for (int i = 1; i < n; ++i) {
            if (str[i - 1] < str[i]) {
                del[i - 1] = true;
                --d;
                if (!d) break;
                for (int j = i - 2; j >= 0; --j) {
                    if (!del[j] && str[j] < str[i]) {
                        del[j] = true;
                        --d;
                        if (!d) break;
                    } else if (!del[i] && str[j] >= str[i]) break;
                }
                if (!d) break;
            }
        }
        for (int i = 0, cnt = 0; i < n && cnt < last; ++i) {
            if (!del[i]) { ++cnt; printf("%c", str[i]); }
        }
        printf("\n");
    }
    return 0;
}
