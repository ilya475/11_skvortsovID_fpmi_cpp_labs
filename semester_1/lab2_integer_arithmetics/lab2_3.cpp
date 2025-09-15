#include <iostream>

int main()
{
    setlocale(LC_ALL, "RU");
    std::cout << "Введите натуральное число ";
    int p, n, mod;
    int min = 0;
    std::cin >> n;
    if (!std::cin >> n || n<=0) {
        std::cout << "Error";
    std:exit(1);
    }
    p = n;
    while (n > 0) {
        mod = n % 10;
        n = n / 10;
        if (min > mod)
            min = mod;
        else
            min = mod;

  }
    std::cout << "Новое число: " << min << p << min;
    return 0;
}