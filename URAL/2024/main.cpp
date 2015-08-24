#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

const int maxn = 1E5 + 7;

int k;
int C[26 + 7][26 + 7];
int num[26 + 7];
char str[maxn];

int main() {
    for(int i=0; i<32; i++) {
        C[i][i]=1;
        C[i][0]=1;
    }
    for(int i=1; i<32; i++) {
        for(int j=1; j<i; j++) {
            C[i][j]=C[i-1][j]+C[i-1][j-1];
        }
    }
    scanf("%s", str);
    scanf("%d", &k);
    for(int i = 0; str[i]; ++i) {
        ++num[str[i] - 'a'];
    }
    sort(num, num + 26);
    int ans1(0), ans2(0);
    for(int i = 25; i > 25 - k; --i) {
        ans1 += num[i];
    }
    if(num[26 - k] == 0) ans2 = 1;
    else {
        int cn(0), cm(0);
        for(int i = 25; i >= 0; --i) if(num[i] == num[26 - k]) ++cn;
        for(int i = 25; i > 25 - k; --i) if(num[i] == num[26 - k]) ++cm;
        ans2 = C[cn][cm];
    }
    printf("%d %d", ans1, ans2);
    return 0;
}
