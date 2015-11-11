### 题目链接
<a href="http://acm.zju.edu.cn/onlinejudge/showProblem.do?problemCode=2315">HERE</a>

### 题目描述
微软有N个员工，每个员工能从他的上司得到1000美元，或者给他下属1000美元，再或者不得到也不往下给。
如果员工从他的上司那里拿到了1000美元，那么他就不能给他下属钱。同样如果给了下属钱，那么他就不能从上司那里得到钱。
员工不能从多个上司得到钱。
问全体员工最多能得到的钱。

### 解题思路
很典型的树形dp。
设d[i][j]，i为员工的标号。
如果j为0，表示这个员工什么也不做得到的钱。
如果j为1，表示从上司拿到钱。
如果j为2，表示这个员工给下属钱。
那么 
[latex]d[i][0]=\sum{\max{(d[j][0],d[j][2])}}[/latex] （j表示这个员工的下属）
[latex]d[i][1]=\sum{\max{(d[j][0],d[j][2])}}[/latex]
[latex]d[i][2]=d[k][1]+\sum_{j!=k}{\max{(d[j][0],d[j][2])}}[/latex]
d[i][2]可以通过 [latex]d[i][2]=\sum{\max{(d[j][0],d[j][2])}}-\max{(d[k][0],d[k][2])}+d[k][1][/latex] 计算，降低复杂度。

``` cpp
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

const int maxn = 500007;

int n;
int d[maxn][3];
bool flag;
vector<int> res;
vector<int> son[maxn];

void init() {
    res.clear();
    memset(d, 0, sizeof(d));
    for (int i = 0; i < maxn; ++i) son[i].clear();
}

void dfs(int k) {
    d[k][0] = d[k][2] = 0;
    if (k != 1)
        d[k][1] = 1;

    int t = 0;
    for (size_t i = 0; i < son[k].size(); ++i) {
        int v = son[k][i];
        dfs(v);
        d[k][0] += max(d[v][0], d[v][2]);
        if (k != 1)
            d[k][1] += max(d[v][0], d[v][2]);
        t += max(d[v][0], d[v][2]);
    }
    for (size_t i = 0; i < son[k].size(); ++i) {
        int v = son[k][i];
        d[k][2] = max(d[k][2], t - max(d[v][0], d[v][2]) + d[v][1]);
    }

}

void dfs2(int k, int cmd) {
    if (cmd == 1) res.push_back(k);

    if (cmd == 2) {
        int t = 0;
        for (size_t i = 0; i < son[k].size(); ++i) {
            int v = son[k][i];
            t += max(d[v][0], d[v][2]);
        }
        bool ok = true;
        for (size_t i = 0; i < son[k].size(); ++i) {
            int v = son[k][i];
            if (t - max(d[v][0], d[v][2]) + d[v][1] == d[k][2] && ok) {
                ok = false;
                dfs2(v, 1);
            } else {
                if (d[v][0] > d[v][2]) dfs2(v, 0);
                else if (d[v][2] != 0) dfs2(v, 2);
            }
        }
    } else {
        for (size_t i = 0; i < son[k].size(); ++i) {
            int v = son[k][i];
            if (d[v][0] > d[v][2]) dfs2(v, 0);
            else if (d[v][2] != 0) dfs2(v, 2);
        }
    }
}

int main() {
    int T;
    bool blank = false;
    scanf("%d", &T);
    while (T--) {
        init();
        if (blank) puts("");
        blank = true;
        scanf("%d", &n);
        for (int i = 2; i <= n; ++i) {
            int p;
            scanf("%d", &p);
            son[p].push_back(i);
        }
        dfs(1);
        int ans = max(d[1][0], d[1][2]);
        printf("%d\n", ans * 1000);
        if (d[1][2] > d[1][0]) {
            dfs2(1, 2);
        } else {
            dfs2(1, 0);
        }
        flag = false;
        sort(res.begin(), res.end());
        for (int i = 0; i < res.size(); ++i) {
            if (flag) printf(" ");
            flag = true;
            printf("%d", res[i]);
        }
        puts("");
    }
    return 0;
}
```