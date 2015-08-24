#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 9 + 7;

int n, ans;
int a[maxn], b[maxn][maxn], c[maxn][maxn];
int temp[maxn][maxn];

bool dfs(int d, const int maxd) {
    int h(0);
    for(int i = 0; i < n - 1; ++i) if(a[i] != a[i + 1] - 1) ++h;
    if(!h) return true;
    if(d == maxd) return false;
    if(3 * d + h > 3 * maxd) return false;

    for(int beg = 0; beg < n; ++beg) {
        for(int len = 1; beg + len <= n; ++len) {
            memcpy(temp[d], a, sizeof(a));
            int posb(0), posc(0);
            for (int i = 0; i < beg; ++i) c[d][posc++] = a[i];
            for (int i = beg; i < beg + len; ++i) b[d][posb++] = a[i];
            for (int i = beg + len; i < n; ++i) c[d][posc++] = a[i];

            for(int i = beg + 1; i < n - len + 1; ++i) {
                int posa(0);

                for (int j = 0; j < i; ++j) a[posa++] = c[d][j];
                for (int j = 0; j < posb; ++j) a[posa++] = b[d][j];
                for (int j = i; j < posc; ++j) a[posa++] = c[d][j];

                if(dfs(d + 1, maxd)) return true;
            }
            memcpy(a, temp[d], sizeof(a));
        }
    }
    return false;
}

int main() {
    int Kase(0);
    while(~scanf("%d", &n) && n) {
        for(int i = 0; i < n; ++i) scanf("%d", &a[i]);
        for(int i = 0; i < 9; ++i) if(dfs(0, i)) { ans = i; break; }
        printf("Case %d: %d\n", ++Kase, ans);
    }
    return 0;
}
