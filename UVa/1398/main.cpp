#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 100007;

struct Event{
    int t;
    bool flag;
    bool operator < (const Event& e) const {
        return t != e.t ? t < e.t : flag < e.flag;
    }
}events[maxn * 2];

void update(int x, int a, int w, int &L, int &R) {
    if (a == 0) {
        if (x <= 0 || x >= w) R = L - 1;
    } else if (a > 0) {
        L = max(L, -x * 2520 / a);
        R = min(R, (w - x) * 2520 / a);
    } else {
        L = max(L, (w - x) * 2520 / a);
        R = min(R, -x * 2520 / a);
    }
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("std.in", "r", stdin);
    #endif // ONLINE_JUDGE

    int T;
    scanf("%d", &T);
    while (T--) {
        int n, w, h, e(0);
        scanf("%d%d", &w, &h);
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            int x, y, a, b;
            scanf("%d%d%d%d", &x, &y, &a, &b);
            int L = 0, R = 1 << 27;
            update(x, a, w, L, R);
            update(y, b, h, L, R);
            if (L < R) {
                events[e++] = (Event) {L, true};
                events[e++] = (Event) {R, false};
            }
        }
        sort(events, events + e);
        int ans = 0, cnt = 0;
        for (int i = 0; i < e; ++i) {
            if (events[i].flag) { ans = max(ans, ++cnt); }
            else --cnt;
        }
        printf("%d\n", ans);
    }
    return 0;
}
