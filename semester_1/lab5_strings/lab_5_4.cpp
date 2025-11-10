#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
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
int main()
{
	try {
		int number;
		std::string enter_string;
		std::string result_string;
		std::string temp_symbol;
		std::cout << "Enter string: " << std::endl;
		std::getline(std::cin, enter_string);
		for (size_t i = 0; i < enter_string.size(); i++) {
			if (std::isdigit(enter_string[i])) {
				temp_symbol += enter_string[i];
			}
			else {
				if (!(temp_symbol.empty())) {
					temp_symbol.erase(0, temp_symbol.find_first_not_of('0'));
					if (temp_symbol.empty()) {
						temp_symbol = "0";
					}
					if (temp_symbol.size() > 10 || (temp_symbol.size() == 10 && temp_symbol > "2147483647")) {
						throw "There is too large number in your string";
					}
					int number = std::stoi(temp_symbol);
					if (PrimeNumbers(number)) {
						if (!(result_string.empty())) {
							result_string += " ";
						}
						result_string += temp_symbol;
					}
					temp_symbol.clear();
				}
			}
		}
		if (!(temp_symbol.empty())) {
			temp_symbol.erase(0, temp_symbol.find_first_not_of('0'));
			if (temp_symbol.empty()) {
				temp_symbol = "0";
			}
			if (temp_symbol.size() > 10 || (temp_symbol.size() == 10 && temp_symbol > "2147483647")) {
				throw "There is too large number in your string";
			}
			int number = std::stoi(temp_symbol);
			if (PrimeNumbers(number)) {
				if (!result_string.empty()) {
					result_string += " ";
				}
				result_string += temp_symbol;
			}
		}
		if (result_string.empty() == true) {
			throw "There are no prime numbers in your string, try again";
		}
		std::cout << "Your new string with prime numbers: " << result_string << std::endl;
		return 0;
	}
	catch (const char* msg) {
		std::cout << msg;
		return 1;
	}
	catch (...) {
		std::cout << "Unknown error";
	}
}
