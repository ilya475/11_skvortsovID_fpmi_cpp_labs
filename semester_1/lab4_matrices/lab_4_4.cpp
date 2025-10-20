#include <iostream>
#include <random>
int** give_memory(int row, int column);
void enter_mas(int** mas, int row, int column);
void print_array(int** mas, int row, int column);
void find_product_with_zero(int** mas, int row, int column);
void bublesort(int** mas, int row, int column);
void delete_memory(int** mas, int row);


void keyboard_enter(int** mas, int row, int column) {
enter_mas(mas, row, column);
print_array(mas, row, column);
find_product_with_zero(mas, row, column);
bublesort(mas, row, column);
}
void random_enter(int** mas, int row, int column) {
std::cout << "Enter of random interval(the first number is start, the second is finish): ";
int start, finish;
if (!(std::cin >> start >> finish)) {
	std::cout << "Error";
	delete_memory(mas, row);
	exit(1);
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
for (int i = 0; i < row; i++) {
	for (int j = 0; j < column; j++) {
		int random_element = dist(gen);
		mas[i][j] = random_element;
	}
}
print_array(mas, row, column);
find_product_with_zero(mas, row, column);
bublesort(mas, row, column);
}
int** give_memory(int row, int column) {
int** mas = new int* [row];
for (int i = 0; i < row; i++) {
	mas[i] = new int[column];
}
return mas;
}
void enter_mas(int**mas,int row,int column) {
std::cout << "Enter your mas: " << "\n";
for (int i = 0; i < row; i++) {
	for (int j = 0; j < column; j++) {
		if (!(std::cin >> mas[i][j])) {
			std::cout << "Error";
			delete_memory(mas, row);
			exit(1);
		}
	}
}
}
void print_array(int** mas, int row, int column) {
std::cout << "Your mas: " << "\n";
for (int i = 0; i < row; i++) {
	for (int j = 0; j < column; j++) {
		std::cout << mas[i][j] << "  ";
	}
	std::cout << std::endl;
}
}
void find_product_with_zero(int** mas, int row, int column) {
int sum = 0;
for (int j = 0; j < column; j++) {
	int count_to_do_break = 0;
	for (int i = 0; i < row; i++) {
		if (mas[i][j] == 0) {
			count_to_do_break++;
		}
		if(count_to_do_break == 1){
			for (int k = 0; k < row; k++) {
				sum += mas[k][j];
			}
			break;
		}
	}
}
if (sum == 0) {
	std::cout << "No rows with zeroes" << std::endl;
	return;
}
std::cout << "Sum of elements with rows where there is 0 is: " << sum << std::endl;
}
void bublesort(int** mas, int row, int column) {					
	for (int i = 1; i < row; i += 2) {
		for (int k = 0; k < column - 1; k++) {
			for (int j = 0; j < column - 1; j++) {
				if (mas[i][j] > mas[i][j + 1]) {
					int temp = mas[i][j];
					mas[i][j] = mas[i][j + 1];
					mas[i][j + 1] = temp;
				}
			}
		}
	}
	for (int i = 0; i < row; i += 2) {
		for (int k = 0; k < column - 1; k++) {
			for (int j = 0; j < column - 1; j++) {
				if (mas[i][j] < mas[i][j + 1]) {
					int temp = mas[i][j];
					mas[i][j] = mas[i][j + 1];
					mas[i][j + 1] = temp;
				}
			}
		}
	}
print_array(mas, row, column);
}
void delete_memory(int** mas, int row) {
	for (int i = 0; i < row; i++) {
		delete[] mas[i];
		mas[i] = nullptr;
	}
	delete[] mas;
	mas = nullptr;
}
int main()
{
int row;
int column;
std::cout << "Enter number of rows for the first and columns for the second: ";
if (!(std::cin >> row) || !(std::cin >> column) || (row <= 0) || (column <= 0)) {
	std::cout << "Error";
	return 1;
}
int** mas = give_memory(row, column);
std::cout << "Enter 0 if you want to enter elements manually or other number if random enter: ";
double variants;
if (!(std::cin >> variants)) {
	std::cout << "Try again";
	delete_memory(mas, row);
	return 1;
}
if (!variants) {
	keyboard_enter(mas,row,column);
}
else {
	random_enter(mas, row, column);
}
delete_memory(mas, row);
return 0;
}