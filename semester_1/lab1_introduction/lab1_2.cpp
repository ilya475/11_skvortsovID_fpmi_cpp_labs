

#include <iostream>

int main()

{
 setlocale(LC_ALL, "RU");
 int n;
 int pr =1;
 int sum = 0;
 std::cout << "Введите число n\n";
 std::cin >> n;
 for (int i = 1; i <= n; i++)
 {

	 if (i % 2 == 0) {
		 sum += i;
	 }
	 if (i % 2 != 0) {
		 pr *= i;
	 }
 }
 std::cout << "Сумма четных чисел промежутка: " << sum<<std::endl;
 std::cout << "Произведение нечётных чисел промежутка: " << pr;


	 return 0;
}
