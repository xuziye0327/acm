/* ***********************************************
Author        :xuziye0327
Created Time  :2016年06月12日 星期日 18时47分26秒
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
		if (b % a) printf("-1\n");
		else printf("%d %d\n", a, b);
	}
    return 0;
}
