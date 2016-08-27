#include <bits/stdc++.h>

#define SZ(x) (int) x.size()
#define PB(x) push_back(x)
#define LEN(x) strlen(x);
#define POW2(x) ((x) * (x))
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

const int maxn = 1e2 + 7;
const int maxm = 1e4 + 7;
const int  mod = 1e6;

int n, m, len;
int d[maxn][maxm];

int main() {
    ios::sync_with_stdio(false);
    while (cin >> n >> m && n) {
        memset(d, 0, sizeof d);
        d[0][0] = 1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j <= n; ++j) {
                for (int k = 0; k <= n; ++k) {
                    (d[i + 1][j + k] += d[i][j]) %= mod;;
                }
            }
        }
        cout << d[m][n] << endl;
    }
    return 0;
}

