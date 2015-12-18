#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <set>
#include <queue>

using namespace std;

typedef pair<int, int> P;

const int maxn = 100 + 7;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

struct Node {
    int x, y, sta, step;
    set<P> s;
    Node (int x_, int y_, int sta_, int step_) : x(x_), y(y_), sta(sta_), step(step_) { s.clear(); }
};

int N, M, res;
int d[maxn][maxn][maxn];
char ma[maxn][maxn];

void init() {
    memset(d, -1, sizeof(d));
}

void bfs(int x, int y) {
    init();
    Node node(x, y, 0, 0);
    queue<Node> que;
    que.push(node);
    d[0][x][y] = 0;

    while(!que.empty()) {
        node = que.front(); que.pop();
        x = node.x; y = node.y;
        for(int i = 0; i < 4; ++i) {
            int tx = x + dx[i], ty = y + dy[i];
            if(tx >= 1 && tx <= N && ty >= 1 && ty <= N && ma[tx][ty] != '#') {
                Node newNode = node;
                newNode.x = tx; newNode.y = ty;
                if(ma[tx][ty] == '.') {
                    newNode.step = node.step + 1;
                }
                if(ma[tx][ty] == 'S') {
                    if(newNode.s.count(make_pair(tx, ty))) {
                        newNode.step = node.step + 1;
                    } else {
                        newNode.step = node.step + 2;
                        newNode.s.insert(make_pair(tx, ty));
                    }
                }
                if(ma[tx][ty] - '0' >= 1 && ma[tx][ty] - '0' <= 9) {
                    int key = ma[tx][ty] - '0';
                    if(node.sta == key - 1) {
                        newNode.sta = key;
                    }
                    newNode.step = node.step + 1;
                }
                if(ma[tx][ty] == 'T' || ma[tx][ty] == 'K') {
                    newNode.step = node.step + 1;
                }
                if(d[newNode.sta][tx][ty] == -1 || d[newNode.sta][tx][ty] > newNode.step) {
                    d[newNode.sta][tx][ty] = newNode.step;
                    que.push(newNode);
                }
            }
        }
    }

    for(int i = 1; i <= N; ++i)
        for(int j = 1; j <= N; ++j)
            if(ma[i][j] == 'T') {
                res = d[M][i][j];
                return ;
            }
}

int main() {
    while(~scanf("%d%d", &N, &M) && N) {
        for(int i = 1; i <= N; ++i) scanf("%s", ma[i] + 1);
        for(int i = 1; i <= N; ++i)
            for(int j = 1; j <= N; ++j) if(ma[i][j] == 'K') bfs(i, j);
        if(res == -1) printf("impossible\n");
        else printf("%d\n", res);
    }
    return 0;
}