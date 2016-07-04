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
