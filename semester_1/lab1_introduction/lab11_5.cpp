#include <iostream>

int main()
{
	setlocale(LC_ALL, "RU");
	int num_1, num_2;
	std::cout << "Введите первое и второе число через пробел: ";
	std::cin >> num_1 >> num_2;
	if (!std::cin >> num_1 >> num_2 || num_1 < 0 || num_2 < 0 || num_1,num_2==0 ) {
		std::cout << "Ошибка";
		std::exit(1);
	}
	while (num_2 > 0)
	{
		int r = num_1 % num_2;
		num_1 = num_2;
		num_2 = r; // num_1 - НОД по Евклиду
	}
	for (int i = 1; i <= num_1; i++) {
		if (num_1 % i == 0)
			std::cout << "Один из общих делителей чисел равен: " << i << std::endl; // все общие делители чисел
	}

	return 0;
}
