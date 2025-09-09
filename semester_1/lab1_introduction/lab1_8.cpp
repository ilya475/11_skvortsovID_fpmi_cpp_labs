

#include <iostream>
using namespace std;
int main()
{
	float a, b, c, d, e, f, g, h, i, j;
	setlocale(LC_ALL, "RU");
	cout << "Введите числа: ";
	cin >>a>>b>>c>>d>>e>>f>>g>>h>>i>>j;
	int p = 0;
	if (b < c && b < a)
		p++;
	if (c < b && c < d)
		p++; 
	if (d < c && d < e)
		p++;
	if (e < d && e < f)
		p++;
	if (f< e && f < g)
		p++;
	if (g < f && g < h)
		p++;
	if (h < g && h < i)
		p++;
	if (i < h && i < j)
		p++;
	cout << "Таких чисел: " << p;

	return 0;

 
}


