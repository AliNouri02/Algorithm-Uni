#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int fibonacci(int n) {
    vector<int> f(n + 1);
    f[0] = 0;
    if (n > 0) {
        f[1] = 1;
        for (int i = 2; i <= n; i++) {
            f[i] = f[i - 1] + f[i - 2];
        }
    }
    return f[n];
}

int bin(int n, int k) {
    vector<vector<int>> B(n, vector<int>(k));

    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= min(i, k); j++)
            if (j == 0 || j == i) B[i][j] = 1;
            else B[i][j] = B[i - 1][j - 1] + B[i - 1][j];
    return B[n][k];
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    if (n < 0) {
        cout << "Fibonacci sequence is not defined for negative numbers." << endl;
    }
    else {
        int result = fibonacci(n);
        cout << "The " << n << "th term of the Fibonacci sequence is: " << result << endl;
    }

   
    return 0;
}