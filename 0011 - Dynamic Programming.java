// https://acmp.ru/index.asp?main=source&id=8518289

import java.math.BigInteger;
import java.io.PrintWriter;
import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;
 
public class Task {
 
  static BigInteger[] a = new BigInteger[301];
  static int k;
 
  public static void main(String[] args) {
    Scanner sc = null;
    PrintWriter pw = null;
    try {
      sc = new Scanner(new File("input.txt"));
      pw = new PrintWriter(new File("output.txt"));
    } catch (FileNotFoundException e) {
    }
 
    k = sc.nextInt();
    int n = sc.nextInt();
 
    for (int i = 0; i <= 300; i++) {
      a[i] = new BigInteger("-1");
    }
    a[0] = new BigInteger("1");
    a[1] = new BigInteger("1");
 
    // System.out.print(ans.toString());
    BigInteger ans = calc(n);
    pw.print(ans.toString());
    pw.close();
  }
 
  static BigInteger calc(int m) {
    if (!a[m].equals(new BigInteger("-1"))) {
      return a[m];
    }
 
    BigInteger ans = new BigInteger("0");
    for (int i = 1; i <= k; i++) {
      if (m - i < 0) {
        break;
      }
      ans = ans.add(calc(m - i));
    }
    return a[m] = ans;
  }
}
