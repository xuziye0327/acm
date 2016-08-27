#include <iostream>
#include <cstdio>
#include <algorithm>

typedef long long ll;

using namespace std;

ll a, b, c, d, p, m;

ll f(ll x, ll y) {
    if(x < 0 || y < 0) return 0;
    ll ma = x % p, mb = y % p;
    ll ans;
    ans = (x / p) * (y / p) * p;
    ans += (ma + 1) * (y / p) + (mb + 1) * (x / p);
    if(ma > m) {
        ans += min(m, mb) + 1;
        ll t = (p + m - ma) % p;
        if(t <= mb) ans += mb - t + 1;
    } else {
        ll t = (p + m - ma) % p;
        if(t <= mb) ans += min(m - t, mb - t) + 1;
    }
    return ans;
}

ll gcd(ll x, ll y) {
    return y == 0 ? x : gcd(y, x % y);
}

int main() {
    int T, Kase(0);
    scanf("%d", &T);
    while(T--) {
        scanf("%I64d%I64d%I64d%I64d%I64d%I64d", &a, &b, &c, &d, &p, &m);
        ll res = f(b, d) - f(a - 1, d) - f(b, c - 1) + f(a - 1, c - 1);
        ll down = (b - a + 1) * (d - c + 1);
        ll g = gcd(res, down);
        printf("Case #%d: %I64d/%I64d\n", ++Kase, res / g, down / g);
    }
    return 0;
}