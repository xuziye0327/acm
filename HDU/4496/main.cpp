#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

const int maxn = 10000 + 7;

typedef pair<int, int> P;

int N, M;
int fa[maxn];

void init() {
    for(int i = 0; i < maxn; ++i) fa[i] = i;
}

int fin(int x) {
    return fa[x] == x ? x : fa[x] = fin(fa[x]);
}

int main() {
    while(~scanf("%d%d", &N, &M)) {
        init();
        int t(N);
        stack<P> st;
        stack<int> ans;
        ans.push(t);
        for(int i = 0; i < M; ++i) {
            int u, v;
            scanf("%d%d", &u, &v);
            st.push(make_pair(u, v));
        }
        while(!st.empty()) {
            P p = st.top(); st.pop();
            if(fin(p.first) != fin(p.second)) --t;
            fa[fin(p.first)] = fa[fin(p.second)];
            if(!st.empty()) ans.push(t);
        }
        while(!ans.empty()) {
            printf("%d\n", ans.top());
            ans.pop();
        }
    }
    return 0;
}