### 题目链接
<a href = "https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=467&page=show_problem&problem=2989">传送门</a>

### 题目描述
输入a和c， 求最小的b使得lcm(a, b) = c。

### 解题思路
c % a != 0， 无解。
令b = c / a。
1. gcd(a, b) == 1, 解为b。
2. g = gcd(a, b) != 1， 这时b不为解， 因为a, b还有公共因子， 把这些公因子去掉， 即a /= g, b *= g， 直到gcd(a, b) == 1。

```
/* ***********************************************
Author        :xuziye0327
Created Time  :2016年06月12日 星期日 18时52分43秒
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

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T;
	scanf("%d", &T);
	while (T--) {
		int a, b;
		scanf("%d%d", &a, &b);
		if (b % a) printf("NO SOLUTION\n");
		else {
			int x = a, y = b;
			b /= a;
			int g = __gcd(a, b);
			while (g != 1) {
				a /= g;
				b *= g;
				g = __gcd(a, b);
			}
			printf("%d\n", b);
		}
	}
    return 0;
}

```
