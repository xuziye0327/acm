#include <bits/stdc++.h>

using namespace std;

const int maxn = 107;
const int  inf = 0x3f3f3f;

int n, k;
int v[maxn];
int d[maxn];
int w[maxn][maxn];
bool vis[maxn];

void dij() {
    fill(d, d + maxn, inf);
    fill(vis, vis + maxn, false);
    d[0] = 0;
    while (true) {
        int v = -1;
        for (int i = 0; i < maxn; ++i) {
            if (!vis[i] && (v == -1 || d[i] < d[v])) v = i;
        }
//        cout << v << " ";
//        cout << d[v] << endl;
        if (v == -1) return ;
        vis[v] = true;
        for (int i = 0; i < maxn; ++i) {
            if (d[v] + w[v][i] + 60 < d[i]) {
                d[i] = d[v] + w[v][i] + 60;
            }
        }
    }
}

int main() {
    while (~scanf("%d%d", &n, &k)) {
        for (int i = 0; i < maxn; ++i) fill(w[i], w[i] + maxn, inf);
        for (int i = 0; i < n; ++i) scanf("%d", &v[i]);
        getchar();
        for (int i = 0; i < n; ++i) {
            int td = 0;
            char ch;
            vector<int> vec;
            while (true) {
                ch = getchar();
                if (ch == '\n') {
                    vec.push_back(td);
                    break;
                }
                if (ch == ' ') {
                    vec.push_back(td);
                    td = 0;
                } else {
                    td = 10 * td + ch - '0';
                }
            }
            sort(vec.begin(), vec.end());
            for (int j = 0; j < vec.size(); ++j) {
                for (int jj = j + 1; jj < vec.size(); ++jj) {
                    w[vec[j]][vec[jj]] = w[vec[jj]][vec[j]] = min(w[vec[j]][vec[jj]], (vec[jj] - vec[j]) * v[i]);
                }
            }
        }
//        cout << w[20][99] << endl;
        if (k == 0) {
            printf("0\n");
            continue;
        }
        dij();
//        cout << d[k] << endl;
        if (d[k] == inf) printf("IMPOSSIBLE\n");
        else printf("%d\n", d[k] - 60);
    }
    return 0;
}
