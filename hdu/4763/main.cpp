#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

typedef unsigned long long ull;

const ull base = 27LL;
const int maxn = 1E6 + 7;

ull hasemap[maxn];
ull pbase[maxn] = {1LL};
char str[maxn];

int main() {
    for(int i = 1; i < maxn; ++i) pbase[i] = pbase[i - 1] * base;
    int t;
    scanf("%d", &t);
    while(t--){
        int res(0);
        scanf("%s", str);
        int len = strlen(str);
        hasemap[len] = 0;
        for(int i = len - 1; i >= 0; --i) hasemap[i] = hasemap[i + 1] * base + str[i];
        int slen = len / 3;
        while(slen > 0) {
            ull temp1(0LL), temp2(0LL), temp3(0LL);
            temp1 = hasemap[0] - hasemap[slen] * pbase[slen];
            temp2 = hasemap[len - slen] - hasemap[len] * pbase[slen];
//            printf("%I64d\n", temp1);
//            printf("%I64d\n", temp2);
            if(temp1 == temp2) {
                for(int i = slen; i < len - slen; ++i) {
                    temp3 = hasemap[i] - hasemap[i + slen] * pbase[slen];
                    if(temp1 == temp3) { res = slen; break; }
                }
            }
            if(res) break;
            --slen;
        }
        printf("%d\n", slen);
    }
    return 0;
}