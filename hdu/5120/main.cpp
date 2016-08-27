#include <iostream>
#include <cstdio>

#include <cstring>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <ctime>

#include <stack>
#include <queue>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define MP(x,y) make_pair(x,y)
#define CLR(a, b) memset(a, b, sizeof(a))
#define HERE printf("here!\n")
#define RANDOM srand((unsigned)time(NULL))

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const double PI = acos(-1);
const int inf = 1 << 30;
const int maxn = 15 + 7;
const double eps = 1E-8;

struct Point{
    double x,y;
}pa,pb;

double dist(Point a,Point b){
    return sqrt( (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y) );
}

double magic(Point c1,double r1,Point c2,double r2){
    double d=dist(c1,c2);
    if(r1+r2<d+eps) return 0;
    if(d<fabs(r1-r2)+eps){
        double r= min(r1,r2);
        return PI*r*r;
    }
    double x=(d*d+r1*r1-r2*r2)/(2*d);
    double t1=acos(x/r1);
    double t2=acos((d-x)/r2);
    return r1*r1*t1+r2*r2*t2-d*r1*sin(t1);
}

int main() {
    int T,Case = 0;
    scanf("%d",&T);
    while(T--){
        double ra,rb;
        scanf("%lf %lf",&ra,&rb);
        scanf("%lf %lf",&pa.x,&pa.y);
        scanf("%lf %lf",&pb.x,&pb.y);
        double big = magic(pa,rb,pb,rb);
        double small = magic(pa,ra,pb,ra);
        double small1 = magic(pa, ra, pb, rb);
        double small2 = magic(pa, rb, pb, ra);
        printf("Case #%d: %.6f\n",++Case,big + small - small1 - small2);
    }
    return 0;
}