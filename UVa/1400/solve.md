### 题目链接
<a href="https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=501&page=show_problem&problem=4146">传送门</a>

### 解题思路
线段树每一个节点维护最大前缀和、最大后缀和和最大字段和。更新和查询的时候，每个最大子段和 = max(左右子节点最大字段和，左节点最大后缀和+右节点最大前缀和)。最大前缀后缀和的更新和查询方法和上面的一样。

