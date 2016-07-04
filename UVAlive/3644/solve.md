### 题目链接
<a href = "https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&category=19&page=show_problem&problem=1645">传送门</a>

### 题目描述
每个化学物由两种元素组成，按所给的顺序把化合物装进车里，如果有k个化学物正好有k个元素，则它们将组成一个易爆的化学物。在保证车上不能有易爆的化学物的前提下，有多少个化学物不能被装到车上。

### 解题思路
并查集，如果要放到车上的两个化学物在同一个集合中，就不能添加。

``` cpp
/* ***********************************************
Author        :xuziye0327
Created Time  :2016年07月04日 星期一 20时31分23秒
File Name     :main.cpp
************************************************ */

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

const int maxn = 100007;

int fa[maxn];

int findFa(int x) { return x == fa[x] ? x : fa[x] = findFa(fa[x]); }

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	int a, b;
    while (~scanf("%d", &a) && a != -1) {
		for (int i = 0; i < maxn; ++i) {
			fa[i] = i;
		}
		scanf("%d", &b);
		int ans = 0;
		fa[a] = b;
		while (scanf("%d", &a) && a != -1) {
			scanf("%d", &b);
			a = findFa(a);
			b = findFa(b);
			if (a == b) ++ans;
			fa[a] = b;
		}
		printf("%d\n", ans);
	}
    return 0;
}
```
