/* ***********************************************
Author        :xuziye0327
Created Time  :2016年07月04日 星期一 21时17分35秒
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
#define ABS(x) ((x) < 0 ? -(x) : (x))
using namespace std;

const int maxn = 20007;

int fa[maxn], d[maxn];

int update(int x) {
	if (x == fa[x]) return x;
	int pa = update(fa[x]);
	d[x] += d[fa[x]];
	return fa[x] = pa;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T;
	scanf("%d", &T);
	while (T--) {
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) fa[i] = i, d[i] = 0;
		char cmd[2];
		while (scanf("%s", cmd) && cmd[0] != 'O') {
			int a, b;
			if (cmd[0] == 'E') {
				scanf("%d", &a);
				update(a);
				printf("%d\n", d[a]);
			} else {
				scanf("%d%d", &a, &b);
				fa[a] = b;
				d[a] = ABS(a - b) % 1000;
			}
		}
	}
    return 0;
}
