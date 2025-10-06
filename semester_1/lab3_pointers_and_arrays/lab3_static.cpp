#include <iostream>
#include<cmath>
#include<random>
#include<cstdlib>
const int all_el = 1000;
int i = 0;
int counter = 0;
double product = 1;
void acts_with_mas(double mas[], int number_of_elements) {
	std::cout << "Your mas is: ";
	for (i = 0; i < number_of_elements; i++) {
		std::cout << mas[i] << " ";
	}
	std::cout << std::endl;
	for (i = 0; i < number_of_elements; i++) {
		bool different = true;
		for (int j = 0; j < i; j++) {
			if (mas[i] == mas[j]) {
				different = false;
				break;
			}
		}
		if (different)
			counter++;
	}
	std::cout << "The number of different elements is: " << counter << std::endl;
	double first_element = mas[0];
	for (int i = 0; i < number_of_elements; i++) {
		if (std::abs(first_element) < std::abs(mas[i])) {
			first_element = mas[i];
		}
	}
	for (int i = 0; i < number_of_elements; i++) {
		if (mas[i] == first_element) {
			if (i == number_of_elements - 1) {
				std::cout << "Max element is last, thats why product is 1\n";
			}
			for (int j = i + 1; j < number_of_elements; j++) {
				product = product * mas[j];
			}
			break;
		}
	}
	std::cout << "The product of elements after the abs_max is :" << product << std::endl;
	if (product == 1) {
		std::cout << "Max element is last, thats why product is 1\n";
	}
	for (int j = 0; j < number_of_elements - 1; j++) {
		for (i = 0; i < number_of_elements - 1; i++) {
			if (mas[i] > mas[i + 1]) {
				double temp = mas[i];
				mas[i] = mas[i + 1];
				mas[i + 1] = temp;
			}
		}
	}
	std::cout << "Sorted mas is: \n";
	for (i = 0; i < number_of_elements; i++) {
		std::cout << mas[i] << std::endl;
	}
}
void keyboard(double mas[], int number_of_elements) {
	std::cout << "Enter elements mas in your arr: \n";
	for (; i < number_of_elements; i++) {
		if (!(std::cin >> mas[i])) {
			std::cout << "Error";
			std::exit(1);
		}
	}
	acts_with_mas(mas, number_of_elements);
}
void random_enter(double mas[], int number_of_elements) {
	std::cout << "Enter of random interval(the first number is start, the second is finish): ";
	double start, finish;
	if (!(std::cin >> start >> finish)) {
		std::cout << "Error";
		std::exit(1);
	}
	std::mt19937 gen(45218965);
	double change_if = start + finish;
	if (start > finish) {
		start = finish;
		finish = change_if - start;
	}
	std::uniform_real_distribution<double> dist(start, finish);
	for (i = 0; i < number_of_elements; i++) {
		double random_element = dist(gen);
		mas[i] = random_element;
	}
	acts_with_mas(mas, number_of_elements);
}
int main()
{
	double mas[all_el];
	int number_of_elements;
	std::cout << "Enter 0 if you want to enter elements manually or other number if random enter: ";
	double variants;
	if (!(std::cin >> variants)) {
		std::cout << "Try again";
		return 1;
	}
	std::cout << "Enter a number of elements in your array: ";
	if (!(std::cin >> number_of_elements) || number_of_elements > all_el || number_of_elements <= 0) {
		std::cout << "Error";
		std::exit(1);
	}
	if (!variants) {
		keyboard(mas, number_of_elements);
	}
	else {
		random_enter(mas, number_of_elements);
	}
	return 0;
}
