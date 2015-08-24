#include <iostream>
#include <cstdio>
#include <set>

using namespace std;

struct monk {
    int id, gra;
    bool operator < (const monk &k) const {
        return gra < k.gra;
    }
    monk(int x, int y) : id(x), gra(y) { }
};

set<monk> s;

int main() {
    int n, k, g;
    while(~scanf("%d", &n) && n) {
        s.clear();
        for(int i = 0; i < n; i++) {
            scanf("%d%d", &k, &g);
            monk t(k, g);
            printf("%d ", k);
            if(i == 0) { printf("1"); }
            else {
                set<monk> :: iterator it = s.lower_bound(t);
                if(it == s.end()) printf("%d", (--it) -> id);
                else if(it == s.begin()) { printf("%d", it -> id); }
                else {
                        monk m1(it -> id, it -> gra);
                        --it;
                        monk m2(it -> id, it -> gra);
                        printf("%d", g - m2.gra <= m1.gra - g ? m2.id : m1.id);
                }
            }
            s.insert(t);
            printf("\n");
        }
    }
    return 0;
}