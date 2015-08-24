#include <cstring>
#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;

typedef pair<int, int> P;
typedef unsigned int ui;

const int maxn = 15 + 7;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

int R, C;
bool used[maxn][maxn];
bool used2[maxn][maxn];
char ma[maxn][maxn];
char temp[maxn * 2];
string nans, bans;
vector<string> vec;

bool cmp(const string &str1, const string &str2) {
    return !(str1.size() != str2.size() ? str1.size() < str2.size() : str1 < str2);
}

bool cmp2(const char &ch1, const char &ch2) {
    return ch1 > ch2;
}

int bfs(int x, int y) {
    memset(used2, false, sizeof(used2));
    int cnt(0);
//    set<P> s;
    queue<P> que;
    while(!que.empty()) que.pop();
//    s.insert(make_pair(x, y));
    used2[x][y] = true;
    que.push(make_pair(x, y));

    while(!que.empty()) {
        ++cnt;
        P p = que.front(); que.pop();
        x = p.first; y = p.second;
        for(int i = 0; i < 4; ++i) {
            int tx = x + dx[i], ty = y + dy[i];
            if(used2[tx][ty]) continue;
            if(tx >= 1 && tx <= R && ty >= 1 && ty <= C) {
                if(ma[tx][ty] != '#' && !used[tx][ty]) {
                    que.push(make_pair(tx, ty));
                    used2[tx][ty] = true;
                }
            }
        }
    }
    return cnt;
}

void dfs(int x, int y, int d) {
    temp[d] = ma[x][y];
    temp[d + 1] = 0;
    nans = temp;

    int lastnum = bfs(x, y);
    bool ok = false;

    if(d + lastnum < bans.size()) {
        return ;
    } else if(d + lastnum == bans.size()) {
        if(nans < bans.substr(0, (ui) d)) return ;
    }

    for(int i = 0; i < 4; ++i) {
        int tx = x + dx[i], ty = y + dy[i];
        if(tx >= 1 && tx <= R && ty >= 1 && ty <= C) {
            if(!used[tx][ty] && ma[tx][ty] != '#') {
                ok = true;
                used[tx][ty] = true;
                dfs(tx, ty, d + 1);
                used[tx][ty] = false;
            }
        }
    }

    if(!ok && cmp(nans, bans)) bans = nans;
    return ;
}

int main() {
    while(~scanf("%d%d", &R, &C) && R) {
        bans.clear();
        for(int i = 1; i <= R; ++i) scanf("%s", ma[i] + 1);
        for(int i = 1; i <= R; ++i) {
            for(int j = 1; j <= C; ++j) {
                if(ma[i][j] != '#') {
                    used[i][j] = true;
                    dfs(i, j, 0);
                    used[i][j] = false;
                }
            }
        }
        printf("%s\n", bans.c_str());
    }
    return 0;
}
