#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>
#include <set>
int Sum(const std::vector<int>& vec) {
    return std::accumulate(vec.begin(), vec.end(), 0);
}
int Size(const std::vector<int>& vec) {
    return static_cast<int>(vec.size());
}
int FindAmountOfCurrentAmount(const std::vector<int>& vec, int current) {
    return std::count(vec.begin(), vec.end(), current);
}
int BiggerThanCurrent(int current, const std::vector<int>& vec) {
    int count = 0;
    for (int i : vec) {
        if (i > current) {
            ++count;
        }
    }
    return count;
}
void ArithmeticMeanToZeros(std::vector<int>& vec) {
    if (vec.size() == 0) {
        throw "Can not / 0";
    }
    int average = Sum(vec) / static_cast<int>(vec.size());
    for (int i = 0; i < vec.size(); ++i) {
        if (vec[i] == 0) {
            vec[i] = average;
        }
    }
}
void AddFromInterval(std::vector<int>& vec, int start, int finish) {
    if (vec.empty()) {
     throw "Nothing to add to empty"; 
    } 
    if (start < 0 || finish < 0 || start >= vec.size() || finish >= vec.size()){ 
     throw "Invalid interval input";
    }
    if (finish < start) {
        std::swap(start, finish);
    }
    int interval_sum = std::accumulate(vec.begin() + start, vec.begin() + finish + 1, 0);
    for (int i = 0; i < vec.size(); ++i) {
        vec[i] += interval_sum;
    }
}
void ReplaceOddWithMinAndMax(std::vector<int>& vec) {
    int difference = *max_element(vec.begin(), vec.end()) - *min_element(vec.begin(), vec.end());
    for (int i = 0; i < vec.size(); ++i) {
        if (abs(vec[i]) % 2 != 0) {
            vec[i] = difference;
        }   
    }
}
void DeleteexceptFirst(std::vector<int>& vec) {
    std::set<int> known;
        for (size_t i = 0; i < vec.size(); ) {
            int module = abs(vec[i]);
            if (known.find(module) == known.end()) {
                known.insert(module);
                ++i;
            }
            else {
                vec.erase(vec.begin() + i);
            }
        }
}
void PrintVector(std::vector<int>& vec) {
    std::cout << "Your vector is:" << std::endl;
    for (int i : vec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}
int main() {
    try {
        std::vector<int> vec;
        std::cout << "Enter elements of your vector: " << std::endl;
        int num;
        while (std::cin >> num) {
            vec.push_back(num);
        }
        std::cout << "Vector: ";
        PrintVector(vec);
        std::cout << "Sum of elements: " << Sum(vec) << std::endl;
        std::cout << "Size: " << Size(vec) << std::endl;
        std::cout << "Amoumt of number 9: " << FindAmountOfCurrentAmount(vec, 9) << std::endl;
        std::cout << "Amount of numbers bigger than 9: " << BiggerThanCurrent(9, vec) << std::endl;

            std::vector<int> copy1 = vec;
            ArithmeticMeanToZeros(copy1);
            std::cout << "Vector with 0 elements + avg: " << std::endl;
            PrintVector(copy1);
            copy1.clear();

            std::vector<int> copy2 = vec;
            AddFromInterval(copy2, 5, 7);
            std::cout << "Vector with elements + sum of interval: " << std::endl;
            PrintVector(copy2);
            copy2.clear();
        
            std::vector<int> copy3 = vec;
            ReplaceOddWithMinAndMax(copy3);
            std::cout << "Vector with changed odd numbers: " << std::endl;
            PrintVector(copy3);
            copy3.clear();

            std::vector<int> copy4 = vec;
            DeleteexceptFirst(copy4);
            std::cout << "Vector without repeating: ";
            PrintVector(copy4);
            copy4.clear();
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
