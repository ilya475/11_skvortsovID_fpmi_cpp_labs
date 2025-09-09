
#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "RU");
	int k;
	int res = 1;
	cout << "Введите число k:" << endl;
	cin >> k;
	if (k % 2 == 0)
		for (int i = 2; i <= k; i += 2)
			res = res * i;
	else  for (int i = 1; i <=k; i += 2)
		res = res * i;
		
	cout << "Результат равен: " << res;
	


	return 0;

}
