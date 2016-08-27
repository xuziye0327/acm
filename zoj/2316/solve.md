### 题目链接
<a href="http://acm.zju.edu.cn/onlinejudge/showProblem.do?problemCode=2316">HERE</a>

### 题目描述
给出N个顶点M条边，求给出的无向图邻接矩阵的倒置和邻接矩阵的乘后的每个元素之和。

### 解题思路
无向图的矩阵倒置和不倒置是一样的。
如果直接用邻接矩阵解的话会MLE，而且会超时。
写出矩阵相乘的步骤的话会发现最终的答案是每个顶点的度数乘积之和。

``` cpp
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
```