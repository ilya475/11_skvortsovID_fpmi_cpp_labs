#include <iostream>

int main()
{
	setlocale(LC_ALL, "RU");
	int k;
	int res = 1;
	std::cout << "Введите число k:" << std::endl;
	std::cin >> k;
	if (!std::cin >> k || k < 1) {
		std::cout << "Ошибка";
		std::exit(1);
	}
	if (k % 2 == 0) {
		for (int i = 2; i <= k; i += 2)
			res = res * i;
	}
	else {
		for (int i = 1; i <= k; i += 2)
			res = res * i;
	}
	std::cout << "Результат равен: " << res;

	return 0;

}
