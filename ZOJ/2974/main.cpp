#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 20 + 7;

struct Matrix {
    double M[maxn][maxn];
    Matrix() { memset(M, 0, sizeof(M)); }
};

int n, m, k;
double con[maxn], ans[maxn];
Matrix a, res;

void init() {
    memset(ans, 0, sizeof(ans));
    memset(con, 0, sizeof(con));
    memset(a.M, 0, sizeof(a.M));
    memset(res.M, 0, sizeof(res.M));
}

Matrix matrixMul (Matrix m1, Matrix m2) {
    Matrix m3;
    memset(m3.M, 0, sizeof(m3.M));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            for (int k = 1; k <= n; ++k) {
                m3.M[i][j] += m1.M[i][k] * m2.M[k][j];
            }
        }
    }
    return m3;
}

void matrixMulT(int t) {
    for(int i = 0; i < maxn; ++i) res.M[i][i] = 1.0;
    while(t) {
        if(t & 1) {
            res = matrixMul(res, a);
        }
        t = t >> 1;
        a = matrixMul(a, a);
    }
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        init();
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) scanf("%lf", &con[i]);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &k);
            if(k == 0) a.M[i][i] = 1.0;
            int pos;
            double t = 1.0 / (k * 1.0);
            for (int j = 0; j < k; ++j) {
                scanf("%d", &pos);
                a.M[i][pos] = t;
            }
        }
        scanf("%d", &m);
        matrixMulT(m);
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                ans[i] += res.M[j][i] * con[j];
            }
        }
        for(int i = 1; i <= n; ++i) {
            if(i != 1) printf(" ");
            printf("%.2f", ans[i]);
        }
        printf("\n");
    }
    return 0;
}