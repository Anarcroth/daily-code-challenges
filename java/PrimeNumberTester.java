import java.util.ArrayList;

public class PrimeNumberTester {

    public int prNumber;

    private ArrayList<Integer> range;

    public PrimeNumberTester() {
        this.prNumber = 1;
    }

    public PrimeNumberTester(int prNumber) {
        this.prNumber = prNumber;
    }

    public void assign(int prNumber) {
        this.prNumber = prNumber;

        range = new ArrayList<>();
        for (int i = 1; i < prNumber - 1; i++) {
            if (prNumber % i == 0) {
                range.add(i);
            }
        }
    }

    private int sumOfDivisors() {
        return range.stream().mapToInt(Integer::intValue).sum();
    }

    public boolean isPerfect() {
        return (prNumber == sumOfDivisors()) ? true : false;
    }

    public boolean isDeficient() {
        return (prNumber > sumOfDivisors()) ? true : false;
    }

    public boolean isAbundant() {
        return (prNumber < sumOfDivisors()) ? true : false;
    }
}
