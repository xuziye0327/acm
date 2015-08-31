DP

据说正解是高斯消元。

设 ![dp][1] 为选第 ![i][2] 个数后异或为 ![j][3] 的个数。
则 ![4][4]。

[1]: https://latex.codecogs.com/gif.latex?dp%5Bi%5D%5Bj%5D
[2]: https://latex.codecogs.com/gif.latex?i
[3]: https://latex.codecogs.com/gif.latex?j
[4]: https://latex.codecogs.com/gif.latex?dp%5Bi%5D%5Bk%5Bi%5Dxorj%5D%3Ddp%5Bi-1%5D%5Bj%5D&plus;dp%5Bi-1%5D%5Bk%5Bi%5Dxorj%5D