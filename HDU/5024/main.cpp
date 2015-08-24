#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 100 + 7;
const int dx[] = {0, 0, 1, -1, 1, -1, 1, -1};
const int dy[] = {1, -1, 0, 0, -1, 1, 1, -1};

int res, N;
char ma[maxn][maxn];

void init() {
    res = 0;
    for(int i = 0; i < maxn; ++i)
        for(int j = 0; j < maxn; ++j) ma[i][j] = '#';
}

void solve(int x, int y) {
    int a[8] = {0};
    for(int i = 0; i < 8; ++i) {
        for(int j = 0; ; ++j) {
            if(ma[x + dx[i] * j][y + dy[i] * j] == '.') ++a[i];
            else break;
        }
    }
    for(int i = 0; i < 8; ++i) {
        for(int j = 0; j < 8; ++j) {
            if(i != j) {
                if((i < 4 && j < 4) || (i >= 4 && j >= 4)) {
                    res = max(res, a[i] + a[j] - 1);
                }
            }
        }
    }
}

int main() {
    while(~scanf("%d", &N) && N) {
        init();
        for(int i = 1; i <= N; ++i) scanf("%s", ma[i] + 1);
        for(int i = 1; i <= N; ++i)
            for(int j = 1; j <= N; ++j) if(ma[i][j] == '.') solve(i, j);
        printf("%d\n", res);
    }
    return 0;
}