最大流

给出前 ![i][1] 行所有元素之和 ![Ai][3] 和前 ![j][2] 列所有元素之和 ![Bj][4]， 求出元素为 ![1...20][5] 的一个 ![R*C][6] 的矩阵。

很容易求出第 ![i][1] 行元素之和 ![A'i][7] 和 第 ![j][2] 列元素之和 ![B'j][8]， 如果矩阵中每个元素减一， 则每一行元素之和应该减 ![C][9]， 每一列元素之和应该减 ![R][10]。 这样矩阵中元素范围就是 ![0...19][11]， 根据这个原理构建出网络流。

每行对应一个 ![X][12]， 每列对应一个 ![Y][13]， 源点到 ![X_i][14] 的容量为 ![A'i-C][16]， ![Y_i][15] 到终点的容量为 ![B'i-R][17], ![X][12] 到每一个 ![Y][13] 的容量为 ![19][18]。 第 ![i][1] 行 ![j][2] 列的元素就为 ![Xi-Yj+1][19]。

[1]: https://latex.codecogs.com/gif.latex?i
[2]: https://latex.codecogs.com/gif.latex?j
[3]: https://latex.codecogs.com/gif.latex?A%5Bi%5D
[4]: https://latex.codecogs.com/gif.latex?B%5Bi%5D
[5]: https://latex.codecogs.com/gif.latex?1...20
[6]: https://latex.codecogs.com/gif.latex?R*C
[7]: https://latex.codecogs.com/gif.latex?A%27%5Bi%5D
[8]: https://latex.codecogs.com/gif.latex?B%27%5Bj%5D
[9]: https://latex.codecogs.com/gif.latex?C
[10]: https://latex.codecogs.com/gif.latex?R
[11]: https://latex.codecogs.com/gif.latex?0...19
[12]: https://latex.codecogs.com/gif.latex?X
[13]: https://latex.codecogs.com/gif.latex?Y
[14]: https://latex.codecogs.com/gif.latex?X_i
[15]: https://latex.codecogs.com/gif.latex?Y_i
[16]: https://latex.codecogs.com/gif.latex?A%27%5Bi%5D-C
[17]: https://latex.codecogs.com/gif.latex?B%27%5Bi%5D-R
[18]: https://latex.codecogs.com/gif.latex?19
[19]: https://latex.codecogs.com/gif.latex?X_i-Y_j&plus;1