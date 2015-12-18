暴力/扩展欧几里得

暴力不再多说。

![公式][1]

可以枚举 ![a][a] 的取值， 根据扩展欧几里得求出 ![b][b] 和 ![k][k]， 验证下是否满足数列。

[1]: https://latex.codecogs.com/gif.latex?%5C%5C%20x_2%3D%28a*x_1&plus;b%29mod10001%5C%5C%20x_3%3D%28a*x_2&plus;b%29mod10001%5C%5C%20x_3%3D%28a*%28a*x_1&plus;b%29mod10001&plus;b%29mod10001%5C%5C%20x_3%3D%28a*%28a*x_1&plus;b%29&plus;b%29mod10001%5C%5C%20x_3&plus;10001*k%3Da*%28a*x_1&plus;b%29&plus;b%5C%5C%20%28a&plus;1%29*b-10001k%3Dx_3-a*a*x_1%5C%5C
[a]: https://latex.codecogs.com/gif.latex?a
[b]: https://latex.codecogs.com/gif.latex?a
[k]: https://latex.codecogs.com/gif.latex?a