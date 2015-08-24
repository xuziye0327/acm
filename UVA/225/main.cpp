/*
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>

#define X p.first
#define Y p.second

using namespace std;

typedef pair<int, int> P;

const int maxn = 50 + 7;
const int dx[] = {0, 0, 0, -1, 1};
const int dy[] = {0, 1, -1, 0, 0};
const char dir[] = {' ', 'n', 's', 'w', 'e'};

int n, k;
P dis[maxn];
char path[maxn];
set<P> used;
vector<string> ans;

void init() {
    ans.clear();
}

void dfs(int x, int y, int cnt, int d) {
    if(cnt > n) {
        path[cnt - 1] = '\0';
        if(x == 0 && y == 0) ans.push_back(path);
        return ;
    }
    P p;
    if(d == 1 || d == 2) {
        for(int i = 3; i <= 4; ++i) {
            bool ok = true;
            X = x + dx[i] * cnt; Y = y;
            if(used.count(make_pair(X, Y))) continue;
            used.insert(make_pair(X, Y));
            for(int j = 0; j < k; ++j) {
                if(dis[j].second == Y){
                    if(dx[i] > 0 && dis[j].first > x && dis[j].first <= X) { ok = false; break; }
                    if(dx[i] < 0 && dis[j].first < x && dis[j].first >= X) { ok = false; break; }
                }
            }
            if(ok) { path[cnt - 1] = dir[i]; dfs(X, Y, cnt + 1, i); }
            used.erase(make_pair(X, Y));
        }
    } else if(d == 3 || d == 4) {
        for(int i = 1; i <= 2; ++i) {
            bool ok = true;
            X = x; Y = y + dy[i] * cnt;
            if(used.count(make_pair(X, Y))) continue;
            used.insert(make_pair(X, Y));
            for(int j = 0; j < k; ++j) {
                if(dis[j].first == X){
                    if(dy[i] > 0 && dis[j].second > y && dis[j].second <= Y) { ok = false; break; }
                    if(dy[i] < 0 && dis[j].second < y && dis[j].second >= Y) { ok = false; break; }
                }
            }
            if(ok) { path[cnt - 1] = dir[i]; dfs(X, Y, cnt + 1, i); }
            used.erase(make_pair(X, Y));
        }
    }
}

int main() {
    int T;
    scanf("%d", &T);
    for(int Case = 0; Case < T; ++Case) {
        init();
        scanf("%d%d", &n, &k);
        for(int i = 0; i < k; ++i) scanf("%d%d", &dis[i].first, &dis[i].second);
        for(int i = 1; i <= 4; ++i) {
            used.clear();
            bool ok = true;
            for(int j = 0; j < k; ++j) if(dis[j].first == dx[i] && dis[j].second == dy[i]) {
                    ok = false; break;
                }
            if(ok) { used.insert(make_pair(dx[i], dy[i])); path[0] = dir[i]; dfs(dx[i], dy[i], 2, i); }
        }
        sort(ans.begin(), ans.end());
        for(int i = 0; i < ans.size(); ++i) cout << ans[i] << endl;
        printf("Found %d golygon(s).\n\n", ans.size());
    }
    return 0;
}
 */
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>

#define X p.first
#define Y p.second

using namespace std;

typedef pair<int, int> P;

const int maxn = 50 + 7;
const int dx[] = {0, 0, 0, -1, 1};
const int dy[] = {0, 1, -1, 0, 0};
const char dir[] = {' ', 'n', 's', 'w', 'e'};

int n, k;
P dis[maxn];
char path[maxn];
bool used[2000][2000];
vector<string> ans;

void init() {
    memset(used, false, sizeof(used));
    ans.clear();
}

void dfs(int x, int y, int cnt, int d) {
    if(cnt > n) {
        path[cnt - 1] = '\0';
        if(x == 0 && y == 0) ans.push_back(path);
        return ;
    }
    P p;
    if(d == 1 || d == 2) {
        for(int i = 3; i <= 4; ++i) {
            bool ok = true;
            X = x + dx[i] * cnt; Y = y;
            if(used[X + 500][Y + 500]) continue;
            used[X + 500][Y + 500] = true;
            for(int j = 0; j < k; ++j) {
                if(dis[j].second == Y){
                    if(dx[i] > 0 && dis[j].first > x && dis[j].first <= X) { ok = false; break; }
                    if(dx[i] < 0 && dis[j].first < x && dis[j].first >= X) { ok = false; break; }
                }
            }
            if(ok) { path[cnt - 1] = dir[i]; dfs(X, Y, cnt + 1, i); }
            used[X + 500][Y + 500] = false;
        }
    } else if(d == 3 || d == 4) {
        for(int i = 1; i <= 2; ++i) {
            bool ok = true;
            X = x; Y = y + dy[i] * cnt;
            if(used[X + 500][Y + 500]) continue;
            used[X + 500][Y + 500] = true;
            for(int j = 0; j < k; ++j) {
                if(dis[j].first == X){
                    if(dy[i] > 0 && dis[j].second > y && dis[j].second <= Y) { ok = false; break; }
                    if(dy[i] < 0 && dis[j].second < y && dis[j].second >= Y) { ok = false; break; }
                }
            }
            if(ok) { path[cnt - 1] = dir[i]; dfs(X, Y, cnt + 1, i); }
            used[X + 500][Y + 500] = false;
        }
    }
}

int main() {
    int T;
    scanf("%d", &T);
    for(int Case = 0; Case < T; ++Case) {
        init();
        scanf("%d%d", &n, &k);
        for(int i = 0; i < k; ++i) scanf("%d%d", &dis[i].first, &dis[i].second);
        for(int i = 1; i <= 4; ++i) {
            bool ok = true;
            for(int j = 0; j < k; ++j) if(dis[j].first == dx[i] && dis[j].second == dy[i]) {
                    ok = false; break;
                }
            if(ok) { used[dx[i] + 500][dy[i] + 500] = true; path[0] = dir[i]; dfs(dx[i], dy[i], 2, i); used[dx[i] + 500][dy[i] + 500] = false; }
        }
        sort(ans.begin(), ans.end());
        for(int i = 0; i < ans.size(); ++i) cout << ans[i] << endl;
        printf("Found %d golygon(s).\n\n", ans.size());
    }
    return 0;
}