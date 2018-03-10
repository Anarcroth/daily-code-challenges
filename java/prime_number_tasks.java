import java.util.ArrayList;
import java.util.HashSet;
import java.util.Set;

public class PrimeNumberTasks {

    public static void main(String args[]) {

    }

    private boolean isPrime(int n) {
        for(int divisor = 2; divisor <= n / 2; divisor++) {
            if (n % divisor == 0) {
                return false;
            }
        }
        return true;
    }

    private static Set<String> generatePerm(String input) {
        Set<String> set = new HashSet<String>();
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

    public void vampireNumbers(Integer n) {

        if (n.toString().length() % 2 == 0) {

            ArrayList<String> pairs_of_n = new ArrayList<String>();
            pairs_of_n.addAll(generatePerm(n.toString()));
            for (int i = 0; i < pairs_of_n.size() - 1; i++) {
                if (Integer.parseInt(pairs_of_n.get(i)) * Integer.parseInt(pairs_of_n.get(i + 1)) == n) {
                    System.out.println(n + " is a vampire number!");
                }
            }
        } else {

            System.out.println("Please enter a number with even digits.");
        }
    }

    public void emirpNumbers(Integer n) {
        Integer rev_n = Integer.parseInt(new StringBuilder(n.toString()).reverse().toString());
        if (isPrime(n) && isPrime(rev_n) && !n.equals(rev_n)) {
            System.out.println("prime: " + n + " / emirp: " + rev_n);
        }
    }

    public void additivePrimes(Integer n) {
        int sum_n = 0;
        int temp = n;
        while (temp > 0) {
            sum_n += temp % 10;
            temp = temp / 10;
        }
        if (isPrime(sum_n) && isPrime(n)) {
            System.out.println("An additive prime is " + n);
        }
    }


    public void marsennePrimes(Integer p) {
        if ((int)isPrime(Math.pow(2, p) - 1)) {
            System.out.println("For p = " + p + ", " + (Math.pow(2, p) - 1) + " is a Marsenne prime");
        }
    }

    public void twinPrimes(int range) {
        ArrayList<Integer> primes_in_range = new ArrayList<Integer>();
        for (int i = 0; i < range; i ++) {
            if (isPrime(i)) {
                primes_in_range.add(i);
            }
        }

        for (int i = 0; i < primes_in_range.size(); i++) {
            if (primes_in_range.get(i + 1) - primes_in_range.get(i) == 2) {
                System.out.println("(" + (i + 1) + ", " + i + ")");
            }
        }
    }

    private class PrimeNumberTester {

        public int prNumber;

        private ArrayList<Integer> range;

        public PrimeNumberTester(int prNumber) {
            this.prNumber = prNumber;
        }

        public void assign(int prNumber) {
            this.prNumber = prNumber;

            range = new ArrayList<>(prNumber);
            for (int i = 0; i < prNumber; i++) {
                range.add(i);
            }
        }

        private int sumOfDivisors() {
            return range.stream().mapToInt(Integer::intValue).sum();
        }

        private boolean isPerfect(Integer n) {
            return (prNumber == sumOfDivisors()) ? true : false;
        }

        private boolean isDeficient(int n) {
            return (prNumber < sumOfDivisors()) ? true : false;
        }

        private boolean isAbundant(int n) {
            return (prNumber > sumOfDivisors()) ? true : false;
        }
    }
}
