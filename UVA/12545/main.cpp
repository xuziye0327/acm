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

char str1[maxn], str2[maxn];

void init() {
}

int main() {
//    freopen("testin", "r", stdin);
//    freopen("testout", "w", stdout);
    int T, Kase(0);
    scanf("%d", &T);
    while (T--) {
        scanf("%s%s", str2, str1);
        int res(0);
        int len = strlen(str1);
        for (int i = 0; i < len; ++i) {
            if (str1[i] == str2[i]) continue;
            for (int j = i + 1; j < len; ++j) {
                if (str1[i] == str2[j] && str1[j] == str2[i]) {
                    swap(str2[i], str2[j]);
                    ++res;
                    break;
                }
            }
        }
        for (int i = 0; i < len; ++i) {
            bool flag = false;
            if (str1[i] == str2[i]) continue;
            if (str2[i] == '?') {
                for (int j = i + 1; j < len; ++j) {
                    if (str1[i] == str2[j] && str1[j] != str2[j]) {
                        swap(str2[i], str2[j]);
                        str2[j] = str1[j];
                        res += 2;
                        flag = true;
                        break;
                    }
                }
                if (flag) continue;
                ++res;
                str2[i] = str1[i];
            } else {
                for (int j = i + 1; j < len; ++j) {
                    if (str2[i] == str1[j] && str1[j] != str2[j]) {
                        swap(str2[i], str2[j]);
                        str2[i] = str1[i];
                        res += 2;
                        break;
                    }
                }
            }
        }
        for (int i = 0; i < len; ++i) {
            if (str1[i] != str2[i]) {
                if (str1[i] == '1' && str2[i] == '0') {
                    ++res;
                } else {
                    res = -1;
                    break;
                }
            }
        }
        printf("Case %d: %d\n", ++Kase, res);
    }
    return 0;
}
