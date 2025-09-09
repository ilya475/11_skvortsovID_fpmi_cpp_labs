

#include <iostream>
using namespace std;
int main()
{
setlocale(LC_ALL, "RU");
int num_1, num_2;
cout << "Введите первое число: ";
cin >> num_1;
cout << "Введите второе число: ";
cin >> num_2;
while (num_2 > 0) 
{
	int r = num_1 % num_2;
	num_1 = num_2;
	num_2 = r; // m - НОД по Евклиду
}
for (int i = 1; i <= num_1; i++) {
	if (num_1 % i == 0)
		cout << "Один из общих делителей чисел равен: " << i << endl;
}
	return 0;
}
