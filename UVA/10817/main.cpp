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
const int maxn = 200 + 7;
const int maxs = (1 << 8) + 7;
const double eps = 1E-6;

int s, m, n;
int d[maxn][maxs][maxs];
int c[maxn], st[maxn];
char str[maxn];

void init() {
	CLR(c, 0);
	CLR(d, -1);
	CLR(st, 0);
}

int dp(int pos, int s0, int s1, int s2) {
	if (pos == m + n) return (s2 == (1 << s) - 1) ? 0 : inf;
	
	int &res = d[pos][s1][s2];
	if (res >= 0) return res;
	res = inf;

	if (pos >= m) res = dp(pos + 1, s0, s1, s2);

	int m0 = st[pos] & s0, m1 = st[pos] & s1;
	s0 ^= m0; s1 |= m0; s1 ^= m1; s2 |= m1;
	res = min(res, dp(pos + 1, s0, s1, s2) + c[pos]);

	return res;
}

int main() {
	while (~scanf("%d%d%d", &s, &m, &n) && s) {
		init();
		for (int i = 0; i < n + m; ++i) {
			scanf("%d", &c[i]);
			gets(str);
			int len = strlen(str);
			for (int j = 0; j < len; ++j) {
				if (isdigit(str[j])) {
					st[i] ^= (1 << ((str[j] - '0') - 1));
				}
			}
		}
		printf("%d\n", dp(0, (1 << s) - 1, 0, 0));
	}
    return 0;
}
