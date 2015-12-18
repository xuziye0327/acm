import java.util.*;
import java.math.*;

public class Main {
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		int T = cin.nextInt();
		while (T-- > 0) {
			int n = cin.nextInt();
			if (n == 0 || n == 1) {
				System.out.println(1);
				continue;
			} else if (n == 2) {
				System.out.println(2);
				continue;
			}
			BigInteger V = BigInteger.ZERO;
			BigInteger E = BigInteger.ZERO;
			for (int i = 1; i <= n - 3; ++i) {
				V = V.add(BigInteger.valueOf(n - 2 - i).multiply(BigInteger.valueOf(i)));
				E = E.add(BigInteger.valueOf(n - 2 - i).multiply(BigInteger.valueOf(i))).add(BigInteger.ONE);
			}
			V = V.multiply(BigInteger.valueOf(n)).divide(BigInteger.valueOf(4)).add(BigInteger.valueOf(n));
			E = E.multiply(BigInteger.valueOf(n)).divide(BigInteger.valueOf(2)).add(BigInteger.valueOf(2 * n));
			System.out.println(E.subtract(V).add(BigInteger.ONE));
		}
	}
}