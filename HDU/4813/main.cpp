#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int t, N, M;
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &N, &M);
        string s;
        cin >> s;
        int cnt(0);
        for(int i = 0; i < s.size(); ++i) {
            if(cnt != M) printf("%c", s[i]);
            cnt++;
            if(cnt == M) {
                printf("\n");
                cnt = 0;
            }
        }
    }
    return 0;
}