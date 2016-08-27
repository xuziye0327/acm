#include <cstdio>
#include <set>

using namespace std;

int main() {
    multiset<int> m;
    int n;
    scanf("%d", &n);
    while(n--) {
        int x, cmd;
        scanf("%d", &cmd);
        if(cmd == 1) {
            scanf("%d", &x);
            m.insert(x);
        } else if(cmd == 2) {
            if(!m.empty())
                m.erase(m.begin());
        } else {
            if(m.empty()) printf("0\n");
            else printf("%d\n", *m.rbegin());
        }
    }
    return 0;
}