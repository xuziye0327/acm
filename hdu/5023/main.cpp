#include <bits/stdc++.h>
 
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
 
using namespace std;
 
const int maxn = 1000007;
 
struct St {
    int res, lazy;
}st[maxn << 2];
 
void push_up(int rt) {
    st[rt].res = st[rt << 1].res | st[rt << 1 | 1].res;
}
 
void push_down(int rt) {
    if (st[rt].lazy) {
        st[rt << 1].lazy = st[rt << 1 | 1].lazy = st[rt].lazy;
        st[rt << 1].res = 1 << st[rt].lazy;
        st[rt << 1 | 1].res = 1 << st[rt].lazy;
        st[rt].lazy = 0;
    }
}
 
void build(int l, int r, int rt) {
    st[rt].res = 1 << 2;
    st[rt].lazy = 0;
    if (l == r) return ;
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
    push_up(rt);
}
 
void update(int L, int R, int val, int l, int r, int rt) {
    if (L <= l && r <= R) {
        st[rt].lazy = val;
        st[rt].res = 1 << val;
        return ;
    }
    int m = (l + r) >> 1;
    push_down(rt);
    if (L <= m) update(L, R, val, lson);
    if (R >  m) update(L, R, val, rson);
    push_up(rt);
}
 
int query(int L, int R, int l, int r, int rt) {
    if (L <= l && r <= R) {
        return st[rt].res;
    }
    int m = (l + r) >> 1;
    int ret = 0;
    push_down(rt);
    if (L <= m) ret |= query(L, R, lson);
    if (R >  m) ret |= query(L, R, rson);
    return ret;
}
 
int main() {
    int n, m;
    while (~scanf("%d%d", &n, &m) && n) {
        build(1, n, 1);
        while (m--) {
            char cmd[2];
            int l, r, x;
            scanf("%s", cmd);
            if (cmd[0] == 'P') {
                scanf("%d%d%d", &l, &r, &x);
                update(l, r, x, 1, n, 1);
            } else {
                scanf("%d%d", &l, &r);
                int ret = query(l, r, 1, n, 1);
                bool flag = false;
                for (int i = 1; i <= 30; ++i) {
                    if ((ret >> i) & 1) {
                        if (flag) printf(" ");
                        printf("%d", i);
                        flag = true;
                    }
                }
                printf("\n");
            }
        }
    }
    return 0;
}