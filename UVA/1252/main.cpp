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
const int maxn = 128 + 7;
const int maxm = 12;
const double eps = 1E-6;

int m, n;
int fuc[maxn];
int d[1 << maxm][1 << maxm];

void init() {
	for (int i = 0; i < 1 << maxm; ++i) {
		for (int j = 0; j < 1 << maxm; ++j) {
			d[i][j] = inf;
		}
	}	
}

int tran() {
	char str[maxm];
	scanf("%s", str);
	int d(1), res(0);
	for (int i = 0; i < m; ++i) {
		res += d * (str[i] - '0');
		d *= 2;
	}
	return res;
}

int dp(int s, int a) {
	if (d[s][a] < inf) return d[s][a];
	int cnt(0);

	for (int i = 0; i < n; ++i) {
		if (((fuc[i] & a) == a) && ((fuc[i] & (a ^ s)) == 0)) ++cnt;
	}
	if (cnt <= 1) return d[s][a] = 0;

	for (int i = 0; i < m; ++i) {
		if ((s & (1 << i))) continue;
		d[s][a] = min(d[s][a], max(dp(s | (1 << i), a), dp(s | (1 << i), a | (1 << i))) + 1);
	}

	return d[s][a];
}

int main() {
	while (scanf("%d%d", &m, &n) && m) {
		init();
		for (int i = 0; i < n; ++i) {
			fuc[i] = tran();
		}
		printf("%d\n", dp(0, 0));
	}
    return 0;
}
