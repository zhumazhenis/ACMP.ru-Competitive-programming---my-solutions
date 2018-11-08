// https://acmp.ru/index.asp?main=source&id=8526846

import java.math.BigInteger;
import java.io.PrintWriter;
import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;
 
public class Task {
 
  static BigInteger[] fib = new BigInteger[1001];
 
  public static void main(String[] args) {
    Scanner sc = null;
    PrintWriter pw = null;
    try {
      sc = new Scanner(new File("input.txt"));
      pw = new PrintWriter(new File("output.txt"));
    } catch (FileNotFoundException e) {
    }
    int n = sc.nextInt();
 
    // start
    fib[0] = new BigInteger("1");
    fib[1] = new BigInteger("2");
    for (int i = 2; i <= n; i++)
      fib[i] = fib[i - 1].add(fib[i - 2]);
 
    pw.print(fib[n].toString());
    pw.close();
  }
}
