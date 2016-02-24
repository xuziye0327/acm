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
