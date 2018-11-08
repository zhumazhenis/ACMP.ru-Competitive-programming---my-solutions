// https://acmp.ru/index.asp?main=source&id=8518223

import java.math.BigInteger;
import java.io.PrintWriter;
import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;
 
public class Task {
 
  static BigInteger[] d = new BigInteger[102];
 
  public static void main(String[] args) {
    Scanner sc = null;
    PrintWriter pw = null;
    try {
      sc = new Scanner(new File("input.txt"));
      pw = new PrintWriter(new File("output.txt"));
    } catch (FileNotFoundException e) {
 
    }
 
    int n = sc.nextInt();
    d[0] = new BigInteger("2");
    for (int i = 1; i <= n; i++) {// d[i] = 3 * d[i - 1] - 2;
      d[i] = d[i - 1].multiply(new BigInteger("3"));
      d[i] = d[i].subtract(new BigInteger("2"));
    }
    // System.out.print(ans.toString());
    pw.print(d[n].toString());
    pw.close();
  }
}
