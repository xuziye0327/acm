import java.math.BigInteger;
import java.util.Scanner;

/**
 * Created by myz on 2015/11/11.
 */
public class Main {
    static public void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        int t = cin.nextInt();
        BigInteger b;
        boolean blank = false;
        while (t-- > 0) {
            if (blank) {
                System.out.println();
            }
            blank = true;
            b = cin.nextBigInteger();
            if (b.mod(BigInteger.valueOf(2)).equals(BigInteger.ONE)) {
                System.out.println(b.divide(BigInteger.valueOf(2)));
            } else {
                BigInteger temp = b.divide(BigInteger.valueOf(2));
                if (temp.mod(BigInteger.valueOf(2)).equals(BigInteger.ONE)) {
                    temp = temp.subtract(BigInteger.valueOf(2));
                } else {
                    temp = temp.subtract(BigInteger.ONE);
                }
                System.out.println(temp);
            }
        }
    }
}
