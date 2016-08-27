/* ***********************************************
Author        :myz
Created Time  :2016年02月21日 星期日 16时13分38秒
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

const int maxn = 1007;

int n;
int tree[maxn][maxn];

int lowbit(int x) {
    return x & (-x);
}

void update(int x, int y, int val) {
    for (int i = x; i <= n; i += lowbit(i)) {
        for (int j = y; j <= n; j += lowbit(j)) {
            tree[i][j] += val;
        }
    }
}

int quary(int x, int y) {
    int sum = 0;
    for (int i = x; i > 0; i -= lowbit(i)) {
        for (int j = y; j > 0; j -= lowbit(j)) {
            sum += tree[i][j];
        }
    }
    return sum;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T;
    bool blank = false;
    scanf("%d", &T);
    while (T--) {
        memset(tree, 0, sizeof(tree));
        if (blank) printf("\n");
        blank = true;
        int q;
        scanf("%d%d", &n, &q);
        while (q--) {
            char cmd[7];
            scanf("%s", cmd);
            if (cmd[0] == 'C') {
                int x1, y1, x2, y2;
                scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
                update(x1, y1, 1);
                update(x2 + 1, y1, -1);
                update(x1, y2 + 1, -1);
                update(x2 + 1, y2 + 1, 1);
            } else {
                int x, y;
                scanf("%d%d", &x, &y);
                printf("%d\n", quary(x, y) & 1 ? 1 : 0);
            }
        }
    }
    return 0;
}

