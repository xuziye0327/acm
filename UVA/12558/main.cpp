#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>

using namespace std;

typedef long long ll;

const int maxn = 5 + 7;

ll a, b, k, maxd;
ll v[maxn * 1000], ans[maxn * 1000];
set<ll> cannt;

ll gcd(ll a_, ll b_) {
    return b_ == 0 ? a_ : gcd(b_, a_ % b_);
}

ll get_first(ll aa, ll bb) {
    for(ll i = 1; ; ++i) if(aa * i >= bb) return i;
}

bool batter(ll d) {
    for(ll i = d; i >= 0; --i) if(v[i] != ans[i])
            return ans[i] == -1 || v[i] < ans[i];
    return false;
}

bool dfs(ll d, ll from, ll aa, ll bb) {
    if(d == maxd) {
        if(bb % aa) return false;
        if(!cannt.count(bb / aa)) {
            v[d] = bb / aa;
            if(batter(d)) memcpy(ans, v, sizeof(ll) * (d + 1));
            return true;
        }
    }
    bool ok = false;
    from = max(from, get_first(aa, bb));
    for(ll i = from; ; ++i) {
        if(bb * (maxd + 1 - d) <= i * aa) break;
        if(cannt.count(i)) continue;
        v[d] = i;
        ll a_ = aa * i - bb;
        ll b_ = bb * i;
        ll g = gcd(b_, a_);
        if(dfs(d + 1, i + 1, a_ / g, b_ / g)) ok = true;
    }
    return ok;
}

int main() {
    int T, Kase(0);
    scanf("%d", &T);
    while(T--) {
        cannt.clear();
        memset(v, 0, sizeof(v));
        scanf("%lld%lld%lld", &a, &b, &k);
        for(int i = 1; i <= k; ++i) {
            ll t;
            scanf("%lld", &t);
            cannt.insert(t);
        }
        for(maxd = 1; ; ++maxd) {
            memset(ans, -1, sizeof(ans));
            if(dfs(0, get_first(a, b), a, b)) break;
        }
        printf("Case %d: %lld/%lld=", ++Kase, a, b);
        for(int i = 0; ans[i] != -1; ++i) {
            if(i) printf("+");
            printf("1/%lld", ans[i]);
        }
        printf("\n");
    }
    return 0;
}