/* ***********************************************
Author        :myz
Created Time  :2015年12月22日 星期二 16时47分37秒
File Name     :./hdu/1257/main.cpp
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

const int maxn = 1007;

int ma[maxn], t[maxn];

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n;
    while (~scanf("%d", &n)) {
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &ma[i]);
            bool flag = false;
            for (int j = 0; j < ans; ++j) {
                if (t[j] >= ma[i]) {
                    t[j] = ma[i];
                    flag = true;
                    break;
                }
            }
            if (!flag) {
                t[ans++] = ma[i];
			}
		}
		printf("%d\n", ans);
	}	
	return 0;
}
