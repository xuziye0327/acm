### 题目链接
<a href="http://poj.org/problem?id=2965">HERE</a>

### 题目描述
4*4个冰箱，‘+’表示冰箱门关闭，‘-’表示冰箱门打开。选一个点后，这个点和它所在的行列的状态都发生变化，打开变成关闭，关闭变成打开。
求最少选几个点，使得全部冰箱门开启。输出选的门的坐标。

### 解题思路
4*4的数据量，直接枚举。

``` cpp
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef pair<int, int> P;

const int maxn = 27;

P ans[maxn];
P temp[maxn];
int res;
char ma[7][7];

void dfs(int x, int y, int d) {
    if (y > 4) ++x, y = 1;
    if (x > 4) {
        for (int i = 1; i <= 4; ++i) {
            for (int j = 1; j <= 4; ++j) {
                if (ma[i][j] == '+') return ;
            }
        }
        if (d < res) {
            res = d;
            for (int i = 0; i < d; ++i) ans[i] = temp[i];
        }
        return ;
    }

    ma[x][y] = ma[x][y] == '+' ? '-' : '+';
    for (int i = 1; i <= 4; ++i) {
        if (P(x, y) != P(x, i))
            ma[x][i] = ma[x][i] == '+' ? '-' : '+';
        if (P(x, y) != P(i, y))
            ma[i][y] = ma[i][y] == '+' ? '-' : '+';
    }

    temp[d] = P(x, y);
    dfs(x, y + 1, d + 1);

    ma[x][y] = ma[x][y] == '+' ? '-' : '+';
    for (int i = 1; i <= 4; ++i) {
        if (P(x, y) != P(x, i))
            ma[x][i] = ma[x][i] == '+' ? '-' : '+';
        if (P(x, y) != P(i, y))
            ma[i][y] = ma[i][y] == '+' ? '-' : '+';
    }

    dfs(x, y + 1, d);
}

int main() {
    res = 27;
    for (int i = 1; i <= 4; ++i) {
        scanf("%s", ma[i] + 1);
    }
    dfs(1, 1, 0);
    printf("%d\n", res);
    for (int i = 0; i < res; ++i) printf("%d %d\n", ans[i].first, ans[i].second);
    return 0;
}
```