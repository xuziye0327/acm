贪心

设要达成的串是 str1， 给的串是 str2。

因为 str2 的 '0' 可以换成 '1'， 先不管 '0'。 相等的话就不用管。 如果 str2 的第 ![i][i] 个位置是 '?'， 往后面扫看有没有 ![1][1] 且 ![2][2]， 如果有就交换， 次数加 2； 否则次数加 1， 把这个 '?' 换成 ![3][3]。 如果 ![4][4]， 向后查找有没有 ![5][5] 并且 ![6][6]。 如果存在就交换， 次数加 1， 否则就不动这个数字。

最后， 如果 ![7][7] 且 ![8][8]， 此题无解， 如果 ![9][9] 且 ![10][10]， 次数加 1。

[i]: https://latex.codecogs.com/gif.latex?i

[1]: https://latex.codecogs.com/gif.latex?str1_i%3Dstr2_j
[2]: https://latex.codecogs.com/gif.latex?str1_j%21%3Dstr2_j
[3]: https://latex.codecogs.com/gif.latex?str1_i
[4]: https://latex.codecogs.com/gif.latex?str1_i%21%3Dstr2_i
[5]: https://latex.codecogs.com/gif.latex?str1_j%3Dstr2_i
[6]: https://latex.codecogs.com/gif.latex?str1_i%3Dstr2_j
[7]: https://latex.codecogs.com/gif.latex?str1_i%3D0
[8]: https://latex.codecogs.com/gif.latex?str2_i%3D1
[9]: https://latex.codecogs.com/gif.latex?str1_i%3D1
[10]: https://latex.codecogs.com/gif.latex?str2_i%3D0