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
#include <algorithm>
#include <vector>
#include <set>
#include <map>

#define MP(x,y) make_pair(x,y)
#define CLR(a, b) memset(a, b, sizeof(a))

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;

const int maxn = 15;
const ull base = 23333333333333;

int N;
int l[maxn];
set<ull> s;

void dfs(int l1, int l2, int l3, int n) {
    if (n == N) {
        if(l1 > l2 || l1 > l3 || l2 > l3) return ;
        if (l1 < l2 + l3 && l2 < l1 + l3 && l3 < l1 + l2 && l1 && l2 && l3) {
            ull t = (((l1 * base) + l2) * base + l3) * base;
            s.insert(t);
        }
        return ;
    }
    dfs(l1 + l[n], l2, l3, n + 1);
    dfs(l1, l2 + l[n], l3, n + 1);
    dfs(l1, l2, l3 + l[n], n + 1);
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        s.clear();
        scanf("%d", &N);
        for(int i = 0; i < N; ++i) scanf("%d", &l[i]);
        dfs(0, 0, 0, 0);
        printf("%d\n", s.size());
    }
    return 0;
}
