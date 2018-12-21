// Given a square matrix, calculate the absolute difference between the sums of its diagonals.
// https://www.hackerrank.com/challenges/diagonal-difference/problem
int diagonalDifference(vector<vector<int>> arr) {
    int d1 = 0, d2 = 0;
    int j = 0;
    for (int i = 0; i < arr.size(); i++) {
        d1 += arr[i][j];
        d2 += arr[arr.size() - 1 - i][j];
        j += 1;
    }
    return abs(d1 - d2);
}

// Given an array of integers, find the sum of its elements.
// https://www.hackerrank.com/challenges/simple-array-sum/problem
int simpleArraySum(vector<int> ar) {
    int sum = 0;
    for (auto &n : ar) {
        sum += n;
    }
    return sum;
}

// Calculate and print the sum of the elements in an array, keeping in mind that some of those integers may be quite large.
// https://www.hackerrank.com/challenges/a-very-big-sum/problem
long aVeryBigSum(vector<long> ar) {
    long long int sum = 0;
    for (auto& i : ar) {
        sum += i;
    }
    return sum;
}

// Given an array of integers, calculate the fractions of its elements that are positive, negative, and are zeros. Print the decimal value of each fraction on a new line.
// https://www.hackerrank.com/challenges/plus-minus/problem
void plusMinus(vector<int> arr) {
    long double posr = 0.0, negr = 0.0, zr = 0.0;
    for (auto& i : arr) {
        if (i > 0) {
            posr += 1.0;
        } else if (i < 0) {
            negr += 1.0;
        } else {
            zr += 1.0;
        }
    }
    cout << posr / arr.size() << endl;
    cout << negr / arr.size() << endl;
    cout << zr / arr.size() << endl;
}

// Given five positive integers, find the minimum and maximum values that can be calculated by summing exactly four of the five integers. Then print the respective minimum and maximum values as a single line of two space-separated long integers.
// https://www.hackerrank.com/challenges/mini-max-sum/problem
void miniMaxSum(vector<int> arr) {
    sort(begin(arr), end(arr));
    long long int sum = 0;
    for (auto &i : arr) {
      sum += i;
    }
    long long int min = sum - arr[4];
    long long int max = sum - arr[0];
    cout << min << " " << max;
}
