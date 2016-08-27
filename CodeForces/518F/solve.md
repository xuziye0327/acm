### 题目链接

<a href="http://codeforces.com/problemset/problem/518/F">传送门</a>



### 题目描述

定义f(i,j) 为A[1,2 ... i-1, j+1, ... n]中任意两数最大公约数的最大值。

求![1][1]。


### 解题思路

设H[i]为有多少f(l, r) <= i。

next[j] = k, f(j, k) <= i, k 尽量小。当k不存在的时候next[j] = n + 1。

H[i] = ![2][2]。因为对于f(j, next[i]) <= i， 所有f(j, i), i > next[i]的最大公约数都小于i。

假设已经知道了f(j,k) <= i的next值，如何求f(j,k)<=i-1的值。

设v[i]=p1, p2, ..., pk-1, pk为A中能被i整除的数的下标，从小到大排序。

如果f(l,r)以外包含大于等于2个能被i整除的数，那么f(l,r)>=i。所以一段next[i]，必须包含至少k-1个能被i整除的数。

对于next[j], 1<=j<=p1, next[j] = max(next[j], pk-1)。

p1<j<=p2, next[j] = max(next[j], pk)。

p2 < j, next[j] = n + 1。 

``` cpp
#include <bits/stdc++.h>

using namespace std;

const int maxn = 2007;

typedef unsigned long long ull;

int n, m;
int sumr[maxn][maxn];
int sumc[maxn][maxn];
int l[maxn][maxn];
int r[maxn][maxn];
int sumUp[maxn][maxn];
int sumDown[maxn][maxn];
char t[maxn][maxn];
char ma[maxn][maxn];

void getSum() {
    memset(sumr, 0, sizeof sumr);
    memset(sumc, 0, sizeof sumc);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            sumr[i][j] = sumr[i][j - 1] + (ma[i][j] == '#');
        }
    }
    for (int j = 1; j <= m; ++j) {
        for (int i = 1; i <= n; ++i) {
            sumc[j][i] = sumc[j][i - 1] + (ma[i][j] == '#');
        }
    }
}

void Swap() {
    memset(l, 0, sizeof l);
    memset(r, 0, sizeof r);
    memset(sumUp, 0, sizeof sumUp);
    memset(sumDown, 0, sizeof sumDown);
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            t[i][j] = ma[j][m - i + 1];
        }
    }
    swap(n, m);
    memcpy(ma, t, sizeof ma);
    getSum();
    for (int i = 1; i <= n; ++i) {
        l[i][0] = 0;
        r[i][m + 1] = m + 1;
        for (int j = 1; j <= m; ++j) {
            if (ma[i][j] == '#') l[i][j] = j;
            else l[i][j] = l[i][j - 1];
            if (sumc[j][i]) sumUp[i][j] = sumUp[i][j - 1];
            else {
                sumUp[i][j] = sumUp[i][j - 1] + 1;
            }
        }
        for (int j = m; j >= 1; --j) {
            if (ma[i][j] == '#') r[i][j] = j;
            else r[i][j] = r[i][j + 1];
        }
    }
    for (int i = n; i >= 1; --i) {
        for (int j = 1; j <= m; ++j) {
            if (sumc[j][n] - sumc[j][i - 1]) sumDown[i][j] = sumDown[i][j - 1];
            else sumDown[i][j] = sumDown[i][j - 1] + 1;
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) scanf("%s", ma[i] + 1);
    ull ans0 = 0, ans1 = 0, ans2 = 0;
    getSum();
    for (int i = 2; i <= n - 1; ++i) if (!sumr[i][m]) ++ans0;
    for (int j = 2; j <= m - 1; ++j) if (!sumc[j][n]) ++ans0;

    for (int j = 2; j <= m - 1; ++j) {
        for (int i = 2; i <= n - 1; ++i) {
            if (!sumc[j][i] && !sumr[i][j]) ++ans1;
            if (!sumc[j][i] && !(sumr[i][m] - sumr[i][j - 1])) ++ans1;
            if (!(sumc[j][n] - sumc[j][i - 1]) && !sumr[i][j]) ++ans1;
            if (!(sumc[j][n] - sumc[j][i - 1]) && !(sumr[i][m] - sumr[i][j - 1])) ++ans1;
        }
    }

    int T = 4;
    while (T--) {
        Swap();
        for (int i = 2; i <= n - 1; ++i) {
            for (int j = 2; j <= m - 1; ++j) if (ma[1][j] == '.' && ma[i][j] == '.' && !sumc[j][i]) {
                int rpos = r[i][j];
                int lpos = l[i][j];
                if (j > 2) ans2 += sumDown[i][j - 1] - sumDown[i][max(1, lpos)];
                if (rpos > j + 1) ans2 += sumDown[i][min(m - 1, rpos - 1)] - sumDown[i][j];
                if (rpos > j + 2) ans2 += sumUp[i][min(m - 1, rpos - 1)] - sumUp[i][j + 1];
                if (j > 3) ans2 += sumUp[i][j - 2] - sumUp[i][max(1, lpos)];
            }
        }
    }
    printf("%I64u\n", ans0 + ans1 + ans2 / 2);
    return 0;
}
```

[1]: http://latex.codecogs.com/gif.latex?%5Csum_%7Bi%3D1%7D%5E%7Bn%7D%7B%5Csum_%7Bj%3D1%7D%5E%7Bn%7D%7Bf%28i%2C%20j%29%7D%7D
[2]: http://latex.codecogs.com/png.latex?%5Csum_%7Bp%3D1%7D%5E%7Bn%7D%7Bn-next%5Bp%5D+1%7D