#include <iostream>

int main()
{
    setlocale(LC_ALL, "RU");
    std::cout << "Введите натуральное число: ";
    int num_n, n, mod;
    std::cin >> n;
    int min_num = 9; //начинаем с максимальной цифры
    if (!std::cin >> n || n<=0) {
        std::cout << "Error";
    std::exit(1);
    }
    num_n = n; // в num_n мы записываем число, равное n
    while (n > 0) {
        mod = n % 10;
        if (mod !=0 && mod < min_num)
            min_num = mod;
        n /= 10;

  }
    
    std::cout << "Новое число: " << min_num << num_n << min_num;
    return 0;
}