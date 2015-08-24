#include <iostream>
#include <string>

using namespace std;

const int maxn = 12 + 7;

int n;
string ans[maxn][1 << 13];

int main() {
    ans[1][0] = {"0"};
    ans[1][1] = {"1"};
    ans[2][0] = {"00"};
    ans[2][1] = {"10"};
    ans[2][2] = {"01"};
    ans[2][3] = {"11"};
    for(int i = 3; i <= 12; ++i) {
        int cnt(0);
        int l = i / 2, r = i - l;
        if(l & 1 && r & 1) { --l; ++r; }
        for(int j = 0; j < (1 << i); ++j) {
            ans[i][j] = ans[l][j % (1 << l)] + ans[r][(j + cnt) % (1 << r)];
            if(j % (1 << r) == (1 << r) - 1) ++cnt;
        }
    }
    bool bla(false);
    while(cin >> n && n) {
        if(bla) cout << endl;
        bla = true;
        for(int i = 0; i < (1 << n); ++i) cout << ans[n][i] << endl;
    }
    return 0;
}