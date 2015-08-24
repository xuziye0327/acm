#include <bits/stdc++.h>

using namespace std;

const int maxn = 50 + 7;

bool ok;
string s, t, a, b, c, ab, cab, abab, ababa, ababcab;

void init() {
    ok = false;
    s.clear();
    t.clear();
    a.clear();
    b.clear();
    c.clear();
    ab.clear();
    cab.clear();
    abab.clear();
    ababa.clear();
    ababcab.clear();
}

void change(const string from, string &to) {
    for(size_t i = 0; i < from.size(); i++) {
        if(from[i] >= 'a' && from[i] <= 'z') {
            to += from[i];
        } else if(from[i] >= 'A' && from[i] <= 'Z') {
            to += from[i];
        }
    }
}

bool getab(const string S) {
    string t1, t2;
    int len = ab.size() + 1;
    while(len <= s.size()) {
        t1 = s.substr(0, len);
        if(t1.size() > s.size() / 2) return false;
        t2 = s.substr(len, len);
        if(t1 == t2) {
            ab = t1;
            return true;
        }
        len++;
    }
    return false;
}

int main() {
    int T;
    cin >> T;
    while(T--) {
        init();
        cin >> t;
        change(t, s);
        while(true) {
            if(!getab(s)) break;
            if(ab.size() * 2 >= s.size()) break;
            for(int i = 1; i < ab.size(); i++) {
                a = ab.substr(0, i);
                b = ab.substr(i, ab.size() - i);
                abab = ab + ab;
                if(a != b) {
                    ababa = ab + ab + a;
                    if(s == ababa) {
                        ok = true;
                        break;
                    } else if(s.size() - abab.size() > 0){
                        cab = s.substr(abab.size(), s.size() - abab.size());
                        if(cab.size() > ab.size()) {
                            c = cab.substr(0, cab.size() - ab.size());
                            if(ab == cab.substr(cab.size() - ab.size(), cab.size() - c.size()) && a != c && b != c) {
                                ok = true;
                                break;
                            }
                        }
                    }
                }
            }
            if(ok) break;
        }
        if(ok) cout << "Yes" << endl;
        else   cout << "No"  << endl;
    }
    return 0;
}