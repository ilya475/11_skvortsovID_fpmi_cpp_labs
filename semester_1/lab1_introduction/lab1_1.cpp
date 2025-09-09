#include <iostream>

int main()
{
	setlocale(LC_ALL, "RU");
	std::cout << "Введите нулевой член прогрессии, верхнюю границу прогрессии, разность прогрессии\n";
	int a_0, n, d;
	std::cin >> a_0 >> n >> d;
	for (int i = a_0; i <= n; i += d)
	{
		if (i % 3 == 0)
			std::cout << "Член прогресcии кратный трём: " << i << std::endl;
	}

	return 0;
}



