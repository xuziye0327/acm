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

const int maxn = 40 + 7;

int N, M;
bool Graph[maxn][maxn];
int Match[maxn];
bool InQueue[maxn], InPath[maxn], InBlossom[maxn];
int Head, Tail;
int Queue[maxn];
int Start, Finish;
int NewBase;
int Father[maxn], Base[maxn];
int Count;
vector<P> ma;
vector<int> ans;

void push(int u) {
    Queue[Tail] = u;
    Tail++;
    InQueue[u] = true;
}

int Pop() {
    int res = Queue[Head];
    ++Head;
    return res;
}

int FindCommonAncestor(int u, int v) {
    CLR(InPath, false);
    while(true) {
        u = Base[u];
        InPath[u] = true;
        if(u == Start) break;
        u = Father[Match[u]];
    }
    while(true) {
        v = Base[v];
        if(InPath[v]) break;
        v = Father[Match[v]];
    }
    return v;
}

void ResetTrace(int u) {
    int v;
    while(Base[u] != NewBase) {
        v = Match[u];
        InBlossom[Base[u]] = InBlossom[Base[v]] = true;
        u = Father[v];
        if(Base[u] != NewBase) Father[u] = v;
    }
}

void BloosomContract(int u, int v) {
    NewBase = FindCommonAncestor(u, v);
    CLR(InBlossom, false);
    ResetTrace(u);
    ResetTrace(v);
    if(Base[u] != NewBase) Father[u] = v;
    if(Base[v] != NewBase) Father[v] = u;
    for(int tu = 1; tu <= N; ++tu)
        if(InBlossom[Base[tu]]) {
            Base[tu] = NewBase;
            if(!InQueue[tu]) push(tu);
        }
}

void FindAugmentingPath() {
    CLR(InQueue, false);
    CLR(Father, 0);
    for(int i = 1; i <= N; ++i)
        Base[i] = i;
    Head = Tail = 1;
    push(Start);
    Finish = 0;
    while(Head < Tail) {
        int u = Pop();
        for(int v = 1; v <= N; ++v)
        if(Graph[u][v] && (Base[u] != Base[v]) && (Match[u] != v)) {
            if(v == Start || (Match[v] > 0 && Father[Match[v]] > 0)) BloosomContract(u, v);
            else if(Father[v] == 0) {
                Father[v] = u;
                if(Match[v] > 0) push(Match[v]);
                else {
                    Finish = v;
                    return ;
                }
            }
        }
    }
}

void AugmentPath() {
    int u, v, w;
    u = Finish;
    while(u > 0) {
        v = Father[u];
        w = Match[v];
        Match[v] = u;
        Match[u] = v;
        u = w;
    }
}

void Edmonds() {
    CLR(Match, 0);
    for(int u = 1; u <= N; ++u) {
        if(Match[u] == 0) {
            Start = u;
            FindAugmentingPath();
            if(Finish > 0) AugmentPath();
        }
    }
}

void PrintMatch() {
    Count = 0;
    for(int u = 1; u <= N; ++u)
        if(Match[u] > 0) Count++;
    printf("%d\n", Count);
    for(int u = 1; u <= N; ++u) {
        if(u < Match[u]) printf("%d %d\n", u, Match[u]);
    }
}

int CountMatch() {
    Edmonds();
    Count = 0;
    for(int u = 1; u <= N; ++u)
        if(Match[u] > 0) Count++;
    return Count / 2;
}

int main() {
    while(~scanf("%d%d", &N, &M)) {
        ma.clear();
        ans.clear();
        CLR(Graph, false);
        for(int i = 0; i < M; ++i) {
            int u, v;
            scanf("%d%d", &u, &v);
            ma.push_back(MP(u, v));
            Graph[u][v] = Graph[v][u] = true;
        }

        int maxx = CountMatch();

        for(int i = 0; i < M; ++i) {
            int x = ma[i].first, y = ma[i].second;
            CLR(Graph, false);
            for(int j = 0; j < M; ++j) {
                if(j == i) continue;
                int xx = ma[j].first, yy = ma[j].second;
                if(xx == x || xx == y || yy == x || yy == y) continue;
                Graph[xx][yy] = Graph[yy][xx] = true;
            }
            if(CountMatch() != maxx - 1) {
                ans.push_back(i + 1);
            }
        }

        printf("%d\n", ans.size());
        for(int i = 0; i < ans.size(); ++i) {
            if(i) printf(" ");
            printf("%d", ans[i]);
        }
        printf("\n");
    }
    return 0;
}