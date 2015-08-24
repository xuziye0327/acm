#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

const int maxn = 10 + 7;

char c[maxn];
char chess[maxn][maxn];
bool ma[maxn][maxn];

int main() {
    int n, x, y, sx, sy;
    while(~scanf("%d%d%d", &n, &sx, &sy) && n) {
        memset(ma, 0, sizeof(ma));
        memset(chess, 0, sizeof(chess));
        for(int i = 0; i < n; ++i) {
            scanf("%s %d%d", c, &x, &y);
            chess[x][y] = c[0];
        }
        for(int i = 0; i < maxn; ++i) {
            for(int j = 0; j < maxn; ++j) {
                if(chess[i][j] == 'G') {
                    for(int k = i - 1; k >= 0; --k) {
                        ma[k][j] = true;
                        if(chess[k][j]) break;
                    }
                    for(int k = i + 1; k < maxn; ++k) {
                        ma[k][j] = true;
                        if(chess[k][j]) break;
                    }
                } else if(chess[i][j] == 'R') {
                    for(int k = i - 1; k >= 0; --k) {
                        ma[k][j] = true;
                        if(chess[k][j]) break;
                    }
                    for(int k = i + 1; k < maxn; ++k) {
                        ma[k][j] = true;
                        if(chess[k][j]) break;
                    }
                    for(int k = j - 1; k >= 0; --k) {
                        ma[i][k] = true;
                        if(chess[i][k]) break;
                    }
                    for(int k = j + 1; k < maxn; ++k) {
                        ma[i][k] = true;
                        if(chess[i][k]) break;
                    }
                } else if(chess[i][j] == 'H') {
                    if(!chess[i][j + 1]) {
                        ma[i + 1][j + 2] = ma[i - 1][j + 2] = true;
                    }
                    if(!chess[i][j - 1] && j - 2 >= 0) {
                        ma[i + 1][j - 2] = ma[i - 1][j - 2] = true;
                    }
                    if(!chess[i - 1][j] && i - 2 >= 0) {
                        ma[i - 2][j - 1] = ma[i - 2][j + 1] = true;
                    }
                    if(!chess[i + 1][j]) {
                        ma[i + 2][j - 1] = ma[i + 2][j + 1] = true;
                    }
                } else if(chess[i][j] == 'C') {
                    bool ok;
                    ok = false;
                    for(int k = i - 1; k >= 0; --k) {
                        if(!ok && chess[k][j]) { ok = true; continue; }
                        if(ok) {
                            ma[k][j] = true;
                            if(chess[k][j]) break;
                        }
                    }
                    ok = false;
                    for(int k = i + 1; k < maxn; ++k) {
                        if(!ok && chess[k][j]) { ok = true; continue; }
                        if(ok) {
                            ma[k][j] = true;
                            if(chess[k][j]) break;
                        }
                    }
                    ok = false;
                    for(int k = j - 1; k >= 0; --k) {
                        if(!ok && chess[i][k]) { ok = true; continue; }
                        if(ok) {
                            ma[i][k] = true;
                            if(chess[i][k]) break;
                        }
                    }
                    ok = false;
                    for(int k = j + 1; k < maxn; ++k) {
                        if(!ok && chess[i][k]) { ok = true; continue; }
                        if(ok) {
                            ma[i][k] = true;
                            if(chess[i][k]) break;
                        }
                    }
                }
            }
        }
        bool yes = false;
        if(sx == 1 && sy == 4) { if(ma[sx][sy + 1] && ma[sx + 1][sy]) yes = true; }
        else if(sx == 1 && sy == 5) { if(ma[sx][sy - 1] && ma[sx + 1][sy] && ma[sx][sy + 1]) yes = true; }
        else if(sx == 1 && sy == 6) { if(ma[sx][sy - 1] && ma[sx + 1][sy]) yes = true; }
        else if(sx == 2 && sy == 4) { if(ma[sx][sy + 1] && ma[sx + 1][sy] && ma[sx - 1][sy]) yes = true; }
        else if(sx == 2 && sy == 5) { if(ma[sx][sy - 1] && ma[sx + 1][sy] && ma[sx - 1][sy] || !ma[sx][sy + 1]) yes = true; }
        else if(sx == 2 && sy == 6) { if(ma[sx][sy - 1] && ma[sx + 1][sy] && ma[sx - 1][sy]) yes = true; }
        else if(sx == 3 && sy == 4) { if(ma[sx][sy + 1] && ma[sx - 1][sy]) yes = true; }
        else if(sx == 3 && sy == 5) { if(ma[sx][sy - 1] && ma[sx - 1][sy] && ma[sx][sy + 1]) yes = true; }
        else if(sx == 3 && sy == 6) { if(ma[sx][sy - 1] && ma[sx - 1][sy]) yes = true; }
        printf("%s\n", yes ? "YES" : "NO");
    }
    return 0;
}