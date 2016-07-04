/* ***********************************************
Author        :xuziye0327
Created Time  :2016年07月04日 星期一 19时25分11秒
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

const int maxn = 1007;

struct Item {
	int a, b, c;
	bool operator < (const Item& k) const {
		return b == k.b ? a > k.a : b > k.b;
	}
};

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	char cmd[27];
	priority_queue<Item> que;
   	while (scanf("%s", cmd) && cmd[0] != '#') {
		Item item;
		scanf("%d%d", &item.a, &item.b);
		item.c = item.b;
		que.push(item);
	}
	int x;
	scanf("%d", &x);
	while (x--) {
		Item it = que.top();
		printf("%d\n", it.a);
		que.pop();
		it.b += it.c;
		que.push(it);
	}
    return 0;
}
