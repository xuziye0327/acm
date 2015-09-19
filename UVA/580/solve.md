组合数学

设答案为 ![f(n)][1]， 有 ![n][n] 个盒子且不满足条件的种类 ![g(n)=2^n-f(n)][2]。

另第 ![i-1][i-1] 个盒子放 ‘L’， 前 ![i-2][i-2] 个盒子没有三个‘U’放一起， ![i,i+1,i+2][i,i+1,i+2] 三个盒子放‘U’。 那么这种情况下的个数共有 ![g(i-2)*2^{n-i-2}][3] 个。 则 ![f(n)=2^(n-3)+/sum_{i=2}^{n-2}{g(i-2)*2^(n-i-2)}][4]。

[n]: https://latex.codecogs.com/gif.latex?n
[i-1]: https://latex.codecogs.com/gif.latex?i-1
[i-2]: https://latex.codecogs.com/gif.latex?i-2
[i,i+1,i+2]: https://latex.codecogs.com/gif.latex?i%2Ci&plus;1%2Ci&plus;2

[1]: https://latex.codecogs.com/gif.latex?n
[2]: https://latex.codecogs.com/gif.latex?g%28n%29%3D2%5En-f%28n%29
[3]: https://latex.codecogs.com/gif.latex?g%28i-2%29*2%5E%7Bn-i-2%7D
[4]: https://latex.codecogs.com/gif.latex?f%28n%29%3D2%5E%7Bn-3%7D&plus;%5Csum_%7Bi%3D2%7D%5E%7Bn-2%7D%7Bg%28i-2%29*2%5E%7Bn-i-2%7D%7D
