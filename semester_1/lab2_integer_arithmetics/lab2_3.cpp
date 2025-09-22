#include <iostream>

int main() {
    std::cout << "Enter a natural number: ";
    int num_n, n, mod;
    int min_num = 9; // starting from the biggest number - 9
    if (!(std::cin >> n) || n <= 0) {
        std::cout << "Error";
        return 1;
    }
    num_n = n; // num_n is a number = n
    while (n) {
        mod = n % 10;
        if (mod != 0 && mod < min_num) {
            min_num = mod;
        }
        n /= 10;
    }
    std::cout << "New number: " << min_num << num_n << min_num;
    return 0;
}
