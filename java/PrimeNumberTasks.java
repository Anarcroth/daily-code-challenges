import java.util.ArrayList;
import java.util.HashSet;
import java.util.Set;

public class PrimeNumberTasks {

  public static void main(String args[]) {

    // Vampire Numbers for all 4-digit numbers
    for (int i = 1000; i < 10000; i++) {
      vampireNumbers(i);
    }

    // Test for Perfect, Deficient, Abundant, and Prime numbers from 1 to 250
    PrimeNumberTester pnt = new PrimeNumberTester();
    for (int i = 1; i < 251; i++) {
      pnt.assign(i);
      if (isPrime(i)) { System.out.println(i + " is prime!"); }
      else if (pnt.isAbundant()) { System.out.println(i + " is abundant!"); }
      else if (pnt.isDeficient()) { System.out.println(i + " is deficient!"); }
      else if (pnt.isPerfect()) { System.out.println(i + " is perfect!"); }
    }

    // Display first 100 emirp numbers
    emirpNumbers(100);

    // Display first 25 additive primes
    additivePrimes(25);

    // Display Marsenne numbers from 1 to 31 for `p`
    for (int p = 1; p < 32; p++) {
      marsennePrimes(p);
    }

    // Display all twin primes less than 1000
    twinPrimes(1000);
  }

  public static boolean isPrime(int n) {
    for(int divisor = 2; divisor <= n / 2; divisor++) {
      if (n % divisor == 0) {
        return false;
      }
    }
    return true;
  }

  private static Set<String> generatePerm(String input) {
    Set<String> set = new HashSet<>();
    if (input.equals("")) {
      return set;
    }

    Character a = input.charAt(0);
    if (input.length() > 1)
    {
      input = input.substring(1);
      Set<String> permSet = generatePerm(input);

      for (String x : permSet) {
        for (int i = 0; i <= x.length(); i++) {
          set.add(x.substring(0, i) + a + x.substring(i));
        }
      }
    }
    else {
      set.add(a + "");
    }

    return set;
  }

  static public void vampireNumbers(Integer n) {
    int length = n.toString().length();
    if (length % 2 == 0) {

      ArrayList<String> permsOfN = new ArrayList<String>();
      permsOfN.addAll(generatePerm(n.toString()));

      for (int i = 0; i < permsOfN.size() - 1; i++) {
        if (n.equals(Integer.parseInt(permsOfN.get(i).substring(0, length / 2))
            * Integer.parseInt(permsOfN.get(i).substring(length / 2, length)))) {
          System.out.println(n + " is a vampire number!");
        }
      }
    } else {

      System.out.println("Please enter a number with even digits.");
    }
  }

  public static void emirpNumbers(int range) {
    for (Integer i = 1; i < range; i++) {
      Integer rev_n = Integer.parseInt(new StringBuilder(i.toString()).reverse().toString());
      if (isPrime(i) && isPrime(rev_n) && !i.equals(rev_n)) {
        System.out.println("prime: " + i + " / emirp: " + rev_n);
      }
    }
  }

  public static void additivePrimes(int range) {
    for (int i = 1; i < range; i++) {
      int sum_n = 0;
      int temp = i;
      while (temp > 0) {
        sum_n += temp % 10;
        temp = temp / 10;
      }
      if (isPrime(sum_n) && isPrime(i)) {
        System.out.println("An additive prime is " + i);
      }
    }
  }

  public static void marsennePrimes(Integer p) {
    if (isPrime((int)Math.pow(2, p) - 1)) {
      System.out.println("For p = " + p + ", " + (int)(Math.pow(2, p) - 1) + " is a Marsenne prime");
    }
  }

  public static void twinPrimes(int range) {
    ArrayList<Integer> primes_in_range = new ArrayList<Integer>();
    for (int i = 0; i < range; i++) {
      if (isPrime(i)) {
        primes_in_range.add(i);
      }
    }

    for (int i = 0; i < primes_in_range.size() - 1; i++) {
      if (primes_in_range.get(i + 1) - primes_in_range.get(i) == 2) {
        System.out.println("(" + primes_in_range.get(i)  + ", " + primes_in_range.get(i + 1) + ")");
      }
    }
  }
}
