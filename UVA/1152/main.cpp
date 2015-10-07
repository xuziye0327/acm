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
const int maxn = 4000 + 7;
const int mod = 100003;
const double eps = 1E-6;

int n;
int A[maxn], B[maxn], C[maxn], D[maxn];
int num[4000 * 4000 + 7];

void init() {
    CLR(num, 0);
}

int main() {
    int T;
    bool BLANK = false;
    scanf("%d", &T);
    while (T--) {
        if (BLANK) printf("\n");
        BLANK = true;
        init();
        int cnt(0);
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
            scanf("%d%d%d%d", &A[i], &B[i], &C[i], &D[i]);
        int res(0);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int t = A[i] + B[j];
                t *= -1;
                num[cnt++] = t;
            }
        }
        sort(num, num + cnt);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int t = C[i] + D[j];

                int pos1(-1), pos2(-1);
                int l = 0, r = cnt;
                while (l < r)  {
                    int mid = (r - l) / 2 + l;
                    if (num[mid] <= t) {
                        l = mid + 1;
                    } else {
                        r = mid;
                    }
                }

                pos1 = l;

                l = 0, r = cnt;
                while (l < r) {
                    int mid = (r - l) / 2 + l;
                    if (num[mid] < t) {
                        l = mid + 1;
                    } else {
                        r = mid;
                    }
                }

                pos2 = l;

                res += pos1 - pos2;
            }
        }
        printf("%d\n", res);
    }
    return 0;
}
