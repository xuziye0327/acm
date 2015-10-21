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
const int maxn = 200000 + 7;
const double eps = 1E-6;

int ma[maxn], times[maxn];
bool flag[maxn];

void init() {
	CLR(times, 0);
	CLR(flag, false);
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		init();
		int s, n, ans(0), cnt(0);
		scanf("%d%d", &s, &n);
		for (int i = 0; i < n; ++i) {
			scanf("%d", &ma[i]);
			if (i < s) {
				++times[ma[i]];
				if (times[ma[i]] == 1) {
					++cnt;
				} else if (times[ma[i]] == 2) {
					--cnt;
				}
				if (cnt == i + 1) flag[i] = true;
			}
		}
		for (int i = s; i < n; ++i) {
			--times[ma[i - s]];
			if (times[ma[i - s]] == 0) --cnt;
			else if (times[ma[i - s]] == 1) ++cnt;
			++times[ma[i]];
			if (times[ma[i]] == 1) ++cnt;
			else if (times[ma[i]] == 2) --cnt;
			if (cnt == s) flag[i] = true;
		}
		for (int i = n; i < n + s; ++i) {
			if (i - s >= 0) {
				--times[ma[i - s]];
				if (times[ma[i - s]] == 0) --cnt;
				else if (times[ma[i - s]] == 1) ++cnt;
				if (s - (i - n + 1) == cnt) flag[i] = true;
			} else {
				flag[i] = flag[i - 1];
			}
		}
		for (int i = 0; i < s; ++i) {
			bool judge(true);
			for (int j = i; ; j += s) {
				if (!flag[j]) { judge = false; break; }
				if (j >= n) break;
			}
			if (judge) ++ans;
		}
		printf("%d\n", ans);
	}
    return 0;
}
