#include <bits/stdc++.h>

#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define F first
#define S second

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int maxn = 500000 + 7;

struct ST {
    pii sub, pre, suf;
}st[maxn << 2];

ll sum[maxn];

ll get_sum(int l, int r) {
    return sum[r] - sum[l - 1];
}

ll get_sum(pii p) {
    return get_sum(p.F, p.S);
}

pii better(pii p1, pii p2) {
    if (get_sum(p1.F, p1.S) == get_sum(p2.F, p2.S)) return p1 < p2 ? p1 : p2;
    return get_sum(p1.F, p1.S) > get_sum(p2.F, p2.S) ? p1 : p2;
}

void push_up(int rt) {
    ll t1 = get_sum(st[rt << 1].pre.F, st[rt << 1].pre.S);
    ll t2 = get_sum(st[rt << 1].pre.F, st[rt << 1 | 1].pre.S);
    if (t1 >= t2) st[rt].pre = st[rt << 1].pre;
    else st[rt].pre = pii(st[rt << 1].pre.F, st[rt << 1 | 1].pre.S);

    t1 = get_sum(st[rt << 1].suf.F, st[rt << 1 | 1].suf.S);
    t2 = get_sum(st[rt << 1 | 1].suf.F, st[rt << 1 | 1].suf.S);
    if (t1 >= t2) st[rt].suf = pii(st[rt << 1].suf.F, st[rt << 1 | 1].suf.S);
    else st[rt].suf = st[rt << 1 | 1].suf;

    st[rt].sub = better(st[rt << 1].sub, st[rt << 1 | 1].sub);
    st[rt].sub = better(st[rt].sub, pii(st[rt << 1].suf.F, st[rt << 1 | 1].pre.S));
}

void build(int l, int r, int rt) {
    if (l == r) {
        st[rt].sub = st[rt].pre = st[rt].suf = pii(l, r);
        return ;
    }
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
    push_up(rt);
}

pii query_pre(int L, int R, int l, int r, int rt) {
    if (L <= l && r <= R) {
        return st[rt].pre;
    }
    int m = (l + r) >> 1;
    pii ret1 = pii(-1, -1), ret2 = pii(-1, -1);
    if (L <= m) ret1 = query_pre(L, R, lson);
    if (R >  m) ret2 = query_pre(L, R, rson);
    if (ret1.F == -1) return ret2;
    if (ret2.F == -1) return ret1;
    return better(ret1, pii(ret1.F, ret2.S));
}

pii query_suf(int L, int R, int l, int r, int rt) {
    if (L <= l && r <= R) {
        return st[rt].suf;
    }
    int m = (l + r) >> 1;
    pii ret1 = pii(-1, -1), ret2 = pii(-1, -1);
    if (L <= m) ret1 = query_suf(L, R, lson);
    if (R >  m) ret2 = query_suf(L, R, rson);
    if (ret1.F == -1) return ret2;
    if (ret2.F == -1) return ret1;
    return better(ret2, pii(ret1.F, ret2.S));
}

pii query(int L, int R, int l, int r, int rt) {
    if (L <= l && r <= R) {
        return st[rt].sub;
    }
    int m = (l + r) >> 1;
    if (R <= m) return query(L, R, lson);
    else if (L > m) return query(L, R, rson);
    else {
        return better(better(query(L, R, lson), query(L, R, rson)), pii(query_suf(L, R, lson).F, query_pre(L, R, rson).S));
    }
}

int main() {
    int n, m, Case(0);
    while (~scanf("%d%d", &n, &m)) {
        sum[0] = 0;
        for (int i = 1; i <= n; ++i) {
            scanf("%lld", &sum[i]);
            sum[i] += sum[i - 1];
        }
        build(1, n, 1);
        printf("Case %d:\n", ++Case);
        while (m--) {
            int x, y;
            scanf("%d%d", &x, &y);
            pii ans = query(x, y, 1, n, 1);
            printf("%d %d\n", ans.F, ans.S);
        }
    }
    return 0;
}
/*
3 1
1 -1 1
2 3
*/
