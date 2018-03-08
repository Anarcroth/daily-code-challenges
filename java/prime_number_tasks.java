import java.util.ArrayList;
import java.util.HashSet;
import java.util.Set;

public class PrimeNumberTasks {

    public static void main(String args[]) {

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

    public void emirpNumbers() {

    }

    public void additivePrimes() {

    }

    public void marsennePrimes() {

    }

    public void twinPrimes() {

    }

    private class PrimeNumberTester {

        private boolean isPerfect(int n) {

        }

        private boolean isDeficient(int n) {

        }

        private boolean isAbundant(int n) {

        }

        private boolean isPrime(int n) {

        }
    }
}
