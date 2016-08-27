#include<iostream>
#include<cstdio>
#include<cstring>
#include <vector>
using namespace std;

const int maxn = 100 + 7;

int a[maxn];
bool esit[maxn];

int main()
{
    int t;
    scanf("%d", &t);
    int N, K;
    vector<int> s;
    while(t--) {
        memset(esit, 0, sizeof(esit));
        s.clear();
        bool ok = true;
        scanf("%d%d", &N, &K);
        for(int i = 1; i <= N;i++) {
            scanf("%d", &a[i]);
            if(a[i] > N) ok = false;
            if(ok) {
                if(esit[a[i]]) s.push_back(a[i]);
                else esit[a[i]] = true;
            }
        }
        for(int i = 0; i < s.size(); i++) {
            while(s[i] <= N) {
                s[i] += K;
                if(!esit[s[i]]) { esit[s[i]] = true; break; }
            }
        }
        for(int i = 1; i <= N; i++) if(!esit[i]) ok = false;
        if(ok) printf("Jerry\n");
        else printf("Tom\n");
    }
    return 0;
}