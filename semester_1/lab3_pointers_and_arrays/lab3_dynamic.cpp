#include <iostream>
#include <cmath>
#include <random>
#include <cstdlib>
int number_of_elements;
void keyboard(int mas[]) {
    int i = 0;
    std::cout << "Enter elements of mas: ";
    for (; i < number_of_elements; i++) {
        if (!(std::cin >> mas[i])) {
            std::cout << "Error";
            delete[] mas;
            mas = nullptr;
            std::exit(1);
        }
    }
}
void random_enter(int mas[]) {
    std::cout << "Enter of random interval(the first number is start, the second is finish): ";
    int start, finish;
    if (!(std::cin >> start >> finish)) {
        std::cout << "Error";
        delete[] mas;
        mas = nullptr;
        std::exit(1);
    }
    int i = 0;
    std::mt19937 gen(45218965);
    int change_if = start + finish;
    if (start > finish) {
        start = finish;
        finish = change_if - start;
    }
    std::uniform_int_distribution<int> dist(start, finish);
    std::cout << "mas is: " << std::endl;
    for (i = 0; i < number_of_elements; i++) {
        int random_element = dist(gen);
        mas[i] = random_element;
        std::cout << mas[i] << std::endl;
    }
}
bool isPalindrome(int mas[], int start, int end) {
    while (start < end) {
        if (mas[start] != mas[end]) {
            return false;
        }
        start++;
        end--;
    }
    return true;
}
void findPalindrome(int mas[]) {
    int maxL = 0;
    int start = 0;
    for (int i = 0; i < number_of_elements; i++) {
        for (int j = i; j < number_of_elements; j++) {
            if (isPalindrome(mas, i, j) && (j - i + 1) > maxL) {
                maxL = j - i + 1;
                start = i;
            }
        }
    }
    std::cout << "Max palindrom is: \n";
    for (int i = 0; i < maxL; i++) {
        std::cout << mas[i + start] << std::endl;
    }
}
void product(int mas[]) {
    int first = -1;
    int second = -1;
    for (int i = 0; i < number_of_elements; i++) {
        if (mas[i] == 0) {
            first = i;
            break;
        }
    }
    if (first != -1) {
        for (int i = first + 1; i < number_of_elements; i++) {
            if (mas[i] == 0) {
                second = i;
                break;
            }
        }
    }
    if (first == -1 || second == -1) {
        std::cout << "No zerors in palindrom or only one" << std::endl;
        return;
    }
    int product = 1;
    bool between = false;
    for (int i = first + 1; i < second; i++) {
        product *= mas[i];
        between = true;
    }
    if (!between) {
        std::cout << "There is no elements program can product" << std::endl;
    }
    else {
        std::cout << "Product between zeroes is: " << product << std::endl;
    }
}
void rearrange(int mas[]) {
    int position = 0;
    for (int i = 0; i < number_of_elements; ++i) {
        if ((i + 1) % 2 == 1) { 
            int temp = mas[i];
            for (int j = i; j > position; --j) {
                mas[j] = mas[j - 1];
            }
            mas[position] = temp;
            ++position;
        }
    }
    std::cout << "Sorted mas is: \n";
    for (int i = 0; i < number_of_elements; i++) {
        std::cout << mas[i] << " ";
    }
}
int main() {
    std::cout << "Enter 0 if you want to enter elements manually or other number if random enter: ";
    double variants;
    if (!(std::cin >> variants)) {
        std::cout << "Try again";
        return 1;
    }
    std::cout << "Enter a number of elements in your array: ";
    if (!(std::cin >> number_of_elements) || number_of_elements <= 0) {
        std::cout << "Error";
        std::exit(1);
    }
    int* mas = new int[number_of_elements];
    if (!variants) {
        keyboard(mas);
    }
    else {
        random_enter(mas);
    }
    findPalindrome(mas);
    product(mas);
    rearrange(mas);
    delete[] mas;
    mas = nullptr;
    return 0;
}
