#include <iostream>
#include <vector>

int fibonacci(int n) {
    std::vector<int> f(n + 1);
    f[0] = 0;
    if (n > 0) {
        f[1] = 1;
        for (int i = 2; i <= n; i++) {
            f[i] = f[i - 1] + f[i - 2];
        }
    }
    return f[n];
}

int main() {
    int n;
    std::cout << "Enter the ssssssssssssssssssssssssssssssss of n: ";
    std::cin >> n;

    if (n < 0) {
        std::cout << "Fibonacci sequence is not defined for negative numbers." << std::endl;
    }
    else {
        int result = fibonacci(n);
        std::cout << "The " << n << "th term of the Fibonacci sequence is: " << result << std::endl;
    }

    return 0;
}