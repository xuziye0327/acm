#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int inf = 1 << 30;
const int maxn = 110 + 7;

int N, maxk;
int t[maxn][3], c[maxn][2];
int d[maxn][maxn];

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        for(int i = 0; i < maxn; ++i) for(int j = 0; j < maxn; ++j) d[i][j] = inf;
        scanf("%d%d", &N, &maxk);
        for(int i = 1; i <= N; ++i) {
            for(int j = 0; j < 3; ++j) scanf("%d", &t[i][j]);
            for(int j = 0; j < 2; ++j) scanf("%d", &c[i][j]);
        }
        d[0][maxk] = 0;
        for(int i = 1; i <= N; ++i) {
            for(int k = 0; k <= maxk; ++k) {
                d[i][k] = min(d[i][k], d[i - 1][k] + t[i][1]);
                if(k + c[i][0] <= maxk) {
                    d[i][k] = min(d[i][k], d[i - 1][k + c[i][0]] + t[i][0]);
                }
                if(k >= c[i][1] && k != maxk)
                    d[i][k] = min(d[i][k], d[i - 1][k - c[i][1]] + t[i][2]);
                else {
                    for(int kk = max(0, maxk - c[i][1]); kk <= maxk; ++kk) {
                        d[i][maxk] = min(d[i][maxk], d[i - 1][kk] + t[i][2]);
                    }
                }
            }
        }
        int res = inf;
        for(int i = 0; i <= maxk; ++i) {
            res = min(res, d[N][i]);
        }
        printf("%d\n", res);
    }
    return 0;
}