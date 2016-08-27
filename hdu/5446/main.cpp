#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;
typedef pair<pii, ll> ppi;
typedef pair<pii, pii> ppp;

const int maxn = 17;

ll mul(ll a, ll b, ll mod) {
    ll ans = 0;
    while(b) {
        if(b & 1) ans = (ans + a) % mod;
        b >>= 1;
        a = (a + a) % mod;
    }
    return ans;
}

ll ext_gcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1; y = 0;
        return a;
    } else {
        ll r = ext_gcd(b, a % b, y, x);
        y -= x * (a / b);
        return r;
    }
}

ll CRT(vector<ll> a, vector<ll> m, int n) {
    ll M = 1;
    for (int i = 0; i < n; ++i) M *= m[i];
    ll ret = 0;
    for (int i = 0; i < n; ++i) {
        ll x, y;
        ll tm = M / m[i];
        ext_gcd(tm, m[i], x, y);
        ll t1 = mul(x, tm, M);
        ll t2 = mul(t1, a[i], M);
//        (tm * x * a[i]) % M = (tm % M * x % M * a[i] % M) % M;
//        ll t1 = mul(tm, x, M);
//        ll t2 = mul(t1, a[i], M);
//        cout << tm * x * a[i] << " " << t2 << endl;
        ret = (ret + t2) % M;
    }
    return (ret + M) % M;
}

ll quick_mod(ll a,ll b,ll m){
    ll ans = 1;
    a %= m;
    while(b){
        if(b&1)
            ans = ans * a % m;
        b >>= 1;
        a = a * a % m;
    }
    return ans;
}

ll getC(ll n, ll m,ll mod){
    if(m > n)
        return 0;
    if(m > n-m)
        m = n-m;
    ll a = 1,b = 1;
    while(m){
        a = (a*n)%mod;
        b = (b*m)%mod;
        m--;
        n--;
    }
    return a*quick_mod(b,mod-2,mod)%mod;
}

ll Lucas(ll n,ll k,ll mod){
    if(k == 0)
        return 1;
    return getC(n%mod,k%mod,mod)*Lucas(n/mod,k/mod,mod)%mod;
}

ll n, m, k;
ll p[maxn];
vector<ll> a, c;

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    int T, Case(0);
    scanf("%d", &T);
    while (T--) {
        a.clear();
        c.clear();
        scanf("%I64d%I64d%I64d", &n, &m, &k);
        for (int i = 0; i < k; ++i) {
            scanf("%I64d", &p[i]);
            c.push_back(p[i]);
            a.push_back(Lucas(n, m, p[i]) % p[i]);
        }
        printf("%I64d\n", CRT(a, c, k));
    }
    return 0;
}
