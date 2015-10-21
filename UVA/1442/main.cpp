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
const int maxn = 1E6 + 7;
const double eps = 1E-6;

int s[maxn], p[maxn], l[maxn];

void init() {
	for (int i = 0; i < maxn; ++i) l[i] = inf;
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		init();
		int n, level, res(0);
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) scanf("%d", &p[i]);
		for (int i = 0; i < n; ++i) scanf("%d", &s[i]);
		level = inf;
		for (int i = 0; i < n; ++i) {
			if (level > s[i]) level = s[i];
			if (level < p[i]) level = p[i];
			if (level < l[i]) l[i] = level;
		}
		level = inf;
		for (int i = n - 1; i >= 0; --i) {
			if (level > s[i]) level = s[i];
			if (level < p[i]) level = p[i];
			if (level < l[i]) l[i] = level;
		}
		for (int i = 0; i < n; ++i) {
			res += l[i] - p[i];
		}
		printf("%d\n", res);
	}
    return 0;
}
