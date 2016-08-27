### 题目链接
<a href = "https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=497&page=show_problem&problem=3146">传送门</a>

### 题目描述
根据一系列的操作判断队列，有限队列和栈。

### 解题思路
直接模拟。

``` cpp
/* ***********************************************
Author        :xuziye0327
Created Time  :2016年07月04日 星期一 18时19分57秒
File Name     :main.cpp
************************************************ */

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
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
	int n;
	while (~scanf("%d", &n)) {
		stack<int> sta;
		queue<int> que;
		priority_queue<int> pque;
		while (!sta.empty()) {
			sta.pop();
			que.pop();
			pque.pop();
		}
		bool ok1 = true, ok2 = true, ok3 = true;
		while (n--) {
			int x, y;
			scanf("%d%d", &x, &y);
			if (x == 1) {
				sta.push(y);
				que.push(y);
				pque.push(y);
			} else {
				if (sta.empty()) {
					continue;
				}	
				if (sta.top() != y) ok1 = false;
				if (que.front() != y) ok2 = false;
				if (pque.top() != y) ok3 = false;
				sta.pop();
				que.pop();
				pque.pop();
			}
		}
		if (ok1 && !ok2 && !ok3) printf("stack\n");
		else if (ok2 && !ok1 && !ok3) printf("queue\n");
		else if (ok3 && !ok1 && !ok2) printf("priority queue\n");
		else if (!ok1 && !ok2 && !ok3) printf("impossible\n");
		else printf("not sure\n");
	}
    return 0;
}
```
