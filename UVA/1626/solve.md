DP

两种情况， 设 S1 为合法串。

设 ![dp][1] 为第 ![i][i] 和 ![j][j] 个括号区间所需要加括号的最小数。

1. 出现 "(S1)", "[S1]"， 则 ![dp2][2]
2. 无论是否为第一种情况， ![dp3][3]

[i]: https://latex.codecogs.com/gif.latex?i
[j]: https://latex.codecogs.com/gif.latex?i

[1]: https://latex.codecogs.com/gif.latex?dp_{ij}
[2]: https://latex.codecogs.com/gif.latex?dp_%7Bij%7D%3Dmin%28dp_%7B%28i&plus;1%29%28j-1%29%7D%29
[3]: https://latex.codecogs.com/gif.latex?dp_%7Bij%7D%3Dmin%28dp_%7Bik%7D&plus;dp_%7B%28k&plus;1%29j%7D%29