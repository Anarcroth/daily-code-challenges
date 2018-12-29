// Write a program that prints a staircase of size n
void staircase(int n) {
    for (int i = 1; i <= n; i++) {
        for (int k = 0; k < n - i; k++) {
            cout << " ";
        }
        for (int j = 0; j < i; j++) {
            cout << "#";
        }
        cout << endl;
    }
}

void countApplesAndOranges(int s, int t, int a, int b, vector<int> apples, vector<int> oranges) {
    int t_apples = 0;
    int t_oranges = 0;
    for (auto& apple : apples) {
      if (a + apple >= s && a + apple <= t) {
        t_apples += 1;
      }
    }
    for (auto& orange : oranges) {
      if (b + orange <= t && b + orange >= s) {
        t_oranges += 1;
      }
    }
    cout << t_apples << "\n" << t_oranges;
}
vector<int> gradingStudents(vector<int> grades) {
    /*
     * Write your code here.
     */
     for (auto& g : grades) {
         if (g + 2 < 40) {
             continue;
         }
         if ((g + 1) % 5 == 0) {
             g += 1;
         } else if ((g + 2) % 5 == 0) {
             g += 2;
         }
     }
     return grades;
}
