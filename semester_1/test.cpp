#include <iostream>
#include <cmath>
const int N = 1000;
void bubblesort(int* mas, int number_of_elements) {
    for (int i = 0; i < number_of_elements - 1; i++) {
        for (int j = 0; j < number_of_elements - 1; j++) {
            if (abs(mas[j]) > abs(mas[j + 1])) {
                int temp = mas[j];
                mas[j] = mas[j + 1];
                mas[j + 1] = temp;
            }
        }
    }
}
void printmas(int* mas, int number_ofelements) {
    for (int i = 0; i < N; i++) {
        std::cout << mas[i] << " ";
    }
}
int main()
{
    int number_of_elements;
    int mas[N];
    std::cout << "Enter number of elements: ";
    std::cin >> number_of_elements;
    for (int i = 0; i < number_of_elements; i++) {
        std::cin >> mas[i];
    }
    bubblesort(mas, number_of_elements);
    printmas(mas, number_of_elements);
    return 0;
}

