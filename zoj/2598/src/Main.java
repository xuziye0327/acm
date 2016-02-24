import java.util.*;
import java.math.*;

public class Main {

    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);

        while(cin.hasNextBigInteger()) {
            BigInteger R = cin.nextBigInteger();
            if(R.compareTo(BigInteger.ZERO) < 0) break;
            int c = 0;
            BigInteger x = BigInteger.ONE, y = BigInteger.ZERO;
            for(int i = 0; i < R.bitLength(); ++i) {
                if(R.testBit(i)) {
                    BigInteger xx = x.add(y);
                    BigInteger yy = x.multiply(BigInteger.valueOf(c)).add(y.multiply(BigInteger.valueOf(c + 1)));
                    x = xx; y = yy;
                    c = 0;
                } else ++c;
            }
            System.out.println(x.add(y));
        }
    }
}
