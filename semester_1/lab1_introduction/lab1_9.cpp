

#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_ALL, "RU");
    cout << "Введите четырёхзначное натуральное число: ";
    int n,b,c,d,e;
    cin >> n;
    b = n % 100;
    c = (n / 100) % 10;
    d = (n / 100) / 10;
    e = ((n / 100) % 10) *10 + (n / 100) / 10;
    if (b == e)
        cout << "Это палиндром";
    else cout << "Увы, это не палиндром";
    return 0;

    
}

