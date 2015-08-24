#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 250 + 7;

int M, N;
int cnt[5];
char ma[maxn][maxn];

int getnum(const char ch) {
    if(ch == 'B') return 0;
    if(ch == 'J') return 1;
    if(ch == 'H') return 2;
    if(ch == 'Y') return 3;
    if(ch == 'N') return 4;
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &M, &N);
        int res = 0;
        for(int i = 1; i <= M; ++i) scanf("%s", ma[i] + 1);
        for(int i = 1; i <= N; ++i) {
            for(int j = i + 1; j <= N; ++j) {
                memset(cnt, 0, sizeof(cnt));
                for(int k = 1; k <= M; ++k) {
                    if(ma[k][i] == ma[k][j]) {
                        ++cnt[getnum(ma[k][i])];
                    }
                }
                for(int k = 0; k < 5; ++k) res += cnt[k] * (cnt[k] - 1) / 2;
            }
        }
        printf("%d\n", res);
    }
    return 0;
}
