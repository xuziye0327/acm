import java.util.Scanner;
import java.math.BigInteger;

public class Main {

    static int n;

    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        int Case = 0, t = cin.nextInt();
        while(t != 0) {
            boolean ok = false;

            --t;
            n = cin.nextInt();
            BigInteger A = cin.nextBigInteger();
            BigInteger X = cin.nextBigInteger();
            BigInteger B = cin.nextBigInteger();
            BigInteger Y = cin.nextBigInteger();

            A = A.subtract(BigInteger.ONE);
            X = X.subtract(BigInteger.ONE);
            B = B.subtract(BigInteger.ONE);
            Y = Y.subtract(BigInteger.ONE);

            for(int i = 0; i <= n; ++i) {
                X = right(X);
                Y = right(Y);

                BigInteger M = X.xor(A);
                BigInteger N = Y.xor(B);

                if(M.equals(N)) {
                    ok = true;
                }
            }
            System.out.print("Case " + (++Case) + ": ");
            if(ok) System.out.println("Yes");
            else System.out.println("No");
        }
    }
    public static BigInteger right(BigInteger T) {
        BigInteger temp = T.and(BigInteger.ONE);
        return T.shiftRight(1).or(temp.shiftLeft(n - 1));
    }
}
