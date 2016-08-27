#include <cstdio>
#include <cstring>
#include <map>
#include <set>

using namespace std;

typedef unsigned long long ull;
typedef pair<int, int > P;

const int maxn = 10007;

int to[maxn];
set<P> s;

int main() {
    int T;
    bool flag = false;
    scanf("%d", &T);
    while (T--) {
        s.clear();
        memset(to, 0, sizeof(to));
        if (flag) puts("");
        flag = true;
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 0; i < m; ++i) {
            int u, v;
            scanf("%d%d", &u, &v);
            if (!s.count(P(u, v))) {
                s.insert(P(u, v));
                s.insert(P(v, u));
                ++to[v];
                ++to[u];
            }
        }
        ull ans = 0;

        for (int i = 1; i <= n; ++i) {
            ans += (ull)to[i] * (ull)to[i];
        }

        printf("%llu\n", ans);
    }
    return 0;
}
