// https://acmp.ru/index.asp?main=source&id=8526791

import java.math.BigInteger;
import java.io.PrintWriter;
import java.util.Scanner;
import java.util.function.BiFunction;
import java.io.File;
import java.io.FileNotFoundException;
 
public class Task {
 
  static BigInteger[][] d = new BigInteger[21][21];
 
  public static void main(String[] args) {
    Scanner sc = null;
    PrintWriter pw = null;
    try {
      sc = new Scanner(new File("input.txt"));
      pw = new PrintWriter(new File("output.txt"));
    } catch (FileNotFoundException e) {
    }
    int n = sc.nextInt();
    int a = sc.nextInt();
    int b = sc.nextInt();
    for (int i = 0; i <= 20; i++) {
      for (int j = 0; j <= 20; j++) {
        d[i][j] = new BigInteger("-1");
        if (i == 0)
          d[i][j] = new BigInteger("1");
      }
    }
 
    // System.out.print(ans.toString());
    BigInteger x = new BigInteger("0");
    for (int i = 0; i <= a; i++) {
      x = x.add(calc(i, n));
    }
 
    BigInteger y = new BigInteger("0");
    for (int i = 0; i <= b; i++) {
      y = y.add(calc(i, n));
    }
 
    BigInteger ans = x.multiply(y);
    pw.print(ans.toString());
    pw.close();
  }
 
  static BigInteger calc(int k, int n) {
    if (!d[k][n].equals(new BigInteger("-1")))
      return d[k][n];
    if (n == 0)
      return new BigInteger("0");
    BigInteger ans = new BigInteger("0");
    for (int i = k; i >= 0; i--) {
      ans = ans.add(calc(i, n - 1));
    }
    return d[k][n] = ans;
  }
}
