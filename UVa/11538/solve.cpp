### 题目链接
<a href = "https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2533">传送门</a>

### 题目描述
n * m的棋盘放两个皇后， 有多少种方法可以让他们互相攻击。

### 解题思路
假设n >= m。
每一行上放置方法为m * (m - 1)， 一共n行， 这一部分的放置方法有n * m * (m - 1)。
同理，列为m * n * (n - 1)。
考虑斜线，斜向的方格数为1, 2, ..., m, m, ..., m, ..., 2, 1。其中m的个数有(n - m + 1)个， 求和乘2就行了。

```
/* ***********************************************
Author        :xuziye0327
Created Time  :2016年06月11日 星期六 20时26分57秒
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

typedef unsigned long long ull;

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    ull n, m;
	while (scanf("%llu%llu", &n, &m) && n) {
		if (n < m) swap(n, m);
		ull t1 = n * m * (m - 1);
		ull t2 = m * n * (n - 1);
		ull t3 = m * (m - 1) * (2 * m - 1) / 3 - (m - 1) * m + (n - m + 1) * (m - 1) * m;
		printf("%llu\n", t1 + t2 + t3 * 2);
	}
    return 0;
}

```
