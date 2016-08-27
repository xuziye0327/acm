/* ***********************************************
Author        :myz
Created Time  :2016年02月24日 星期三 14时18分26秒
File Name     :main.cpp
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

const int maxn = 50007;

int n;
int ans[maxn];
int tree[maxn];

int lowbit(int x) {
    return x & (-x);
}

void update(int x, int val) {
    while (x <= n) {
        tree[x] += val;
        x += lowbit(x);
    }
}

int sum(int x) {
    int ret = 0;
    while (x) {
        ret += tree[x];
        x -= lowbit(x);
    }
    return ret;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while (~scanf("%d", &n)) {
        memset(ans, 0, sizeof(ans));
        memset(tree, 0, sizeof(tree));
        for (int i = 1; i <= n; ++i) {
            update(i, 1);
        }
        for (int i = 1; i <= n; ++i) {
            int x;
            scanf("%d", &x);
            int l = 1, r = n;
            while (l < r) {
                int mid = (l + r) / 2;
                int t = sum(mid);
                if (t >= x) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            ans[i] = (l + r) / 2;
            update((l + r) / 2, -1);
        }
        int m;
        scanf("%d", &m);
        for (int i = 0; i < m; ++i) {
            int x;
            scanf("%d", &x);
            if (i) {
                printf(" ");
            }
            printf("%d", ans[x]);
        }
        printf("\n");
    }
    return 0;
}
