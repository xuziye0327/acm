区间DP

有 ![n][1] 头狼， 砍第 ![i][2] 只狼收到的伤害是第 ![i][2] 只狼的攻击力和它左右两只狼对它的加成， 问最后砍完 ![n][1] 只狼受到的伤害最小是多少。

设 ![$dp[i][j]$][3] 为杀死 ![i-j][4] 区间内的狼受到的最小伤害。 则有状态转移方程 ![d[i][j]=dp[i][k-1]+dp[k+1][j]+a[k]+b[i-1]+b[j+1]][5]。 砍 ![i][2] 和 ![j][6] 只狼的时候需要特判一下。

[1]: https://latex.codecogs.com/gif.latex?n
[2]: https://latex.codecogs.com/gif.latex?i
[3]: https://latex.codecogs.com/gif.latex?dp%5Bi%5D%5Bj%5D
[4]: https://latex.codecogs.com/gif.latex?i...j
[5]: https://latex.codecogs.com/gif.latex?d%5Bi%5D%5Bj%5D%3Ddp%5Bi%5D%5Bk-1%5D&plus;dp%5Bk&plus;1%5D%5Bj%5D&plus;a%5Bk%5D&plus;b%5Bi-1%5D&plus;b%5Bj&plus;1%5D
[6]: https://latex.codecogs.com/gif.latex?j