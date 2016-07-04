/* ***********************************************
Author        :xuziye0327
Created Time  :2016年07月04日 星期一 18时43分32秒
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

map<int, vector<int> > ma;

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n, m;
	while (~scanf("%d%d", &n, &m)) {
		ma.clear();
		for (int i = 1; i <= n; ++i) {
			int x;
			scanf("%d", &x);
			if (ma.count(x)) ma[x].push_back(i);
			else {
				ma[x] = vector<int>();
				ma[x].push_back(i);
			}
		}
		while (m--) {
			int k, v;
			scanf("%d%d", &k, &v);
			if (!ma.count(v) || ma[v].size() < k) printf("0\n");
			else printf("%d\n", ma[v][k - 1]);
		}
	}
    return 0;
}
