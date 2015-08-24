#include <cstdio>
#include <algorithm>
#include <map>
#include <cstring>
#include <iostream>
#include <string>

using namespace std;

typedef pair<int, int> P;

map<string, P> lis;

int main() {
    for(int i = 0; i < 6; ++i) {
        int pic;
        string t1, type;
        cin >> t1 >> type >> pic;
        if(!lis.count(type)) lis[type] = make_pair(1, pic);
        else {
            P p = lis[type];
            ++p.first; p.second = min(p.second, pic);
            lis[type] = p;
        }
    }
    string hehe;
    int cnt(0), hehehe(1 << 30);
    map<string, P> :: iterator it;
    for(it = lis.begin(); it != lis.end(); ++it) {
        cnt = max(cnt, (*it).second.first);
    }
    for(it = lis.begin() ; it != lis.end(); ++it) {
        if(cnt == (*it).second.first) {
            if(hehehe > (*it).second.second) {
                hehehe = (*it).second.second;
                hehe = (*it).first;
            }
        }
    }
    cout << hehe;
    return 0;
}