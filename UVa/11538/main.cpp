/* ***********************************************
Author        :xuziye0327
Created Time  :2016年06月11日 星期六 20时26分57秒
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

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    ull n, m;
	while (scanf("%llu%llu", &n, &m) && n) {
		if (n < m) swap(n, m);
		ull t1 = n * m * (m - 1);
		ull t2 = m * n * (n - 1);
		ull t3 = m * (m - 1) * (2 * m - 1) / 3 - (m - 1) * m + (n - m + 1) * (m - 1) * m;
		printf("%llu\n", t1 + t2 + t3 * 2);
	}
    return 0;
}
