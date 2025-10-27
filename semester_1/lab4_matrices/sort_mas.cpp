#include <iostream>
#include <random>
#include <algorithm>
int** give_memory(int row, int column);
void enter_mas(int** mas, int row, int column);
void print_array(int** mas, int row, int column);
void bublesort(int** mas, int row, int column);
void countsort(int* rows, int size_of_row, int sort);
void countsort_rows(int** mas, int row, int column);
int how_to_sort(int** mas, int row);
//void mergesort(int** mas, int row, int column);
void insertsort(int** mas, int row, int column);
void delete_memory(int** mas, int row);
int how_to_sort(int** mas, int row) {
	int kind_of_type_of_sort;
	std::cout << "If you want from the least to the biggset - 0; differently - 1: ";
	if (!(std::cin >> kind_of_type_of_sort) || kind_of_type_of_sort < 0) {
		std::cout << "Error";
		delete_memory(mas, row);
		exit(1);	
	}
	if (kind_of_type_of_sort == 0) {
		return 0;
	}
	else if (kind_of_type_of_sort == 1) {
		return 1;
	}
	else {
		std::cout << "Error";
		delete_memory(mas, row);
		exit(1);
	}
}
void keyboard_enter(int** mas, int row, int column) {
	int kind_of_sort;
	std::cout << "If you want buble sort - 0; count - 1; insert - 2: ";
	std::cin >> kind_of_sort;
	switch (kind_of_sort) {
	case 0:enter_mas(mas, row, column);
		print_array(mas, row, column);
		bublesort(mas, row, column);
		break;
	case 1:enter_mas(mas, row, column);
		print_array(mas, row, column);
		countsort_rows(mas,row,column);
		break;

	case 2:
		enter_mas(mas, row, column);
		print_array(mas, row, column);
		insertsort(mas, row, column);
		break;
	default:
		std::cout << "Error";
		delete_memory(mas, row);
	}
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
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			int random_element = dist(gen);
			mas[i][j] = random_element;
		}
	}
	int kind_of_sort;
	std::cout << "If you want buble sort - 0; count - 1; insert - 2: ";
	std::cin >> kind_of_sort;
	switch (kind_of_sort) {
	case 0:
		print_array(mas, row, column);
		bublesort(mas, row, column);
		break;
	case 1:
		print_array(mas, row, column);
		countsort_rows(mas, row, column);
		break;

	case 2:
		
		print_array(mas, row, column);
		insertsort(mas, row, column);
		break;
	default:
		std::cout << "Error";
		delete_memory(mas, row);
	}
}
int** give_memory(int row, int column) {
	int** mas = new int* [row];
	for (int i = 0; i < row; i++) {
		mas[i] = new int[column];
	}
	return mas;
}
void enter_mas(int** mas, int row, int column) {
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
void bublesort(int** mas, int row, int column) {
	int sort = how_to_sort(mas, row);
	for (int i = 0; i < row; i++) {
		for (int k = 0; k < column - 1; k++) {
			for (int j = 0; j < column - 1; j++) {
				if ( sort == 0){
					if (mas[i][j] > mas[i][j + 1]) {
						int temp = mas[i][j];
						mas[i][j] = mas[i][j + 1];
						mas[i][j + 1] = temp;
					}
				}
				else {
					if (mas[i][j] < mas[i][j + 1]) {
						int temp = mas[i][j];
						mas[i][j] = mas[i][j + 1];
						mas[i][j + 1] = temp;
					}
				}
			}
		}
	}
	print_array(mas, row, column);
}
void insertsort(int** mas, int row, int column) {
	int sort = how_to_sort(mas, row);
	for (int i = 0; i < row; i++) {
		for (int j = 1; j < column; j++) {
			if(sort == 0){
				for (int k = j; (k > 0) && (mas[i][k - 1] > mas[i][k]); k--) {
					std::swap(mas[i][k], mas[i][k - 1]);
				}
			}
			else {
				for (int k = j; (k > 0) && (mas[i][k - 1] < mas[i][k]); k--) {
					std::swap(mas[i][k], mas[i][k - 1]);
				}
			}
		}
	}
	print_array(mas, row, column);
}
void countsort_rows(int** mas, int row, int column) {
	int sort = how_to_sort(mas, row);
	for (int i = 0; i < row; i++) {
		countsort(mas[i], column, sort);
	}
	print_array(mas, row, column);
}
void countsort(int* row, int size_of_row, int sort) {
	int min_in_row = row[0];
	int max_in_row = row[0];
	for (int i = 0; i < size_of_row; i++) {
		if (row[i] < min_in_row) {
			min_in_row = row[i];
		}
		if (row[i] > max_in_row) {
			max_in_row = row[i];
		}
	}
	int length_of_count_mas = (max_in_row - min_in_row) + 1;
	int* count_mas = new int[length_of_count_mas]{};
	for (int i = 0; i < size_of_row; i++) {
		count_mas[row[i] - min_in_row]++;
	}
	int index_in_sortedmas = 0;
	if (sort == 0) {
		for (int i = 0; i < length_of_count_mas; i++) {
			for (; count_mas[i] > 0; count_mas[i]--) {
				row[index_in_sortedmas] = i + min_in_row;
				index_in_sortedmas++;
			}
		}
	}
	else {
		for (int i = length_of_count_mas-1; i >=0; i--) {
			for (; count_mas[i] > 0; count_mas[i]--) {
				row[index_in_sortedmas] = i + min_in_row;
				index_in_sortedmas++;
			}
		}

	}
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
			keyboard_enter(mas, row, column);
		}
		else {
			random_enter(mas, row, column);
		}
		delete_memory(mas, row);
	
	return 0;
}