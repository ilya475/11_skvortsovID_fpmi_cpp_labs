#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

bool PrimeNumbers(int number_from_string);

std::string ProccessNumber(const std::string& line) {
    std::string num = line;
    num.erase(0, num.find_first_not_of('0'));
    if (num.empty()) {
        num = "0";
    }
    if (num.size() > 10 || (num.size() == 10 && num > "2147483647")) {
        throw "There is too large number in your string";
    }
    return num;
}

void ProcessOneNumber(const std::string& line, std::string& result_string) {
    if (line.empty()) {
        return;
    }
    std::string proccesed_word = ProccessNumber(line);
    int number = std::stoi(proccesed_word);
    if (PrimeNumbers(number)) {
        if (!result_string.empty()) {
            result_string += " ";
        }
        result_string += proccesed_word;
    }
}

void ProcesString(const std::string& enter_string) {
    std::string result_string;
    std::string temp_symbol;

    for (size_t i = 0; i < enter_string.size(); ++i) {
        if (std::isdigit(enter_string[i])) {
            temp_symbol += enter_string[i];
        }
        else {
            ProcessOneNumber(temp_symbol, result_string);
            temp_symbol.clear();
        }
    }

    ProcessOneNumber(temp_symbol, result_string);

    if (result_string.empty()) {
        throw "There are no prime numbers in your string, try again";
    }

    std::cout << "Your new string with prime numbers: " << result_string << std::endl;
}

bool PrimeNumbers(int number_from_string) {
    if (number_from_string < 2) {
        return false;
    }
    int limit = sqrt(number_from_string);
    for (int i = 2; i <= limit; i++) {
        if (number_from_string % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    try {
        std::string enter_string;
        std::cout << "Enter string: " << std::endl;
        std::getline(std::cin, enter_string);
        ProcesString(enter_string);
        return 0;
    }
    catch (const char* msg) {
        std::cout << msg;
        return 1;
    }
    catch (...) {
        return 1;
        std::cout << "Unknown error";
    }
}
