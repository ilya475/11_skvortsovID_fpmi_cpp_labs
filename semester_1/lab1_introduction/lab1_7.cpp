

#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "RU");
	cout << "Введите количество дробных чисел: ";
	int n;
	cin >> n;
	double k;
	double sum =0, min = 0, max = 0;// k - каждое вводимое в цикле число
	int i = 0;
	while (n > 0) 
	{
		i++;
		cout << "Введите число последовательности: ";
		cin >> k;
		if (k > max) max = k;
		else if (k < max) min = k;
		sum += k;
		n--;
	}
	cout<< "Среднее арифметическое чисел: " << sum / i << endl<<"Минимальное из чисел: " << min<< endl <<"Максимальное из чисел: " << max;
	


	

	return 0;
}

