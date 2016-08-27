最短路

一个赛车比赛。 每条路用5个整数表示 ![u,v,a,b,t][1]。 起点是 ![u][u]， 终点是 ![v][v]， 通过时间是 ![t][t]， 这条道路会打开 ![a][a] 秒， 然后关闭 ![b][b] 秒。 求 ![s][s] 到 ![t][t] 的最短时间。

用最短路求即可。 ![du][du] 为到 ![u][u] 点所需要的最短时间， ![t1=du%(a+b)][2] 判断当前道路有没有关闭。 如果 ![t1=0...a-1][3] 则没有关闭， ![t1=a....a+b-1][4] 道路关闭。 道路开启时判断从当前时间能不能通过， 如果能通过就直接加 ![t][t]， 否则要等到道路下一次开启； 道路关闭判断下一次开启是否能通过， dij搞一下就行了。

[a]: https://latex.codecogs.com/gif.latex?a
[b]: https://latex.codecogs.com/gif.latex?b
[u]: https://latex.codecogs.com/gif.latex?u
[v]: https://latex.codecogs.com/gif.latex?v
[s]: https://latex.codecogs.com/gif.latex?s
[t]: https://latex.codecogs.com/gif.latex?t
[du]: https://latex.codecogs.com/gif.latex?d%5Bu%5D
[1]: https://latex.codecogs.com/gif.latex?u%2Cv%2Ca%2Cb%2Ct
[2]: https://latex.codecogs.com/gif.latex?t1%3Dd%5Bu%5D%25%28a&plus;b%29
[3]: https://latex.codecogs.com/gif.latex?t1%3D0...a-1
[4]: https://latex.codecogs.com/gif.latex?t1%3Da....a&plus;b-1