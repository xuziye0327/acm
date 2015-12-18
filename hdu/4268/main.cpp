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

#define CLR(a, b) memset(a, b, sizeof(a))

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;

const int maxn = 100000 + 7;

struct Rect {
    int h, w;
    bool operator < (const Rect &k) const {
        return h < k.h;
    }
};

Rect Alice[maxn], Bob[maxn];

int N;
multiset<int> s;

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        s.clear();
        int res(0);
        scanf("%d", &N);
        for(int i = 0; i < N; ++i) scanf("%d%d", &Alice[i].h, &Alice[i].w);
        for(int i = 0; i < N; ++i) scanf("%d%d", &Bob[i].h, &Bob[i].w);
        sort(Alice, Alice + N);
        sort(Bob, Bob + N);
        for(int i = 0, j = 0; i < N; ++i) {
            while(Alice[i].h >= Bob[j].h && j < N) { s.insert(Bob[j].w); ++j; }
            multiset<int> :: iterator it = s.upper_bound(Alice[i].w);
            if(it != s.begin()) { --it; s.erase(it); ++res; }
        }
        printf("%d\n", res);
    }
    return 0;
}
