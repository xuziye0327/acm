#include <iostream>
#include <cstring>
#include <map>
#include <cstdio>

using namespace std;

typedef unsigned long long ull;

const int maxn = 100000 + 7;
const unsigned long long base = 233LL;

int M, L;
char str[maxn];
ull pbase[maxn] = {1ULL};
ull hashmap[maxn];
map<unsigned long long, int> ma;

int main() {
    int i, j, ans, len;
    unsigned long long temp;
    for(i = 1; i <= maxn; ++i) pbase[i] = pbase[i - 1] * base;
    while(~scanf("%d%d", &M, &L)) {
        scanf("%s", str);
        len = strlen(str);
        hashmap[len] = 0;
        for(i = len - 1; i >= 0; --i) hashmap[i] = hashmap[i + 1] * base + str[i];
        ans = 0;
        for(i = 0; i + M * L <= len && i < L; ++i) {
            ma.clear();
            for(j = i; j < i + M * L; j += L) {
                temp = hashmap[j] - hashmap[j + L] * pbase[L];
                ma[temp]++;
            }
            if(ma.size() == M) ++ans;
            for(j = i + M * L; j + L <= len; j += L) {
                temp = hashmap[j - M * L] - hashmap[j - M * L + L] * pbase[L];
                ma[temp]--;
                if(ma[temp] == 0) ma.erase(temp);
                temp = hashmap[j] - hashmap[j + L] * pbase[L];
                ma[temp]++;
                if(ma.size() == M) ++ans;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}