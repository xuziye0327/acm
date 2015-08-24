import java.util.Scanner;
import java.math.*;
import java.text.*;

public class Main {
    public static void main(String[] args){
        Scanner cin = new Scanner (System.in);
        int M, N;
        int t;
        t = cin.nextInt();
        while(t > 0) {
            t--;
            M = cin.nextInt();
            N = cin.nextInt();
            String M1, N1;
            M1 = String.valueOf(M);
            N1 = String.valueOf(N);
            BigInteger a = new BigInteger(M1);
            BigInteger b = new BigInteger(N1);
            a = a.pow(N - 1);
            BigInteger aa = a;
            BigInteger bb = b;
            System.out.println((b.divide(hehe(aa, bb))) + "/" + (a.divide(hehe(aa, bb))));
        }
    }
    public static BigInteger hehe(BigInteger aa, BigInteger bb) {
        BigInteger zero = new BigInteger("0");
        return bb.equals(zero) ? aa : hehe(bb, aa.remainder(bb));
    }
}