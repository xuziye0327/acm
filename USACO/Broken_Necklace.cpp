/*
ID: xuziye01
PROG: beads
LANG: C++11
*/

#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    freopen("beads.in", "r", stdin);
    freopen("beads.out", "w", stdout);
    int n, ans(0);
    string str;
    cin >> n;
    cin >> str;
    for (int i = 0; i < n; ++i) {
        int cnt = 1;
        char ch = str[i];
        bool chang = false;
        for (int j = (i + 1) % n; j != i; j = (j + 1) % n) {
            if (str[j] == 'w') { ++cnt; continue; }
            else if (str[j] == 'b') {
                if (ch == 'w') ch = 'b';
                if (ch == 'b') {
                    ++cnt;
                } else {
                    if (!chang) {
                        ++cnt;
                        ch = str[j];
                        chang = true;
                    } else {
                        break;
                    }
                }
            } else {
                if (ch == 'w') ch = 'r';
                if (ch == 'r') {
                    ++cnt;
                } else {
                    if (!chang) {
                        ++cnt;
                        ch = str[j];
                        chang = true;
                    } else {
                        break;
                    }
                }
            }
        }
        ans = max(ans, cnt);
    }
    cout << ans << endl;
    return 0;
}
