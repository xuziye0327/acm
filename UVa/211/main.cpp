#include <iostream>
#include <cstdio>
#include <map>
#include <cstring>

using namespace std;

typedef pair<int, int> P;

const int maxn = 7 + 7;
const P tBone[maxn * 4] = {{}, {0, 0}, {0, 1}, {0, 2}, {0, 3}, {0, 4}, {0, 5}, {0, 6},
                          {1, 1}, {1, 2}, {1, 3}, {1, 4}, {1, 5}, {1, 6}, {2, 2}, {2, 3}, {2, 4},
                          {2, 5}, {2, 6}, {3, 3}, {3, 4}, {3, 5}, {3, 6}, {4, 4}, {4, 5}, {4, 6},
                          {5, 5}, {5, 6}, {6, 6}};

int cnt;
int ma[maxn][maxn];
int ans[maxn][maxn];
bool used[maxn * 4];
map<P, int> Bone;

void init() {
    cnt = 0;
    memset(ans, -1, sizeof(ans));
    memset(used, false, sizeof(used));
}

void dfs(int x, int y, int num) {
    if(num == 28) {
        if(cnt++) /*printf("\n")*/;
        for(int i = 1; i <= 7; ++i) {
            for(int j = 1; j <= 8; ++j)
                printf("%4d", ans[i][j]);
            printf("\n");
        }
        printf("\n");
        return ;
    }
    if(x > 7) { x = 1; ++y; }
    if(ans[x][y] != -1) {
        dfs(x + 1, y, num);
        return ;
    }
    P p;
    if(x + 1 <= 7 && ans[x + 1][y] == -1) {
        p = make_pair(ma[x][y], ma[x + 1][y]);
        if(!used[Bone[p]] && Bone[p]) {
            used[Bone[p]] = true;
            ans[x][y] = ans[x + 1][y] = Bone[p];
            dfs(x + 1, y, num + 1);
            used[Bone[p]] = false;
            ans[x][y] = ans[x + 1][y] = -1;
        }
    }
    if(y + 1 <= 8 && ans[x][y + 1] == -1) {
        p = make_pair(ma[x][y], ma[x][y + 1]);
        if(!used[Bone[p]] && Bone[p]) {
            used[Bone[p]] = true;
            ans[x][y] = ans[x][y + 1] = Bone[p];
            dfs(x + 1, y, num + 1);
            used[Bone[p]] = false;
            ans[x][y] = ans[x][y + 1] = -1;
        }
    }
}

int main() {
    for(int i = 1; i <= 28; ++i) {
        P p;
        p.first = tBone[i].first;
        p.second = tBone[i].second;
        Bone[p] = i;
        swap(p.first, p.second);
        Bone[p] = i;
    }
    int Kase(0);
    while(~scanf("%d", &ma[1][1])) {
        init();
        if(Kase) printf("\n\n\n");
        for(int i = 1; i <= 7; ++i)
            for(int j = 1; j <= 8; ++j) if(!(i == 1 && j == 1)) scanf("%d", &ma[i][j]);
        printf("Layout #%d:\n\n", ++Kase);
        for(int i = 1; i <= 7; ++i) {
            for(int j = 1; j <= 8; ++j)
                printf("%4d", ma[i][j]);
            printf("\n");
        }
        printf("\nMaps resulting from layout #%d are:\n\n", Kase);
        dfs(1, 1, 0);
        printf("There are %d solution(s) for layout #%d.\n", cnt, Kase);
    }
    return 0;
}