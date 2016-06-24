### 题目链接
<a href="https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=469&page=show_problem&problem=2906">传送门</a>

### 题目描述
在一个m行n列的矩形方格放k个相同的石子，有多少种方法。
并且第一行、最后一行、第一列和最后一列都要有石子。

### 解题思路
简单的容斥原理。

``` cpp
/* ***********************************************
Author        :xuziye0327
Created Time  :2016年06月24日 星期五 16时20分21秒
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

const int maxn = 507;
const int mod = 1000007;

int c[maxn][maxn];

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T, Case(0);
	scanf("%d", &T);
	memset(c, 0, sizeof(c));
	c[0][0] = 1;
	for (int i = 1; i < maxn; ++i) {
		c[i][0] = c[i][i] = 1;
		for (int j = 1; j < i; ++j) {
			c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
		}
	}
	while (T--) {
		int m, n, k;
		scanf("%d%d%d", &m, &n, &k);
		int ans = 0;
		for (int i = 0; i < 16; ++i) {
			int flag = 0, a = m, b = n;
			if (i & 1) { ++flag; --a; }
			if (i & 2) { ++flag; --a; }
			if (i & 4) { ++flag; --b; }
			if (i & 8) { ++flag; --b; }
			if (flag & 1) {
				ans = (ans + mod - c[a * b][k]) % mod;
			} else {
				ans = (ans + c[a * b][k]) % mod;
			}
		}
		printf("Case %d: %d\n", ++Case, ans);
	}
    return 0;
}
```
