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

int a[maxn], Last[maxn], Next[maxn];
map<int, int> ma;

void init() {
	ma.clear();
}

bool nonboring (int l, int r) {
	if (l >= r) return true;
	for (int i = l, j = r; i <= j; ++i, --j) {
		if (Last[i] < l && Next[i] > r) return nonboring(l, i - 1) && nonboring(i + 1, r);
		if (Last[j] < l && Next[j] > r) return nonboring(l, j - 1) && nonboring(j + 1, r);
	}
	return false;
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		init();
		int n, t;
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &t);
			if (ma.count(t)) {
				Last[i] = ma[t];
				Next[Last[i]] = i;
			}
			else {
				Last[i] = 0;
			}
			ma[t] = i;
			Next[i] = n + 1;
		}
		printf("%s\n", nonboring(1, n) ? "non-boring" : "boring");  
	}
    return 0;
}
