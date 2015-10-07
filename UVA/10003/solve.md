区间DP

把一个长 ![L][L] 的木棍切 ![n][n] 次。 只能切给出的 ![n][n] 个点， 每次切割的花费等于被切的木棍的长度。 求最小花费。

设 ![dij][1] 为切 ![i-j][2] 区间所需的最小花费， 则 ![3][3]。

[n]: https://latex.codecogs.com/gif.latex?n
[L]: https://latex.codecogs.com/gif.latex?L

[1]: https://latex.codecogs.com/gif.latex?d_%7Bij%7D
[2]: https://latex.codecogs.com/gif.latex?i-j
[3]: https://latex.codecogs.com/gif.latex?d_%7Bij%7D%20%3D%20min%28d_%7Bik%7D&plus;d_%7Bkj%7D&plus;a_j-a_i%29
