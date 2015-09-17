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
const int maxn = 7 + 7;
const double eps = 1E-6;

int k;
char str[maxn];
string pas1[maxn], pas2[maxn];
vector<char> vec[maxn];
set<char> used;
set<string> ans;

void init() {
    ans.clear();
    for (int i = 0; i < maxn; ++i) {
        vec[i].clear();
        pas1[i].clear();
        pas2[i].clear();
    }
}

void dfs(int pos) {
    if (pos == 5) {
        ans.insert(str);
        return ;
    }

    for (int i = 0; i < vec[pos].size(); ++i) {
        str[pos] = vec[pos][i];
        dfs(pos + 1);
    }
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        init();
        scanf("%d", &k);
        for (int i = 0; i < 6; ++i) cin >> pas1[i];
        for (int i = 0; i < 6; ++i) cin >> pas2[i];
        for (int i = 0; i < 5; ++i) {
            used.clear();
            for (int j = 0; j < 6; ++j) {
                for (int k = 0; k < 6; ++k) {
                    if (pas1[j][i] == pas2[k][i]) {
                        if (!used.count(pas1[j][i])) {
                            vec[i].push_back(pas1[j][i]);
                            used.insert(pas1[j][i]);
                        }
                    }
                }
            }
        }
        // 枚举做法
        /*dfs(0);
        if (k > ans.size()) printf("NO\n");
        else {
            int cnt = 1;
            auto it = ans.begin();
            for (; it != ans.end(); ++it) {
                if (cnt == k) { cout << *it << endl; break; }
                ++cnt;
            }
        }*/
        // 数学做法
        int maxx(1);
        for (int i = 0; i < 5; ++i) maxx *= vec[i].size();
        if (k > maxx) printf("NO\n");
        else {
            string res;
            for (int i = 0; i < 5; ++i) {
                sort(vec[i].begin(), vec[i].end());
                maxx /= vec[i].size();
                for (int j = 1; j <= vec[i].size(); ++j) {
                    if (j * maxx >= k) {
                        res += vec[i][j - 1];
                        k -= maxx * (j - 1);
                        break;
                    }
                }
            }
            cout << res << endl;
        }
    }
    return 0;
}
/*
3
1
AYGSU
DOMRA
CPFAS
XBODG
WDYPK
PRXWO
CBOPT
DOSBG
GTRAR
APMMS
WSXNU
EFGHI
*/