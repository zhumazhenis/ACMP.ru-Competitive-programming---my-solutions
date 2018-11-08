// https://acmp.ru/index.asp?main=source&id=8518207

import java.math.BigInteger;
import java.io.PrintWriter;
import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;
 
public class Task {
 
  static BigInteger[][] d = new BigInteger[101 * 9][101];
  static BigInteger ans = new BigInteger("0");;
 
  public static void main(String[] args) {
    Scanner sc = null;
    PrintWriter pw = null;
    try {
      sc = new Scanner(new File("input.txt"));
      pw = new PrintWriter(new File("output.txt"));
    } catch (FileNotFoundException e) {
 
    }
 
    int n = sc.nextInt() / 2;
    for (int i = 1; i <= n * 9; i++) {
      for (int j = 1; j <= n; j++) {
        d[i][j] = new BigInteger("-1");
      }
    }
 
    for (int i = 0; i <= n * 9; i++)
      ans = ans.add((calc(i, n).multiply(calc(i, n))));
    // System.out.print(ans.toString());
    pw.print(ans.toString());
    pw.close();
  }
 
  static BigInteger calc(int n, int k) {
 
    if (k < 1 || (double) n / k > 9)
      return d[n][0] = new BigInteger("0");
    if (k == 1 || n == 0)
      return d[n][k] = new BigInteger("1");
    if (!d[n][k].equals(new BigInteger("-1")))
      return d[n][k];
    d[n][k] = new BigInteger("0");
    for (int i = n; (i >= 0) && (i >= (n - 9)); i--) {
      d[n][k] = d[n][k].add(calc(i, k - 1));
    }
    return d[n][k];
  }
}
