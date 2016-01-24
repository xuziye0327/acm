import java.math.BigInteger;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        int T = cin.nextInt();
        boolean blank = false;
        while (T-- != 0) {
            if (blank) System.out.println("");
            blank = true;
            BigInteger n = cin.nextBigInteger();
            n = n.subtract(BigInteger.ONE);
            int M, P;
            M = cin.nextInt();
            P = cin.nextInt();
            int ma[][] = new int[37][37];
            for (int i = 0; i < 1 << M; ++i) {
                for (int j = 0; j < 1 << M; ++j) {
                    boolean flag = true;
                    for (int k = 1; k < M; ++k) {
                        if (((i >> (k - 1)) & 1) == ((j >> (k - 1)) & 1)
                                && ((i >> (k - 1)) & 1) == ((i >> k) & 1)
                                && ((i >> k) & 1) == ((j >> k) & 1)) {
                            flag = false;
                            break;
                        }
                    }
                    if (flag) {
                        ma[i + 1][j + 1] = 1;
                    } else {
                        ma[i + 1][j + 1] = 0;
                    }
                }
            }
            int ans[][] = new int[37][37];
            for (int i = 1; i <= 1 << M; ++i) {
                for (int j = 1; j <= 1 << M; ++j) {
                    ans[i][j] = i == j ? 1 : 0;
                }
            }
            while (!n.equals(BigInteger.ZERO)) {
                int temp[][];
                temp = new int[37][37];
                if (n.mod(BigInteger.valueOf(2)).equals(BigInteger.ONE)) {
                    for (int i = 1; i <= 1 << M; ++i) {
                        for (int j = 1; j <= 1 << M; ++j) {
                            int t = 0;
                            for (int k = 1; k <= 1 << M; ++k) {
                                t = (t + ans[i][k] * ma[k][j]) % P;
                            }
                            temp[i][j] = t;
                        }
                    }
                    ans = temp;
                }
                temp = new int[37][37];
                for (int i = 1; i <= 1 << M; ++i) {
                    for (int j = 1; j <= 1 << M; ++j) {
                        int t = 0;
                        for (int k = 1; k <= 1 << M; ++k) {
                            t = (t + ma[i][k] * ma[k][j]) % P;
                        }
                        temp[i][j] = t;
                    }
                }
                ma = temp;
                n = n.shiftRight(1);
            }
            int t = 0;
            for (int i = 1; i <= 1 << M; ++i) {
                for (int j = 1; j <= 1 << M; ++j) {
                    t = (t + ans[i][j]) % P;
                }
            }
            System.out.println(t);
        }
    }
}
