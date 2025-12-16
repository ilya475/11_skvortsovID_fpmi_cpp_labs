#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cctype>
bool IsEmptyInputFile(std::ifstream& in);
int CountWordsInLine(const std::string& line);
int MaxAmountOfWordsInLine(const std::string& file_name);
void SaveBiggerLines(const std::string& input_file, const std::string& output_file, int max_words);

bool IsEmptyInputFile(std::ifstream& in) {
    return in.peek() == EOF;
}
int CountWordsInLine(const std::string& line) {
    int words_in_each_line = 0;
    std::istringstream iss(line);
    std::string word;
    while (iss >> word) {
        ++words_in_each_line;
    }
    return words_in_each_line;
}
int MaxAmountOfWordsInLine(const std::string& file_name) {
    std::ifstream in(file_name);
    if (!in.is_open()) {
        throw ("Can not open " + file_name);
    }
    if (IsEmptyInputFile(in)) {
        throw (file_name + " is empty");
    }
    std::string line;
    int max_words = 0;
    while (std::getline(in, line)) {
        int words = CountWordsInLine(line);
        if (words > max_words) {
            max_words = words;
        }
    }
    return max_words;
}
void SaveBiggerLines(const std::string& input_file, const std::string& output_file, int max_words) {
    std::ifstream in(input_file);
    if (!in.is_open()) {
        in.close();
        throw ("Cannot open " + input_file);
    }
    std::ofstream out(output_file);
    if (!out.is_open()) {
        out.close();
        throw ("Cannot open " + output_file);
    }
    std::string line;
    size_t already_printed = 0;
    while (std::getline(in, line) && already_printed < 10) {
        if (CountWordsInLine(line) == max_words) {
            out << line << std::endl;
            ++already_printed;
        }
    }
    in.close();
    out.close();
}
int main() {
    try {
        const std::string input_file{ "input.txt" };
        const std::string output_file{ "output.txt" };
        int max_words = MaxAmountOfWordsInLine(input_file);
        SaveBiggerLines(input_file, output_file, max_words);
        std::cout << output_file + " is done" << std::endl;
        return 0;
    }
    catch (std::string& msg) {
        std::cerr << msg << std::endl;
        return 1;
    }
    catch (...) {
        std::cerr << "Unknown error" << std::endl;
        return 1;
    }
}
