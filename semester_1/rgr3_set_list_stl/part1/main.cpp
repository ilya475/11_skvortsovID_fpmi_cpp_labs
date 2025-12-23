#include <iostream>
#include <set>
#include <cmath>
int main()
{
	try {
		int number;
		std::cout << "Enter number you want to see primes before: ";
		if (!(std::cin >> number) || number < 2) {
			throw "Invalid input of entering number";
		}
		int bord = sqrt(number);
		std::set<int> numbers;
		for (int i = 2; i <= number; ++i) {
			numbers.insert(i);
		}
		for (int i = 2; i <= bord; ++i) {
			if (numbers.find(i) != numbers.end()) {
				for (int j = i * i; j <= number; j += i) {
					numbers.erase(j);
				}
			}
		}
		std::cout << "Primes before " << number << std::endl;
		for (int prime : numbers)
		{
			std::cout << prime << " ";
		}
		std::cout << std::endl;
		return 0;
	}
	catch (const char* msg) {
		std::cerr << msg;
		return 1;
	}
	catch (...) {
		std::cerr << "Unknown error";
		return 1;
	}
}
