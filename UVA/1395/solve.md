最小生成树

把边权按从小到大排序， 对于边权在区间 ![[L, R]](https://latex.codecogs.com/gif.latex?[L,R]) 内的边， 如果能构成一颗树， 那么一定存在一个苗条度不超过 ![W[R]-W[L]](https://latex.codecogs.com/gif.latex?W[R]-W[L]) 的生成树。

用并查集判断新加入边是否可以构成树即可。 判断时用set会T的。。
