#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include <set>
#include <vector>
using namespace std;

const int maxn = 10 + 7;
const char table[] = {'p', 'q', 'r', 'u', 'v', 'w', 'x', 'y', 'z', '\0'};

int a[maxn];

int main()
{
    int t;
    scanf("%d", &t);
    while(t--) {
        for(int i = 0; i < 10; ++i) scanf("%d", &a[i]);
        bool beg = true;
        for(int i = 0; i < 10; i++) {
            if(beg && !a[i]) continue;
            if(beg) {
                    beg = false;
                    if(i != 9) {
                        if(a[i] != 1 && a[i] != -1)
                            printf("%d%c", a[i], table[i]);
                        else {
                            if(a[i] < 0) printf("-%c", table[i]);
                            else printf("%c", table[i]);
                        }
                    } if(i == 9) {
                        printf("%d", a[i]);
                    }
            }
            else {
                if(!a[i]) continue;
                else {
                    if(i != 9) {
                        if(a[i] != 1 && a[i] != -1) {
                            if(a[i] > 0) printf("+%d%c", a[i], table[i]);
                            else printf("%d%c", a[i], table[i]);
                        } else {
                            if(a[i] > 0) printf("+%c", table[i]);
                            else printf("-%c", table[i]);
                            if(i == 9) printf("1");
                        }
                    } else {
                        if(a[i] != 1 && a[i] != -1) {
                            if(a[i] > 0) printf("+%d", a[i], table[i]);
                            else printf("%d", a[i], table[i]);
                        } else {
                            if(a[i] > 0) printf("+1", table[i]);
                            else printf("-1", table[i]);
                        }
                    }
                }
            }
        }
        if(beg) printf("0");
        printf("\n");
    }
    return 0;
}