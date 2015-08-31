DFS+剪枝

可以构造， 可是我不会。。

设 ![sum][1] 为没有用到的 ![c[1]+c[2]+...+c[n]][2] ， ![maxx][3] 为没用到的 ![c[1]...c[n]][4] 中的最大值。 如果 ![hehe][5] 直接剪枝。

我本以为这样剪枝力度不够， 所以直接写的状态， 又是TLE又是WA了好几次， 然后加上这个剪枝过了。 后来直接用这个剪枝也能过。。 真是够了。

[1]: https://latex.codecogs.com/gif.latex?sum
[2]: https://latex.codecogs.com/gif.latex?c[1]&plus;c[2]&plus;...&plus;c[n]
[3]: https://latex.codecogs.com/gif.latex?maxx
[4]: https://latex.codecogs.com/gif.latex?c[1]...c[n]
[5]: https://latex.codecogs.com/gif.latex?%5Cfrac%7Bmaxx%3E%28sum&plus;1%29%7D%7B2%7D