
#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "RU");
	cout << "Введите n\n";
	int num,sum;
	cin >> num;
	sum = (2 + (num - 1) * 2) * num / 2; //арифметическая прогрессия с d=2
	cout << "Сумма равна: "<< sum;
	return 0;
}

