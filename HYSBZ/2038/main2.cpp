#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;

typedef long long ll;
const int maxn = 50007;

int n, m, t;
ll ans[maxn];
int a[maxn], cor[maxn], part[maxn];

struct Point {
    int x, y, id;
    bool operator < (const Point& k) const {
        return part[x] != part[k.x] ? part[x] < part[k.x] : part[y] < part[k.y];
    }
}p[maxn];

ll getT(ll x) {
    return x * (x - 1);
}

void update(int l, int r, int val) {
    for ( ; l <= r; ++l) {
        t -= getT(cor[a[l]]);
        cor[a[l]] += val;
        t += getT(cor[a[l]]);
    }
}

void solve() {
    t = 0;
    ++cor[a[1]];
    int l = 1, r = 1;
    for (int i = 1; i <= m; ++i) {
        if (l < p[i].x) update(l, p[i].x - 1, -1);
        if (l > p[i].x) update(p[i].x, l - 1, 1);
        if (r < p[i].y) update(r + 1, p[i].y, 1);
        if (r > p[i].y) update(p[i].y + 1, r, -1);
        l = p[i].x;
        r = p[i].y;
        ans[p[i].id] = t;
    }
}

ll gcd(ll a, ll b) {
    if (a < b) swap(a, b);
    return b == 0 ? a : gcd(b, a % b);
}

bool cmp(const Point& k1, const Point& k2) {
    return k1.id < k2.id;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    for (int i = 1; i <= m; ++i) {
        scanf("%d%d", &p[i].x, &p[i].y, p[i].id = i);
    }
    int lim = (int) sqrt(n + 0.5);
    for (int i = 1; i <= n; ++i) {
        part[i] = (i - 1) / lim + 1;
    }
    sort(p + 1, p + 1 + m);
    solve();
    sort(p + 1, p + 1 + m, cmp);
    for (int i = 1; i <= m; ++i) {
        ll t = (ll)getT(p[i].y - p[i].x + 1);
        ll g = gcd(ans[i], t);
        printf("%lld/%lld\n", ans[i] / g, t / g);;
    }
    return 0;
}
