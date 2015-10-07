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
const int maxn = 50 + 7;
const double eps = 1E-6;

char letter[maxn];

void init() {
    for (int i = 0; i < 26; ++i) letter[i] = (char)('a' + i);
    for (int i = 26; i < 52; ++i) letter[i] = (char)('A' + i - 26);
}

int main() {
    init();
    bool BLANK = false;
    int n;
    while (~scanf("%d", &n)) {
        if (BLANK) printf("\n");
        BLANK = true;
        printf("2 %d %d\n", n, n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                printf("%c", letter[i]);
            }
            printf("\n");
        }

        printf("\n");

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                printf("%c", letter[j]);
            }
            printf("\n");
        }
    }
    return 0;
}
