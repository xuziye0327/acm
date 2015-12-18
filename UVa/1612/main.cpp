#include <iostream>
#include <cstdio>

#include <cstring>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <ctime>

#include <stack>
#include <queue>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define MP(x,y) make_pair(x,y)
#define CLR(a, b) memset(a, b, sizeof(a))
#define RANDOM srand((unsigned)time(NULL))

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;

const int maxn = 20000 + 7;

struct Peo {
    int sec[8];
}peo[maxn];

int n;
int ran[maxn];

int main() {
    int Kase(0);
    while(~scanf("%d", &n) && n) {
        for (int i = 1; i <= n; ++i) {
            int a, b, c;
            double aa, bb, cc;
            scanf("%lf%lf%lf", &aa, &bb, &cc);
            a = (int) round(aa * 100.0); b = (int) round(bb * 100.0); c = (int) round(cc * 100.0);
            peo[i].sec[0] = 0;
            peo[i].sec[1] = a;
            peo[i].sec[2] = b;
            peo[i].sec[3] = c;
            peo[i].sec[4] = a + b;
            peo[i].sec[5] = a + c;
            peo[i].sec[6] = b + c;
            peo[i].sec[7] = a + b + c;
            sort(peo[i].sec, peo[i].sec + 8);
        }
        int lastsec = 0;
        bool ok = false;
        for (int i = 0; i < n; ++i) scanf("%d", &ran[i]);
        for (int i = 0; i < n; ++i) {
            int now = ran[i];
            if(!i) {
                lastsec = peo[now].sec[7];
                ok = true;
            } else {
                int lastran = ran[i - 1];
                ok = false;
                for(int j = 7; j >= 0; --j) {
                    if(lastsec == peo[now].sec[j]) {
                        if(now > lastran) {
                            ok = true;
                            break;
                        }
                    } else if (lastsec > peo[now].sec[j]){
                        lastsec = peo[now].sec[j];
                        ok = true;
                        break;
                    }
                }
            }
            if(!ok) break;
        }
        printf("Case %d: ", ++Kase);
        if(ok) printf("%.2f\n", lastsec / 100.0);
        else printf("No solution\n");
    }
    return 0;
}
