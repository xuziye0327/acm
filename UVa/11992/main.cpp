#include <bits/stdc++.h>

#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define pb push_back

using namespace std;

const int maxn = 20 + 7;
const int maxm = 1e6 + 7;
const int  inf = 1 << 30;

struct ST {
    int lazy_set, lazy_add;
    int maxx, minn, sum;
}st[maxn][maxm << 2];

void push_up(int id, int rt) {
    st[id][rt].maxx = max(st[id][rt << 1].maxx, st[id][rt << 1 | 1].maxx);
    st[id][rt].minn = min(st[id][rt << 1].minn, st[id][rt << 1 | 1].minn);
    st[id][rt].sum = st[id][rt << 1].sum + st[id][rt << 1 | 1].sum;
}

void push_down(int id, int rt, int m) {
    if (st[id][rt].lazy_set != -1) {
        st[id][rt << 1].lazy_set = st[id][rt << 1 | 1].lazy_set = st[id][rt].lazy_set;
        st[id][rt << 1].lazy_add = st[id][rt << 1 | 1].lazy_add = 0;
        st[id][rt << 1].maxx = st[id][rt << 1 | 1].maxx = st[id][rt].lazy_set;
        st[id][rt << 1].minn = st[id][rt << 1 | 1].minn = st[id][rt].lazy_set;
        st[id][rt << 1].sum = (m - (m >> 1)) * st[id][rt].lazy_set;
        st[id][rt << 1 | 1].sum = (m >> 1) * st[id][rt].lazy_set;
        st[id][rt].lazy_set = -1;
    }
    if (st[id][rt].lazy_add) {
        st[id][rt << 1].lazy_add += st[id][rt].lazy_add;
        st[id][rt << 1 | 1].lazy_add += st[id][rt].lazy_add;
        st[id][rt << 1].maxx += st[id][rt].lazy_add; st[id][rt << 1 | 1].maxx += st[id][rt].lazy_add;
        st[id][rt << 1].minn += st[id][rt].lazy_add; st[id][rt << 1 | 1].minn += st[id][rt].lazy_add;
        st[id][rt << 1].sum += (m - (m >> 1)) * st[id][rt].lazy_add;
        st[id][rt << 1 | 1].sum += (m >> 1) * st[id][rt].lazy_add;
        st[id][rt].lazy_add = 0;
    }
}

void update1(int id, int L, int R, int v, int l, int r, int rt) {
    if (L <= l && r <= R) {
        st[id][rt].maxx = st[id][rt].minn = v;
        st[id][rt].lazy_add = 0; st[id][rt].lazy_set = v;
        st[id][rt].sum = (r - l + 1) * v;
        return ;
    }
    push_down(id, rt, r - l + 1);
    int m = (l + r) >> 1;
    if (L <= m) update1(id, L, R, v, lson);
    if (R  > m) update1(id, L, R, v, rson);
    push_up(id, rt);
}

void update2(int id, int L, int R, int v, int l, int r, int rt) {
    if (L <= l && r <= R) {
        st[id][rt].maxx += v; st[id][rt].minn += v;
        st[id][rt].lazy_add += v;
        st[id][rt].sum += (r - l + 1) * v;
        return ;
    }
    push_down(id, rt, r - l + 1);
    int m = (l + r) >> 1;
    if (L <= m) update2(id, L, R, v, lson);
    if (R  > m) update2(id, L, R, v, rson);
    push_up(id, rt);
}

bool flag;
int ans_max, ans_min, ans_sum;

void query(int id, int L, int R, int l, int r, int rt) {
    if (L <= l && r <= R) {
        if (flag) ans_max = st[id][rt].maxx;
        else ans_max = max(ans_max, st[id][rt].maxx);
        if (flag) ans_min = st[id][rt].minn;
        else ans_min = min(ans_min, st[id][rt].minn);
        ans_sum += st[id][rt].sum;
        flag = false;
        return ;
    }
    push_down(id, rt, r - l + 1);
    int m = (l + r) >> 1;
    if (L <= m) query(id, L, R, lson);
    if (R  > m) query(id, L, R, rson);
}

void build(int id, int l, int r, int rt) {
    st[id][rt].maxx = 0;
    st[id][rt].minn = 0;
    st[id][rt].sum = 0;
    st[id][rt].lazy_add = 0;
    st[id][rt].lazy_set = -1;
    if (l == r) {
        return ;
    }
    int m = (l + r) >> 1;
    build(id, lson);
    build(id, rson);
}

int main() {
    int n, m, q;
    while (~scanf("%d%d%d", &n, &m, &q)) {
        for (int i = 1; i <= n; ++i) build(i, 1, m, 1);
        while (q--) {
            int cmd, x1, y1, x2, y2, v;
            scanf("%d%d%d%d%d", &cmd, &x1, &y1, &x2, &y2);
            if (cmd == 3) {
                flag = true;
                ans_sum = 0;
                for (int i = x1; i <= x2; ++i) query(i, y1, y2, 1, m, 1);
                printf("%d %d %d\n", ans_sum, ans_min, ans_max);
            } else {
                scanf("%d", &v);
                for (int i = x1; i <= x2; ++i)
                if (cmd == 1) update2(i, y1, y2, v, 1, m, 1);
                else update1(i, y1, y2, v, 1, m, 1);
            }
        }
    }
    return 0;
}
