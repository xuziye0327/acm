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
#include <sstream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define MP(x,y) make_pair(x,y)
#define CLR(a, b) memset(a, b, sizeof(a))
#define HERE printf("here!\n")
#define BLANK bool blank = false
#define RANDOM srand((unsigned)time(NULL))

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;

const int inf = 1 << 27;
const ull INF = 1ULL << 57ULL;
const int maxn = 20 + 7;
const double eps = 1E-6;

int n, r;
char status[maxn];
double p[maxn];
double pp[maxn];
vector<string> vec;

void init() {
    CLR(p, 0);
    CLR(pp, 0);
    CLR(status, 0);
    vec.clear();
}

void dfs(int pos, int d) {
    if (pos == n) {
        if (d == r) vec.push_back(status);
        return ;
    }

    status[pos] = '0';
    dfs(pos + 1, d);

    if (d < r) {
        status[pos] = '1';
        dfs(pos + 1, d + 1);
    }

    return ;
}

int main() {
    int Kase(0);
    while (scanf("%d%d", &n, &r) && n) {
        init();
        for (int i = 0; i < n; ++i) scanf("%lf", &p[i]);
        dfs(0, 0);
        double tot = 0.0;
        for (int i = 0; i < vec.size(); ++i) {
            double t = 1.0;
            for (int j = 0; j < n; ++j) {
                if (vec[i][j] == '1')
                    t *= p[j];
                else t *= (1.0 - p[j]);
            }
            for (int j = 0; j < n; ++j) {
                if (vec[i][j] == '1') pp[j] += t;
            }
            tot += t;
        }
        printf("Case %d:\n", ++Kase);
        for (int i = 0; i < n; ++i) {
            printf("%f\n", pp[i] / tot);
        }
    }
    return 0;
}