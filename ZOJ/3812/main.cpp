#include <cstdio>
#include <map>
#include <cstring>

using namespace std;

const int M = 51;
const int maxn = 400 + 7;

typedef unsigned long long ull;

ull f[200000 + 7];
int ans[200000 + 7][50 + 7];
int W[maxn], T[maxn];
map<ull, int> ma;

int main() {
    for(int i = 1; i <= M + 1; i++) ma[1LL << (i - 1LL)] = i - 1;
    int t;
    scanf("%d", &t);
    while(t--) {
        memset(f, 0, sizeof(f));
        memset(W, 0, sizeof(W));
        memset(T, 0, sizeof(T));
        memset(ans, 0, sizeof(ans));
        f[0] = 1;
        int N, Q;
        scanf("%d%d", &N, &Q);
        for(int i = 1; i <= N; i++) {
            scanf("%d%d", &W[i], &T[i]);
            for(int j = 200000; j >= T[i]; j--) {
                ull v = f[j];
                f[j] |= (f[j - T[i]] << W[i]) & ((1LL << M + 1) - 1);
                for(ull k = v ^ f[j]; k; k &= (k - 1)) {
                    ull x = k & (-k);
                    ans[j][ma[x]] = i;
                }
            }
        }
        for(int i = 1; i <= Q; i++) {
            int M, S;
            scanf("%d%d", &M, &S);
            if(!ans[S][M]) {
                printf("No solution!\n");
            } else {
                printf("%d", ans[S][M]);
                int tt;
                tt = ans[S][M];
                M -= W[tt];
                S -= T[tt];
                while(ans[S][M]) {
                    printf(" %d", ans[S][M]);
                    tt = ans[S][M];
                    M -= W[tt];
                    S -= T[tt];
                }
                printf("\n");
            }
        }
    }
    return 0;
}