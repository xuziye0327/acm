### 题目链接
<a href="http://poj.org/problem?id=1753">HERE</a>

### 题目描述
给出一个4*4的棋盘，每次选一个位置，这个位置和位于它上下左右位置的棋子正反面交换。
问最少选几个棋子，可以让棋盘上棋子全为白色或者全为黑色。

### 解题思路
4*4的数据量，很小，直接暴力。

``` cpp
#include <cstdio>
#include <algorithm>

using namespace std;

const int dx[] = {0, 1, 0, -1, 0};
const int dy[] = {0, 0, -1, 0, 1};

int ans;
char ma[7][7];

void dfs(int x, int y, int d) {
    if (x > 4) { ++y; x = 1; }
    if (y > 4) {
        char ch = ma[1][1];
        for (int i = 1; i <= 4; ++i) {
            for (int j = 1; j <= 4; ++j) {
                if (ma[i][j] != ch) return ;
            }
        }
        ans = min(ans, d);
        return ;
    }

    for (int i = 0; i < 5; ++i) {
        int tx = x + dx[i];
        int ty = y + dy[i];
        if (tx > 0 && tx <= 4 && ty > 0 && ty <= 4) {
            ma[tx][ty] = ma[tx][ty] == 'b' ? 'w' : 'b';
        }
    }

    dfs(x + 1, y, d + 1);

    for (int i = 0; i < 5; ++i) {
        int tx = x + dx[i];
        int ty = y + dy[i];
        if (tx > 0 && tx <= 4 && ty > 0 && ty <= 4) {
            ma[tx][ty] = ma[tx][ty] == 'b' ? 'w' : 'b';
        }
    }

    dfs(x + 1, y, d);
}

int main() {
    ans = 20;
    for (int i = 1; i <= 4; ++i) scanf("%s", ma[i] + 1);
    dfs(1, 1, 0);
    if (ans == 20) printf("Impossible\n");
    else printf("%d\n", ans);
    return 0;
}
```