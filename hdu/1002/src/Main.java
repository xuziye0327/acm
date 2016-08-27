import sun.security.krb5.SCDynamicStoreConfig;

import java.math.*;
import java.util.Scanner;


public class Main {

    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        int Case = 0;
        int t = cin.nextInt();
        while(t > 0) {
            t--;
            if(Case != 0)
                System.out.println();;
            BigInteger a = cin.nextBigInteger();
            BigInteger b = cin.nextBigInteger();
            System.out.println("Case " + (++Case) + ":");
            System.out.println(a + " + " + b + " = " + a.add(b));
        }
    }
}
