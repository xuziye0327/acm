#include <cstdio>
#include <iostream>

/*
 * �ɶ��滻
 */
// lson �����
// rson �Ҷ���
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1

using namespace std;

const int maxn = 100000 + 7;

// ���ٿ� 4 * maxn ������
int n;
int sum[maxn * 4];
// ������
int lazy[maxn * 4];

// ���ϸ���
void pushUp(int rt) {
    sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}

// ���¸���
void pushDown(int rt, int m) {
    if(lazy[rt]) {
        lazy[rt << 1] = lazy[rt << 1 | 1] = lazy[rt];
        sum[rt << 1] = (m - (m >> 1)) * lazy[rt];
        sum[rt << 1 | 1] = (m >> 1) * lazy[rt];
        lazy[rt] = 0;
    }
}

// �����߶���
void build(int l, int r, int rt) {
    lazy[rt] = 0;
    sum[rt] = 1;
    if(l == r) return ;
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
    pushUp(rt);
}

// �����޸�
void update(int L, int R, int c, int l, int r, int rt) {
    if(L <= l && r <= R) {
        lazy[rt] = c;
        sum[rt] = (r - l + 1) * c;
        return ;
    }
    pushDown(rt, r - l + 1);
    int m = (l + r) >> 1;
    if(L <= m) update(L, R, c, lson);
    if(R > m) update(L, R, c, rson);
    pushUp(rt);
}

int main() {
    int T, Kase(0);
    scanf("%d", &T);
    while(T--) {
        int n, Q;
        scanf("%d%d", &n, &Q);
        build(1, n, 1);
        while(Q--) {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            update(a, b, c, 1, n, 1);
        }
        printf("Case %d: The total value of the hook is %d.\n", ++Kase, sum[1]);
    }
    return 0;
}