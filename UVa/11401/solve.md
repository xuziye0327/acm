### 题目链接
<a href = "https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2396">传送门</a>

### 题目描述
从1, 2, ..., n中选3个不同的数，使它们可以组成三角形， 有多少种选法。

### 解题思路
设s[x]为最大边为x时有多少中选法。
次长边为x - 1时， 可选的数为x - 2, x - 3, ..., 2， 共有x - 3个。
次长边为x - 2时， 可选的数为x - 3, x - 4, ..., 3， 共有x - 5个。
可以推出s[x] = (x - 3) + (x - 5) + ... + (x - (2 * k + 1))。
x - (2 * k + 1) >= 0, k <= (x - 1) / 2。
s[x] = k * x - k * (k + 2)。
递推得出解。

``` cpp
/* ***********************************************
Author        :xuziye0327
Created Time  :2016年06月12日 星期日 13时26分47秒
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

const int maxn = 1000007;

ull f[maxn];

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    memset(f, 0, sizeof f);
	for (ull i = 4; i < maxn; ++i) {
		ull k = (i - 1) / 2;
		f[i] = f[i - 1] + k * i - k * (k + 2);
	}
	int n;
	while (scanf("%d", &n)) {
		if (n < 3) break;
		printf("%llu\n", f[n]);
	}
    return 0;
}
```
