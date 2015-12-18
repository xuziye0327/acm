#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>

using namespace std;

const int maxn = 52 + 7;

char Eve[maxn][7], Adam[maxn][7];
int n;
int from[maxn];
bool used[maxn];
vector<int> G[maxn];

int cardValue(char c) {
    if(c == 'A') return 13;
    else if(c == 'K') return 12;
    else if(c == 'Q') return 11;
    else if(c == 'J') return 10;
    else if(c == 'T') return 9;
    else return c - '1';
}

int cardId(char *card) {
    int id(cardValue(*card));
    if(*(card + 1) == 'C') id += 0;
    else if(*(card + 1) == 'D') id += 13;
    else if(*(card + 1) == 'S') id += 26;
    else id += 39;
    return id;
}

bool match(int x) {
    for(int i = 0; i < G[x].size(); ++i) {
        int t = G[x][i];
        if(!used[t]) {
            used[t] = true;
            if(from[t] == -1 || match(from[t])) {
                from[t] = x;
                return true;
            }
        }
    }
    return false;
}

int hunary() {
    int res(0);
    memset(from, -1, sizeof(from));
    for(int i = 1; i <= 52; ++i) {
        memset(used, false, sizeof(used));
        if(match(i)) ++res;
    }
    return res;
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        for(int i = 0; i < maxn; ++i) G[i].clear();
        scanf("%d", &n);
        for(int i = 0; i < n; ++i) scanf("%s", Adam[i]);
        for(int i = 0; i < n; ++i) scanf("%s", Eve[i]);
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                if(cardValue(Eve[i][0]) > cardValue(Adam[j][0])) G[cardId(Eve[i])].push_back(cardId(Adam[j]));
                else if(cardValue(Eve[i][0]) == cardValue(Adam[j][0])) {
                    if(cardId(Eve[i]) > cardId(Adam[j])) G[cardId(Eve[i])].push_back(cardId(Adam[j]));
                }
            }
        }
        printf("%d\n", hunary());
    }
    return 0;
}