#include <cstdio>
#include <string>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

const int maxn = 200 + 7;

int d[maxn][2];
bool f[maxn][2];
vector<int> G[maxn];
map<string, int> ma;

void init () {
    ma.clear();
    for (int i = 0; i < maxn; ++i) {
        G[i].clear();
        for (int j = 0; j < 2; ++j) {
            d[i][j] = -1;
            f[i][j] = true;
        }
    }
}

void dfs(int u) {
    d[u][1] = 1;
    d[u][0] = 0;

    for (int i = 0; i < G[u].size(); ++i) {
        int v = G[u][i];
        if (d[v][0] < 0) dfs(v);
        if (!f[v][0]) f[u][1] = false;
        if (d[v][0] == d[v][1]) f[u][0] = false;
        if (d[v][0] > d[v][1] && !f[v][0]) f[u][0] = false;
        if (d[v][0] < d[v][1] && !f[v][1]) f[u][0] = false;
        d[u][1] += d[v][0];
        d[u][0] += max(d[v][0], d[v][1]);
    }
}

int main () {
    int n;
    while (scanf("%d", &n) && n) {
        init();
        string str1, str2;
        cin >> str1;
        ma[str1] = ma.size() - 1;
        for (int i = 0; i < n - 1; ++i) {
            cin >> str1 >> str2;
            if (!ma.count(str1)) ma[str1] = ma.size() - 1;
            if (!ma.count(str2)) ma[str2] = ma.size() - 1;
            G[ma[str2]].push_back(ma[str1]);
        }
        dfs(0);
        printf("%d ", max(d[0][0], d[0][1]));
        if (d[0][0] == d[0][1]) printf("No\n");
        else if (d[0][0] > d[0][1] && !f[0][0]) printf("No\n");
        else if (d[0][1] > d[0][0] && !f[0][1]) printf("No\n");
        else printf("Yes\n");
    }
    return 0;
}
