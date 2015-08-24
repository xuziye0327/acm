#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

const int maxn = 20000 + 7;

int N;
ll A[maxn], B[maxn], C[maxn];

ll solve(ll m, ll &sum) {
    ll res(0LL);
    for(int i = 0; i < N; ++i) {
        ll temp = min(m, B[i]);
        if(temp >= A[i]) sum += (temp - A[i]) / C[i] + 1;
        if(m > B[i] || m < A[i]) continue;
        if((m - A[i]) % C[i] == 0) ++res;
    }
    return res;
}

int main() {
    while(~scanf("%d", &N)) {
        ll pos(0LL), res(0LL), r(0LL), l(0LL), mid;
        for(int i = 0; i < N; ++i) {
            scanf("%I64d%I64d%I64d", &A[i], &B[i], &C[i]);
            r = max(r, B[i]);
        }
        while(l <= r) {
            ll cnt(0LL);
            mid = (r - l) / 2 + l;
            res = solve(mid, cnt);
            if(res & 1) {
                pos = mid;
                break;
            } else {
                if(cnt & 1) {
                    r = mid;
                } else {
                    l = mid + 1LL;
                }
            }
        }
        if(!pos) printf("DC Qiang is unhappy.\n");
        else printf("%I64d %I64d\n", pos, res);
    }
    return 0;
}