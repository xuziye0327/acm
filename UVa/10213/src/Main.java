/**
 * Created by myz on 2015/10/14.
 */
import java.util.*;
        import java.math.*;

public class Main {
    public static void main (String[] args) {
        Scanner cin = new Scanner(System.in);
        int T = cin.nextInt();
        while (T-- > 0) {
            BigInteger n = cin.nextBigInteger();
            BigInteger V = n.multiply(n.subtract(BigInteger.ONE)).multiply(n.subtract(BigInteger.valueOf(2))).multiply(n.subtract(BigInteger.valueOf(3))).divide(BigInteger.valueOf(24)).add(n);
            BigInteger E = n.subtract(BigInteger.ONE).multiply(n.subtract(BigInteger.valueOf(2))).multiply(n.subtract(BigInteger.valueOf(3))).divide(BigInteger.valueOf(6)).add(n).subtract(BigInteger.valueOf(3)).multiply(n).divide(BigInteger.valueOf(2)).add(n).add(n);
            System.out.println(E.add(BigInteger.ONE).subtract(V));
        }
    }
}
