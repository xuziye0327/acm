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
