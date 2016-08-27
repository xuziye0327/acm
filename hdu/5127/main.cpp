#include <bits/stdc++.h>

using namespace std;

struct num {
    long long first, second;
    bool exit = false;
};

vector<num> v;

int main() {
    int n;
    while(~scanf("%d", &n) && n) {
        v.clear();
        while(n--) {
            long long x, y;
            int cmd;
            scanf("%d", &cmd);
            if(cmd == 1) {
                scanf("%I64d%I64d", &x, &y);
                num t;
                t.first = x;
                t.second = y;
                t.exit = true;
                v.push_back(t);
            } else if(cmd == 0) {
                bool be = true;
                long long ma;
                scanf("%I64d%I64d", &x, &y);
                for(vector<num> :: iterator it = v.begin(); it != v.end(); it++) {
                    if(be && (*it).exit) {
                        be = false;
                        ma = (*it).first * x + (*it).second * y;
                    } else if((*it).exit) {
                        ma = max(ma, (*it).first * x + (*it).second * y);
                    }
                }
                printf("%I64d\n", ma);
            } else if(cmd == -1) {
                scanf("%I64d%I64d", &x, &y);
                for(vector<num> :: iterator it = v.begin(); it != v.end(); it++) {
                    if(((*it).first == x) && ((*it).second == y) && ((*it).exit)) {
                        (*it).exit = false;
                        break;
                    }
                }
            }
        }
    }
    return 0;
}