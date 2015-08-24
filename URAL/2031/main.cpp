#include <cstdio>
#include <algorithm>
#include <map>
#include <cstring>
#include <iostream>
#include <string>

using namespace std;

typedef unsigned long long ull;

int main() {
    int n;
    scanf("%d", &n);
    if(n == 1) printf("01");
    else if(n == 2) printf("11 01");
    else if(n == 3) printf("11 01 60");
    else if(n == 4) printf("11 01 60 80");
    else  printf("Glupenky Pierre");
    return 0;
}