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
const int maxn = 1E5 + 7;
const double eps = 1E-6;

int a[maxn];

void init() {
}

int main() {
	bool blank = false;
	int n, m, T;
	scanf("%d", &T);
	while (T--) {
		if (blank) printf("\n");
		blank = true;
		int cnt(0);
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
		sort(a, a + n);
		for (int i = 0, j = n - 1; j >= i; --j) {
			++cnt;
			if (i == j) break;
			else if (a[i] + a[j] <= m) ++i;
		}
		printf("%d\n", cnt);
	}
    return 0;
}
