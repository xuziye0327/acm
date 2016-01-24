/* ***********************************************
Author        :myz
Created Time  :2016年01月23日 星期六 13时33分28秒
File Name     :./ZOJ/2319/main.cpp
************************************************ */

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

const int maxn = 100007;

struct Point {
	int s, b, id;
	bool operator < (const Point k) const {
		return s != k.s ? s < k.s : b > k.b;
	}
}p[maxn];

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	int T;
	bool flag = false;
   	scanf("%d", &T);
	while (T--) {
		if (flag) printf("\n");
		flag = true;
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			scanf("%d%d", &p[i].s, &p[i].b);
			p[i].id = i;
		}
		sort(p + 1, p + n + 1);
		int d[maxn], f[maxn];
		int len = 1;
		d[1] = p[1].b;
		f[1] = len;
		for (int i = 2; i <= n; ++i) {
			if (p[i].b > d[len]) {
				d[++len] = p[i].b;
				f[i] = len;
			} else {
				int pos = lower_bound(d + 1, d + 1 + len, p[i].b) - d;
				d[pos] = p[i].b;
				f[i] = pos;
			}
		}
		int t = len;
		int ans[maxn];
		for (int i = n; i > 0; --i) {
			if (f[i] == t) {
				ans[t--] = p[i].id;
			}
			if (t == 0) {
				break;
			}
		}
		printf("%d\n", len);
		for (int i = 1; i <= len; ++i) {
			if (i != 1) printf(" ");
			printf("%d", ans[i]);
		}
		printf("\n");
	}
    return 0;
}
