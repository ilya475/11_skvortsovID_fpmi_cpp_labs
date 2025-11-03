#include <iostream>
#include <random>
int** give_memory(int row, int column);
void enter_mas(int** mas, int row, int column);
void print_array(int** mas, int row, int column);
void find_sum_with_zero_in_column(int** mas, int row, int column);
void bublesort(int** mas, int row, int column);
void delete_memory(int** mas, int row);


void keyboard_enter(int** mas, int row, int column) {
    enter_mas(mas, row, column);
    print_array(mas, row, column);
    find_sum_with_zero_in_column(mas, row, column);
    bublesort(mas, row, column);
}
void random_enter(int** mas, int row, int column, std::mt19937& gen) {
    std::cout << "Enter of random interval(the first number is start, the second is finish): ";
    int start, finish;
    if (!(std::cin >> start >> finish)) {
       throw"Invalid input of entering interval";
    }
    int i = 0;
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
    print_array(mas, row, column);
    find_sum_with_zero_in_column(mas, row, column);
    bublesort(mas, row, column);
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
            if (mas[i][j] == 0) {
            }
            if (!(std::cin >> mas[i][j])) {
                 throw"invalid input of entering elements of matrix";
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
void find_sum_with_zero_in_column(int** mas, int row, int column) {
    int count_zeroes = 0;
    int sum = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            if (mas[i][j] == 0) {
                count_zeroes++;
            }
        }
    }
    if (count_zeroes == 0) {
        std::cout << "No columns with zeroes" << std::endl;
        return;
    }
    for (int j = 0; j < column; j++) {
        int count_to_do_break = 0;
        for (int i = 0; i < row; i++) {
            if (mas[i][j] == 0) {
                count_to_do_break++;
            }
            if (count_to_do_break == 1) {
                for (int k = 0; k < row; k++) {
                    sum += mas[k][j];
                }
                break;
            }
        }
    }
   std::cout << "Sum of elements with columns where there is 0 is: " << sum << std::endl; 
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
    std::random_device rd;
    std::mt19937 gen(rd());
    int row;
    int column;
    std::cout << "Enter number of rows for the first and columns for the second: ";
    if (!(std::cin >> row >> column) || (row <= 0) || (column <= 0)) {
        std::cout << "Invalid input of entering number of rows and columns";
        return 1;
    }
    int** mas = give_memory(row, column);
    std::cout << "Enter 0 if you want to enter elements manually or other number if random enter: ";
    double variants;
    if (!(std::cin >> variants)) {
        std::cout << "Invalid input of entering number for filling matrix ";
        delete_memory(mas, row);
        return 1;
    }
    try {
        if (!variants) {
            keyboard_enter(mas, row, column);
        }
        else {
            random_enter(mas, row, column, gen);
        }
    }
    catch (const char* msg) {
        std::cout << msg;
        delete_memory(mas, row);
        return 1;
    }
    catch (...) {
        std::cout << "Unknown error";
        delete_memory(mas, row);
        return 1;
    }        
    delete_memory(mas, row);
    return 0;
}
