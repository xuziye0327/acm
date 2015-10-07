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
const int maxn = 100 + 7;
const double eps = 1E-6;

int dp[maxn][maxn];
char str[maxn];

void init() {
    for (int i = 0; i < maxn; ++i) {
        for (int j = 0; j < maxn; ++j) {
            dp[i][j] = inf;
        }
    }
    for (int i = 0; i < maxn; ++i) {
        dp[i][i] = 1;
        dp[i + 1][i] = 0;
    }
}

bool match(char ch1, char ch2) {
    return (ch1 == '(' && ch2 == ')') || (ch1 == '[' && ch2 == ']');
}

void print(int pos1, int pos2) {
    if (pos1 > pos2) return ;
    if (pos1 == pos2) {
        if (str[pos1] == '(' || str[pos1] == ')') printf("()");
        else printf("[]");
        return ;
    }

    int ans = dp[pos1][pos2];

    if (match(str[pos1], str[pos2]) && ans == dp[pos1 + 1][pos2 - 1]) {
        printf("%c", str[pos1]); print(pos1 + 1, pos2 - 1); printf("%c", str[pos2]);
        return ;
    }

    for (int k = pos1; k < pos2; ++k) {
        if (ans == dp[pos1][k] + dp[k + 1][pos2]) {
            print(pos1, k); print(k + 1, pos2);
            return ;
        }
    }
}

int main() {
//    freopen("input", "r", stdin);
//    freopen("output", "w", stdout);
    int T;
    bool Kase(false);
    scanf("%d", &T);
    getchar();
    while (T--) {
        if (Kase) printf("\n");
        Kase = true;
        init();
        gets(str);
        gets(str);
        int len = strlen(str);
        for (int i = len - 2; i >= 0; --i) {
            for (int j = i + 1; j < len; ++j) {
                dp[i][j] = len;
                if (match(str[i], str[j])) dp[i][j] = min(dp[i][j], dp[i + 1][j - 1]);
                for (int k = i; k < j; ++k) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
                }
            }
        }
        print(0, len - 1);
        printf("\n");
    }
    return 0;
}

