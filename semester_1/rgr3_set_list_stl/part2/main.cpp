#include <iostream>
#include <list>
#include <algorithm>
#include <string>
#include <fstream>
#include <sstream>
struct Author {
    std::string surname;
    std::string name;
    std::string middle_name;
    bool operator<(const Author& rhs) const {
        return surname < rhs.surname;
    }
};
struct Book {
    int id;
    std::string book_name;
    int year;
    std::list<Author> all_authors;
    bool operator<(const Book& rhs) const {
        return book_name < rhs.book_name;
    }
};
class Library {
    std::list<Book> books;
    bool IsEmptyFile(std::istream& in) {
        return in.peek() == EOF;
    }
public:
    void ReadDataFromFile(const std::string& file_name) {
        std::ifstream in(file_name);
        if (!in.is_open()) {
            in.close();
            throw "Can not open input file";
        }
        if (IsEmptyFile(in)) {
            in.close();
            throw "Your input file is empty";
        }
        std::string line;
        while (getline(in, line)) {
            std::istringstream iss(line);
            Book book;
            Author author;
            iss >> book.id >> book.book_name >> book.year;
            while (iss >> author.surname >> author.name >> author.middle_name) {
                book.all_authors.push_back(author);
            }
            book.all_authors.sort();
            books.push_back(book);
        }
        books.sort();
        in.close();
    }
    void AddBookToList(const Book& book_to_add) {
        books.push_back(book_to_add);
        books.sort();
    }
    bool DeleteBookFromListByOnlyName(const std::string& book_to_delete) {
        for (auto i = books.begin(); i != books.end();) {
            if (i->book_name == book_to_delete) {
               i = books.erase(i);
                std::cout << book_to_delete + " Has successfully been deleted\n";
                return true;
            }
            else {
                ++i;
            }
        }
        std::cout << "There is no book with title" + book_to_delete << std::endl;
        return false;
    }
    void SearchBookByNameOfTheBook(const std::string& name_of_the_book) const {
        bool flag = false;
        for(const auto& each_book: books)
            if (each_book.book_name == name_of_the_book) {
                PrintInformation(each_book);
                flag = true;
            }
        if (!flag) {
            std::cout << "There is no book with a name " + name_of_the_book;
        }
        }
    void SearchBookByTheNameOfAuthor(const std::string& surname) {
        bool flag = false;
       for (const auto& each_book : books) {
           for (const auto& each_author : each_book.all_authors) {
               if (each_author.surname == surname) {
                   PrintInformation(each_book);
                   flag = true;
}
           }
            }
       if (!flag) {
           std::cout << "There is no book with an author surname " + surname;
       }
        }
    void AddAuthor(const std::string& name_of_the_book, const Author& author) {
        for (auto& each_book : books) {
            if (each_book.book_name == name_of_the_book) {
                each_book.all_authors.push_back(author);
                each_book.all_authors.sort();
            }
        }
    }
    bool DeleteAuthor(const std::string& author_to_delete,
        const std::string& book_to_delete_from) {
        for (auto& each_book : books) {
            if (each_book.book_name == book_to_delete_from) {
                for (auto i = each_book.all_authors.begin(); i != each_book.all_authors.end(); ++i) {
                    if (i->surname == author_to_delete) {
                        each_book.all_authors.erase(i);
                        std::cout << "Author " << author_to_delete<< " has successfully been deleted from book "<< book_to_delete_from << std::endl;
                        return true;
                    }
                }
            }
        }
        std::cout << "We have not found information about book " << book_to_delete_from << " or author " << author_to_delete << std::endl;
        return false;
    }
    void PrintInformation(const Book& book) const {
        std::cout << "Your book id is: " << book.id << std::endl;
        std::cout << "Your book name is: " << book.book_name << std::endl;
        std::cout << "Your book year is: " << book.year << std::endl;
        std::cout << "Author is: ";
        for (const auto& each_author : book.all_authors) {
            std::cout << each_author.surname << " " << each_author.name << " " << each_author.middle_name << std::endl;
        }
        }
};

int main()
{
    try {
        Library library_bsu;
        library_bsu.ReadDataFromFile("input.txt");
        library_bsu.SearchBookByNameOfTheBook("Math");
        library_bsu.SearchBookByTheNameOfAuthor("Rasmislovich");
        Book newBook;
        newBook.id = 111;
        newBook.book_name = "C++";
        newBook.year = 2025;
        Author author = { "Konah", "Valentina", "Vladimirovna" };
        newBook.all_authors.push_back(author);
        library_bsu.AddBookToList(newBook);
        library_bsu.DeleteBookFromListByOnlyName("Math");
        Author AddAuthor = { "Skvortsov", "Ilya", "Dzmitievich" };
        library_bsu.AddAuthor("C++", AddAuthor);
        library_bsu.SearchBookByTheNameOfAuthor("Skvortsov");
        library_bsu.DeleteAuthor("Skvortsov", "C++");
        library_bsu.SearchBookByTheNameOfAuthor("Konah");
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
