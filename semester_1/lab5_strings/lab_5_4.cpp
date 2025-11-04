#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
bool PrimeNumbers(int number_from_string) {
	if (number_from_string < 2) {
		return false;
	}
	int p = sqrt(number_from_string);
	for (int i = 2; i < p; i++) {
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
		std::string s1{};
		std::string s2{};
		std::string temp_symbol{};
		std::cout << "Enter string: " << std::endl;
		std::getline(std::cin, s1);
		for (size_t i = 0; i <= s1.size(); i++) {
			char one_symbol = s1[i];
			if (std::isdigit(one_symbol)) {
				temp_symbol += one_symbol;
			}
			else {
				if (!(temp_symbol.empty())) {
					if (temp_symbol.size() > 9) {
						throw "Too large number";
					}
					int number = std::stoi(temp_symbol);
					if (PrimeNumbers(number)) {
						if (!(s2.empty())) {
							s2 += temp_symbol + " ";
						}
						s2 += temp_symbol;
					}
					temp_symbol.clear();
				}
			}
		}
		if (!(temp_symbol.empty())) {
			int number = std::stoi(temp_symbol);
			if (PrimeNumbers(number)) {
				if (!s2.empty()) {
					s2 += temp_symbol + " ";
				}
				s2 += temp_symbol;
			}
		}
		if (s2.empty() == true) {
			throw "There are no prime numbers in your string, try again";
		}
		std::cout << s2;
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