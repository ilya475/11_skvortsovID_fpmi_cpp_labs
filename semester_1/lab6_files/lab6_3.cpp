#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <cctype>
bool IsEmptyInputFile(std::ifstream& in);
int CountWordsInLine(const std::string& line);
void ReadData(const std::string& file_name, std::vector<std::string>& lines, std::vector<size_t>& count_words_in_line);
int MaxAmountOfWordsInLine(std::vector<size_t>& count_words_in_line);
void SaveBiggerLines(std::vector<size_t>& count_words_in_line, std::vector<std::string>& lines, const std::string& output_file);
bool IsEmptyInputFile(std::ifstream& in) {
	return (in.peek() == EOF);
}
void ReadData(const std::string& file_name, std::vector<std::string>& lines, std::vector<size_t>& count_words_in_line) {
	std::ifstream in(file_name);
	if (!in.is_open()) {
		throw ("Can not open " + file_name);
	}
	if (IsEmptyInputFile(in)) {
		in.close();
		throw (file_name + " is empty");
	}
	std::string line;
	while (getline(in, line)) {
		lines.push_back(line);
		count_words_in_line.push_back(CountWordsInLine(line));
	}
	in.close();
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
int MaxAmountOfWordsInLine(std::vector<size_t>& count_words_in_line) {
	int max = count_words_in_line[0];
	for (size_t i = 0; i < count_words_in_line.size(); ++i) {
		if (count_words_in_line[i] > max) {
			max = count_words_in_line[i];
		}
	}
	return max;
}
void SaveBiggerLines(std::vector<size_t>& count_words_in_line, std::vector<std::string>& lines, const std::string& output_file) {
	std::ofstream out("output.txt");
	if (!out.is_open()) {
		throw ("Can not open + " + output_file);
	}
	size_t printed_already_lines = 0;
	for (size_t i = 0; i < count_words_in_line.size(); ++i) {
		if (count_words_in_line[i] == MaxAmountOfWordsInLine(count_words_in_line)) {
				if (printed_already_lines < 10) {
					out << lines[i] << std::endl;
					++printed_already_lines;
				}
		}	
	}
	out.close();
}
int main()
{
	try {
		const std::string input_file{"input.txt"};
		const std::string output_file{ "otput.txt" };
		std::vector<std::string> lines;
		std::vector<size_t> count_words_in_line;
		ReadData(input_file, lines, count_words_in_line);
		SaveBiggerLines(count_words_in_line, lines, output_file);
		std::cout << output_file + " is done" << std::endl;
		return 0;
	}
	catch (std::string& msg) {
		std::cerr << msg;
		return 1;
	}
	catch (...) {
		std::cerr << "Unknown error";
		return 1;
	}
}