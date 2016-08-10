#include <bits/stdc++.h>

#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1

using namespace std;

typedef long long ll;

typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef pair<pii, int> ppi;
typedef pair<double, double> pdd;

const int maxn = 2e5 + 7;
const int  inf = 1 << 27;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
const double eps = 1e-9;
const double PI = acos(-1);

struct Day {
    ll t;
    int id;
    bool operator < (const Day& d) const {
        return t < d.t;
    }
}day[maxn];

ll seg[maxn << 2], days[maxn << 2];

void push_up(int rt) {
    seg[rt] = seg[rt << 1] + seg[rt << 1 | 1];
    days[rt] = days[rt << 1] + days[rt << 1 | 1];
}

void build(int l, int r, int rt) {
    seg[rt] = 0;
    if (l == r) {
        scanf("%I64d", &day[l].t);
        day[l].id = l;
        seg[rt] = day[l].t;
        days[rt] = 1;
        return ;
    }
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
    push_up(rt);
}

void update(int pos, int val, int l, int r, int rt) {
    if (l == r) {
        seg[rt] = val;
        days[rt] = 0;
        return ;
    }
    int m = (l + r) >> 1;
    if (pos <= m) update(pos, val, lson);
    else update(pos, val, rson);
    push_up(rt);
}

ll query(int L, int R, int l, int r, int rt) {
    if (L <= l && r <= R) {
        return seg[rt];
    }
    int m = (l + r) >> 1;
    ll ret = 0;
    if (L <= m) ret += query(L, R, lson);
    if (R >  m) ret += query(L, R, rson);
    return ret;
}

ll query_days(int L, int R, int l, int r, int rt) {
    if (L <= l && r <= R) {
        return days[rt];
    }
    int m = (l + r) >> 1;
    ll ret = 0;
    if (L <= m) ret += query_days(L, R, lson);
    if (R >  m) ret += query_days(L, R, rson);
    return ret;
}

int n, m;
int ans[maxn];

struct Item {
    ll d, r;
    int id;
    bool operator < (const Item& it) const {
        return d < it.d;
    }
}item[maxn];

int main() {
//    freopen("my.out", "w", stdout);
//    ios::sync_with_stdio(false);
    scanf("%d%d", &n, &m);
    build(1, m, 1);
    sort(day + 1, day + 1 + m);
    for (int i = 0; i < n; ++i) {
        scanf("%I64d%I64d", &item[i].d, &item[i].r);
        item[i].id = i;
    }
    int pos = 1;
    sort(item, item + n);
    for (int i = 0; i < n; ++i) {
        while (day[pos].t < item[i].d && pos <= m) {
            update(day[pos++].id, 0, 1, m, 1);
        }
        if (pos > m) ans[item[i].id] = 0;
        else {
            int t = 0;
            int l = 1, r = m;
            while (l <= r) {
                int mid = (l + r) >> 1;
                ll sum = query(1, mid, 1, m, 1);
                ll days_num = query_days(1, mid, 1, m, 1);
                if (sum - days_num * item[i].d >= item[i].r) {
                    t = mid;
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            ans[item[i].id] = t;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (i) printf(" ");
        printf("%d", ans[i]);
    }
    return 0;
}
