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

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	int a, b;
    while (~scanf("%d", &a) && a != -1) {
		memset(fa, 0, sizeof(fa));
		scanf("%d", &b);
		int k = 1, cnt = 2, ans = 0;
		fa[a] = fa[b] = -1;
		while (scanf("%d", &a) && a != -1) {
			scanf("%d", &b);
			int t = (fa[a] != -1) + (fa[b] != -1);
			if (cnt + t == k + 1) ans++;
			else {
				fa[a] = fa[b] = -1;
				cnt += t;
				++k;
			}
		}
		printf("%d\n", ans);
	}
    return 0;
}
