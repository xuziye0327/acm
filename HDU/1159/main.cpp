#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxn = 1000 + 7;

int d[maxn][maxn];
string s1, s2;

void init() {
    memset(d, 0, sizeof(d));
}

int main() {
    while(cin >> s1 >> s2) {
        init();
        for (int i = s1.size() - 1; i >= 0; --i) {
            for(int j = s2.size() - 1; j >= 0; --j) {
                if(s1[i] == s2[j]) d[i][j] = max(d[i][j], d[i + 1][j + 1] + 1);
                else d[i][j] = max(d[i][j], max(d[i + 1][j], d[i][j + 1]));
            }
        }
        printf("%d\n", d[0][0]);
    }
    return 0;
}