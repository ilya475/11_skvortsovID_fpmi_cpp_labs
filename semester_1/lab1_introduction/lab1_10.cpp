#include <iostream>

int main()
{
	setlocale(LC_ALL, "RU");
	int n, mod_1, mod_2, sum_1, sum_2;
	sum_1 = 0;
	sum_2 = 0;
	std::cout << "Введите шестизначное число" << std::endl;
	std::cin >> n;
	for (int i = 1; i <= 3; i++) {
		mod_1 = n % 10;
		n = n / 10;
		sum_1 += mod_1;
	}
	for (int j = 1; j <= 3; j++) {
		mod_2 = n % 10;
		n = n / 10;
		sum_2 += mod_2;
	}
	if (sum_1 == sum_2)
		std::cout << "Это счастливое число";
	else 
		std::cout << "Это число не является счастливым";
	return 0;
}
