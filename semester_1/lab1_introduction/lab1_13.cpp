

#include <iostream>

int main()
{
	setlocale(LC_ALL, "RU");
	std::cout << "Введите количество чисел в последовательности Фибоначчи " << std::endl;
	int n,p;
	std::cin >> n;
	int fib_1 = 1;
	int fib_2 = 1;
	if (n == 0)
		std::cout << "0";
	else if (n == 1)
		std::cout << "0 1"; //начинаю нумеровку с 0-ого элемента
	else if (n < 0)
		std::cout << "n должно быть натуральным, попробуйте снова";
	else
	{
		std::cout << "0 1 1 ";
		for (int i = 3; i <= n; i++) {                //начинаем с 3, так как три первых числа последовательности уже известны 
			p = fib_1 + fib_2;
			std::cout << p << " ";
			fib_1 = fib_2;
			fib_2 = p;
		
		}


	}
		return 0;
}

