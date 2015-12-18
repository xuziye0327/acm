#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int inf = 1 << 30;
const int maxn = 10 + 7;
const int dx[] = {0, 0, 1, -1, 1, -1, 1, -1};
const int dy[] = {1, -1, 0, 0, 1, -1, -1, 1};

int n, m, ans;
char ma[maxn][maxn];
char temp[100][maxn][maxn];

void init() {
    ans = 6;
}

bool judge_X(int x, int y) {
    if(ma[x][y] == 'X') return true;
    for(int i = 0; i < 8; ++i) {
        for(int j = 1; ; ++j) {
            if(x + dx[i] * j <= n && x + dx[i] * j >= 1 && y + dy[i] * j <= m && y + dy[i] * j >= 1) {
                if(ma[x + dx[i] * j][y + dy[i] * j] == 'X') return true;
            } else break;
        }
    }
    return false;
}

void change_front(int x, int y) {
    ma[x][y] = 'Q';
    for(int i = 0; i < 8; ++i) {
        for(int j = 1; ; ++j) {
            if(x + dx[i] * j <= n && x + dx[i] * j >= 1 && y + dy[i] * j <= m && y + dy[i] * j >= 1) {
                ma[x + dx[i] * j][y + dy[i] * j] = '.';
            } else break;
        }
    }
}

void dfs(int x, int y, int cnt) {
    if(cnt >= ans) return ;

    bool ok = true;

//    printf("====\n");
//    for(int i = 1; i <= n; ++i) {
//        for(int j = 1; j <= m; ++j) {
//            printf("%c", ma[i][j]);
//        }
//        printf("\n");
//    }

    if(x > n) { x = 1; ++y; }
    if(y > m) return ;

    memcpy(temp[cnt], ma, sizeof(ma));
    change_front(x, y);

    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j) if(ma[i][j] == 'X') ok = false;

    if(ok) { ans = min(ans, cnt); return ; }

    int tx(x + 1), ty(y);
    while (true) {
        if(tx > n) { tx = 1; ++ty; }
        if(ty > m) return ;
        if(judge_X(tx, ty)) {
            dfs(tx, ty, cnt + 1);
            break;
        }
        ++tx;
    }
    memcpy(ma, temp[cnt], sizeof(ma));
    dfs(tx, ty, cnt);
}

int main() {
    int Kase(0);
    while(~scanf("%d", &n) && n) {
        scanf("%d", &m);
        for(int i = 1; i <= n; ++i) scanf("%s", ma[i] + 1);
        init();
        bool ok = false;
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= m; ++j) {
                if(judge_X(i, j)) {
                    ok = true;
                    dfs(i, j, 1);
                    break;
                }
            }
            if(ok) break;
        }
        printf("Case %d: %d\n", ++Kase, ans == 6 ? 0 : ans);
    }
    return 0;
}