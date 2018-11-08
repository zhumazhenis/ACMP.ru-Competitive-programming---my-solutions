// https://acmp.ru/index.asp?main=source&id=8526837

import java.math.BigInteger;
import java.io.PrintWriter;
import java.util.Scanner;
import java.util.function.BiFunction;
import java.io.File;
import java.io.FileNotFoundException;
 
public class Task {
 
  static BigInteger[][] d = new BigInteger[101][10];
 
  public static void main(String[] args) {
    Scanner sc = null;
    PrintWriter pw = null;
    try {
      sc = new Scanner(new File("input.txt"));
      pw = new PrintWriter(new File("output.txt"));
    } catch (FileNotFoundException e) {
    }
    int n = sc.nextInt();
 
    for (int i = 0; i <= 100; i++)
      for (int j = 0; j <= 9; j++) {
        d[i][j] = new BigInteger("-1");
        if (i == 1)
          d[i][j] = new BigInteger("1");
      }
 
    BigInteger ans = new BigInteger("0");
    for (int i = 0; i <= 9; i++)
      if (i != 0 && i != 8)
        ans = ans.add(calc(n, i));
    pw.print(ans.toString());
    pw.close();
  }
 
  static BigInteger calc(int n, int k) {
    if (!d[n][k].equals(new BigInteger("-1")))
      return d[n][k];
    if (n == 0)
      return d[n][k] = new BigInteger("0");
 
    if (k == 1)
      d[n][k] = calc(n - 1, 6).add(calc(n - 1, 8));
    if (k == 2)
      d[n][k] = calc(n - 1, 7).add(calc(n - 1, 9));
    if (k == 3)
      d[n][k] = calc(n - 1, 4).add(calc(n - 1, 8));
    if (k == 4)
      d[n][k] = calc(n - 1, 0).add(calc(n - 1, 3)).add(calc(n - 1, 9));
    if (n > 1)
      if (k == 5)
        d[n][k] = new BigInteger("0");
    if (k == 6)
      d[n][k] = calc(n - 1, 0).add(calc(n - 1, 1)).add(calc(n - 1, 7));
    if (k == 7)
      d[n][k] = calc(n - 1, 2).add(calc(n - 1, 6));
    if (k == 8)
      d[n][k] = calc(n - 1, 1).add(calc(n - 1, 3));
    if (k == 9)
      d[n][k] = calc(n - 1, 2).add(calc(n - 1, 4));
    if (k == 0)
      d[n][k] = calc(n - 1, 4).add(calc(n - 1, 6));
    return d[n][k];
  }
}
