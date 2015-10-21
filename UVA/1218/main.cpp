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

const int inf = 1 << 15;
const ull INF = 1ULL << 57ULL;
const int maxn = 10000 + 7;
const double eps = 1E-6;

int dp[maxn][3];
bool used[maxn];
vector<int> G[maxn];

void init() {
	CLR(dp, 0);
	CLR(used, false);
	for (int i = 0; i < maxn; ++i) G[i].clear();
}

void d(int pos) {
	used[pos] = true;
	dp[pos][0] = 1;
	dp[pos][1] = 0;
	dp[pos][2] = inf;

	queue<int> que;
	for (int i = 0; i < (int) G[pos].size(); ++i) {
		int v = G[pos][i];
		if (!used[v]) {
			d(v);
			que.push(v);
			dp[pos][0] += min(dp[v][0], dp[v][1]);
			dp[pos][1] += dp[v][2];
		}
	}
	while (!que.empty()) {
		int v = que.front(); que.pop();
		dp[pos][2] = min(dp[pos][2], dp[pos][1] - dp[v][2] + dp[v][0]);
	}
	return ;
}

int main() {
	int x, y, n;
	while (scanf("%d", &n)) {
		init();
		for (int i = 1; i < n; ++i) {
			scanf("%d%d", &x, &y);
			G[x].push_back(y);
			G[y].push_back(x);
		}

		int res;
		for (int i = 1; i <= n; ++i) {
			if (!G[i].empty()) {
				d(i);
				res = min(dp[i][0], dp[i][2]);
				break;
			}
		}
		printf("%d\n", res);
		scanf("%d", &n);
		if (n == -1) break;
	}
    return 0;
}
