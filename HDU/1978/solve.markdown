##solve##
DP

$dp[i][j]$ 表示到点 $i, j$ 的总步数。

状态转移方程为 : $dp[i][j] = dp[i - m][j - n]$。