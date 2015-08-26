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
#define CPY(a, b) memset(a, b, sizeof(b))
#define RANDOM srand((unsigned)time(NULL))

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;

const int maxn = 100000 + 7;

int N;
char s[maxn];

int add(int j) {
    if(j >= 100000) return 6;
    else if(j >= 10000) return 5;
    else if(j >= 1000) return 4;
    else if(j >= 100) return 3;
    else if(j >= 10) return 2;
    else if(j >= 0) return 1;
}

int main() {
    while(~scanf("%s", s)) {
        int len = strlen(s);
        ull ans1(0), ans2(0);
        scanf("%d", &N);
        ans1 += N;
        ans2 += 2 * N;
        int lastbeg(-1), lasten(-1);
        for(int i = 0; i < N; ++i) {
            int beg, en;
            scanf("%d%d", &beg, &en);
            ans1 += en - beg;
            if(i == 0) { ans2 += 1 + en - beg; }
            else {
                int minn = min(en - beg, lasten - lastbeg);
                for(int j = 0; j < minn; ++j) {
                    if(s[beg + j] == s[lastbeg + j]) {
                        if(j == minn - 1) {
                            ans2 += add(j + 1);
                            if(en - beg > lasten - lastbeg) ans2 += (en - beg) - (lasten - lastbeg);
                        }
                        continue;
                    } else {
                        ans2 += add(j) + en - beg - j;
                        break;
                    }
                }
            }
            lastbeg = beg; lasten = en;
        }
        printf("%I64u %I64u\n", ans1, ans2);
    }
    return 0;
}