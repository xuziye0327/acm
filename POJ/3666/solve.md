### 题目链接
<a href="http://poj.org/problem?id=3666">HERE</a>

### 题目描述
又一段凹凸不平的路，FJ想把这条路变为递增或递减（非严格），改变一个高度所需要的花费是|A - B|，求出最少的花费。

### 解题思路
dp[i][j]表示前i段变成递增或递减且第i - 1段是b[j]的最小花费。
那么状态转移方程为dp[i][j]=min(dp[i-1][k])+|Ai-Bk|，（1 <= K <= j）。

``` cpp
/* ***********************************************
Author        :myz
Created Time  :2016年02月12日 星期五 15时03分07秒
File Name     :a.cpp
************************************************ */

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

const int maxn = 2007;

int a[maxn], b[maxn], dp[maxn][maxn];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        b[i] = a[i];
    }
    sort(b, b + n);
    for (int i = 0; i < n; ++i) {
        dp[0][i] = abs(a[0] - b[i]);
    }
    for (int i = 1; i < n; ++i) {
        int minn = dp[i - 1][0];
        for (int j = 0; j < n; ++j) {
            minn = min(minn, dp[i - 1][j]);
            dp[i][j] = minn + abs(a[i] - b[j]);
        }
    }
    int ans = dp[n - 1][0];
    for (int i = 1; i < n; ++i) {
        ans = min(ans, dp[n - 1][i]);
    }
    printf("%d", ans);
    return 0;
}
```
