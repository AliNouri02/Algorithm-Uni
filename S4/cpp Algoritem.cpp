//Ali Nouri 
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

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
    vector<vector<int>> B(n + 1, vector<int>(k + 1));

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= min(i, k); j++) {
            if (j == 0 || j == i) B[i][j] = 1;
            else B[i][j] = B[i - 1][j - 1] + B[i - 1][j];
        }
    }
    return B[n][k];
}

int minmult(int n, int d[], vector<vector<int>>& P) {
    vector<vector<int>> M(n, vector<int>(n, 0));

    for (int t = 1; t <= n - 1; t++) {
        for (int i = 1; i <= n - t; i++) {
            int j = i + t;
            int min_val = INT_MAX;
            int min_k = i;
            for (int k = i; k < j; k++) {
                int cost = M[i][k] + M[k + 1][j] + d[i - 1] * d[k] * d[j];
                if (cost < min_val) {
                    min_val = cost;
                    min_k = k;
                }
            }
            M[i][j] = min_val;
            P[i][j] = min_k;
        }
    }
    return M[1][n];
}

int main() {
    cout << "hi welcome to session 4";
    int ch;
    do {
        cout << "\nMenu";
        cout << "\n1. use Fibonacci";
        cout << "\n2. use Calculation of the binomial coefficient";
        cout << "\n3. use Minimum multiples";
        cout << "\n4. Exit";
        cout << "\nEnter your choice 1 to 4=";
        cin >> ch;
        switch (ch) {
            case 1: {
                int n;
                cout << "Enter the value of number: ";
                cin >> n;

                if (n < 0) {
                    cout << "Fibonacci sequence is not defined for negative numbers." << endl;
                } else {
                    int result_fib = fibonacci(n);
                    cout << "The " << n << "th term of the Fibonacci sequence is: " << result_fib << endl;
                }
                break;
            }
            case 2: {
                int n_bin, k_bin;
                cout << "Enter values for n and k (binomial coefficient): ";
                cin >> n_bin >> k_bin;
                int result_bin = bin(n_bin, k_bin);
                cout << "C(" << n_bin << ", " << k_bin << ") = " << result_bin << endl;
                break;
            }
            case 3: {
                int n_minmult;
                cout << "Enter the number of matrices (minmult): ";
                cin >> n_minmult;
                vector<int> dimensions(n_minmult + 1);
                for (int i = 0; i <= n_minmult; i++) {
                    cout << "Enter dimension " << i << ": ";
                    cin >> dimensions[i];
                }
                vector<vector<int>> P(n_minmult + 1, vector<int>(n_minmult + 1, 0));
                int result_minmult = minmult(n_minmult, dimensions.data(), P);
                cout << "Minimum number of multiplications: " << result_minmult << endl;
                break;
            }
            case 4:
                exit(0);
                break;
            default:
                cout << "Invalid choice !" << endl;
                break;
        }
    } while (ch <= 3);

    return 0;
}
