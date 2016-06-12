/* ***********************************************
Author        :xuziye0327
Created Time  :2016年06月12日 星期日 18时52分43秒
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
		if (b % a) printf("NO SOLUTION\n");
		else {
			int x = a, y = b;
			b /= a;
			int g = __gcd(a, b);
			while (g != 1) {
				a /= g;
				b *= g;
				g = __gcd(a, b);
			}
			printf("%d\n", b);
		}
	}
    return 0;
}
