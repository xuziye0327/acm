#include <iostream>
#include <cstdio>

#include <cstring>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <ctime>

#include <stack>
#include <queue>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define MP(x,y) make_pair(x,y)
#define CLR(a, b) memset(a, b, sizeof(a))
#define HERE printf("here!\n")
#define RANDOM srand((unsigned)time(NULL))

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;

const int inf = 1 << 30;
const int maxn = 5 + 7;
const double eps = 1E-6;

int N, M, K;
int c[maxn * maxn];
int ma[maxn][maxn];

bool dfs(int x, int y) {
    if(x > N) { x = 1; ++y; }

    if(y > M) {
        printf("YES\n");
        for(int i = 1; i <= N; ++i) {
            for(int j = 1; j <=M; ++j) {
                if(j != 1) printf(" ");
                printf("%d", ma[i][j]);
            }
            printf("\n");
        }
        return true;
    }

    int maxx(0), sum(0);
    for(int i = 1; i <= K; ++i) if(c[i]) {
            maxx = max(maxx, c[i]);
            sum += c[i];
        }

    if(maxx > (sum + 1) / 2) return false;

    for(int i = 1; i <= K; ++i) if(c[i]) {
            if(ma[x - 1][y] != i && ma[x][y - 1] != i) {
                --c[i];
                ma[x][y] = i;
                if(dfs(x + 1, y)) return true;
                ma[x][y] = 0;
                ++c[i];
            }
        }

    return false;
}

int main() {
    int T, Kase(0);
    scanf("%d", &T);
    while(T--) {
        CLR(ma, 0);
        scanf("%d%d%d", &N, &M, &K);
        for(int i = 1; i <= K; ++i) scanf("%d", &c[i]);
        printf("Case #%d:\n", ++Kase);
        bool flag = dfs(1, 1);
        if(!flag) printf("NO\n");
    }
    return 0;
}