// https://acmp.ru/index.asp?main=source&id=9025383

import java.math.BigInteger;
import java.io.PrintWriter;
import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;
 
public class A {
 
  static BigInteger[] d = new BigInteger[1009];
  static int n, a;
 
  public static void main(String[] args) {
    Scanner sc = null;
    PrintWriter pw = null;
    try {
      sc = new Scanner(new File("input.txt"));
      pw = new PrintWriter(new File("output.txt"));
    } catch (FileNotFoundException e) {
    }
 
    n = sc.nextInt();
    a = sc.nextInt();
 
    // start
    d[1] = new BigInteger("1");
    d[0] = new BigInteger("1");
    for (int i = 2; i <= n; i++) {
      if (i - 1 - a >= 0) {
        d[i] = d[i - 1].multiply(new BigInteger("2")).subtract(d[i - 1 - a]);
      } else {
        d[i] = d[i - 1].multiply(new BigInteger("2")); 
      }
    }
 
    // System.out.print(ans.toString());
    pw.print(d[n].toString());
    pw.close();
  }
}
