#include <iostream>
#include <cstring>
#include <cstdio>
#include <stack>
#include <vector>

#define clr(a, x) memset(a, x, sizeof(a))

using namespace std;

const int maxn = 13 + 7;

int n, m;
int a[1 << maxn];
int pos[1 << maxn];
vector<int> ans;
stack<int> _stack[maxn];

int main() {
    while(~scanf("%d", &n) && n) {
        m = 1 << n;
        ans.clear();
        clr(pos, 0);
        for(int i = 0; i < maxn; ++i) while(!_stack[i].empty()) _stack[i].pop();
        for(int i = 0; i < m; ++i) scanf("%d", &a[i]);
        for(int i = m - 1; i >= 0; --i) {
            _stack[0].push(a[i]);
            pos[a[i]] = 0;
        }
        for(int k = 1; k <= m; ++k) {
            int at = pos[k];
            while(true) {
                if(_stack[at].top() == k) {
                    _stack[at].pop();
                    if(at == 0) {
                        at = 1;
                        ans.push_back(k);
                    }
                    for(int i = 0; i < (n - at) * 2 + 1; ++i) {
                        ans.push_back(k);
                    }
                    break;
                } else {
                    ans.push_back(_stack[at].top());
                    if(at != 0)
                        ans.push_back(_stack[at].top());
                    _stack[at + 1].push(_stack[at].top());
                    pos[_stack[at].top()] = at + 1;
                    _stack[at].pop();
                }
            }
        }
        for(int i = 0; i < ans.size(); ++i) {
            if(i) printf(" ");
            printf("%d", ans[i]);
        }
        printf("\n");
    }
    return 0;
}