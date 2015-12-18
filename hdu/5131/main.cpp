#include <bits/stdc++.h>

using namespace std;

const int maxn = 200 + 7;

struct pe{
    string name;
    int kill;
    bool operator < (const pe &k) const {
        return kill == k.kill ? name < k.name : kill > k.kill;
    }
}P[maxn];

int main() {
    int n, t;
    while(~scanf("%d", &n) && n) {
        for(int i = 0; i < n; i++) {
            cin >> P[i].name >> P[i].kill;
        }
        sort(P, P + n);
        for(int i = 0; i < n; i++) {
            cout << P[i].name << " " << P[i].kill << endl;
        }
        cin >> t;
        while(t--) {
            int fi(0), se(0);
            string name;
            cin >> name;
            for(int i = 0; i < n; i++) {
                if(name == P[i].name) { fi = i; break; }
            }
            for(int i = fi - 1; i >= 0; i--) {
                if(P[i].kill == P[fi].kill) { se++; }
            }
            if(se >= 1)  cout << fi + 1 - se << " " << se + 1 << endl;
            else cout << fi + 1 << endl;
        }
    }
    return 0;
}