##solve##
BFS
因为可以跨越不大于 k 的障碍, 所以用了 pair<pair<int, int>, int>。 里面的 pair<int, int>
用来保存坐标。 int 用来保存步数。