#include <cstdio>
#include <vector>

using namespace std;

const int maxn = 1120 + 7;

int res[maxn][14 + 7];
bool prim[maxn];
vector<int> prims;

void getPrim() {
    for (int i = 2; i < maxn; ++i) prim[i] = true;
    for (int i = 2; i < maxn; ++i) if (prim[i]) {
        prims.push_back(i);
        for (int j = i + i; j < maxn; j += i) prim[j] = false;
    }
}

void solve() {
    res[0][0] = 1;
    for (int i = 0; i < prims.size(); ++i) {
        for (int j = 14; j > 0; --j) {
            for (int k = maxn - 1; k >= 0; --k) {
                if (k - prims[i] < 0) break;
                if (res[k - prims[i]][j - 1]) {
                    res[k][j] += res[k - prims[i]][j - 1];
                }
            }
        }
    }
}

int main() {
    getPrim();
    solve();
    int n, k;
    while (scanf("%d%d", &n, &k) && n) {
        printf("%d\n", res[n][k]);
    }
    return 0;
}
