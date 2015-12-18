/*
 * 树状数组
#include <bits/stdc++.h>

using namespace std;

const int maxn = 50000 + 7;

int N;
int C[maxn];
char cmd[maxn];

int lowbit(int k) {
    return k & (-k);
}

void update(int pos, int val) {
    for(int i = pos; i <= N; i += lowbit(i)) {
        C[i] += val;
    }
}

int getsum(int pos) {
    int s(0);
    for(int i = pos; i > 0; i -= lowbit(i)) {
        s += C[i];
    }
    return s;
}

int main() {
    int t, Case(0);
    scanf("%d", &t);
    while(t--) {
        memset(C, 0, sizeof(C));
        printf("Case %d:\n", ++Case);
        scanf("%d", &N);
        for(int i = 1; i <= N; i++) {
            int p;
            scanf("%d", &p);
            update(i, p);
        }
        while(scanf("%s", cmd) && cmd[0] != 'E') {
            int i, j;
            scanf("%d%d", &i, &j);
            if(cmd[0] == 'A') {
                update(i, j);
            } else if(cmd[0] == 'S') {
                update(i, -j);
            } else {
                printf("%d\n", getsum(j) - getsum(i - 1));
            }
        }
    }
    return 0;
}
*/

#include <cstdio>
#include <cstring>
/*
 * 单点修改， 区间求和
 */
// lson 左儿子
// rson 右儿子
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1

const int maxn = 50000 + 7;

//至少开 4 * maxn 的数组
int sum[maxn * 4];

//向上更新
void pushUp(int rt) {
    sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}

// 建立线段树
void build(int l, int r, int rt) {
    if(l == r) {
        scanf("%d", &sum[rt]);
        return ;
    }
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
    pushUp(rt);
}

// 单点修改
void update(int p, int add, int l, int r, int rt) {
    if(l == r) {
        sum[rt] += add;
        return ;
    }
    int m = (l + r) >> 1;
    if(p <= m) update(p, add, lson);
    else update(p, add, rson);
    pushUp(rt);
}

// 区间求和
int query(int L, int R, int l, int r, int rt) {
    if(L <= l && r <= R) {
        return sum[rt];
    }
    int cnt(0);
    int m = (l + r) >> 1;
    if(L <= m) cnt += query(L, R, lson);
    if(R > m) cnt += query(L, R, rson);
    return cnt;
}

int main() {
    int T, Kase(0);
    scanf("%d", &T);
    while(T--) {
        memset(sum, 0, sizeof(sum));
        printf("Case %d:\n", ++Kase);
        int n;
        scanf("%d", &n);
        build(1, n, 1);
        char cmd[19];
        while(~scanf("%s", cmd)) {
            if(cmd[0] == 'E') break;
            int a, b;
            scanf("%d%d", &a, &b);
            if(cmd[0] == 'A') {
                update(a, b, 1, n, 1);
            }
            if(cmd[0] == 'S') {
                update(a, -b, 1, n, 1);
            }
            if(cmd[0] == 'Q') {
                printf("%d\n", query(a, b, 1, n, 1));
            }
        }
    }
    return 0;
}