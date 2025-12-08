#include "vector_impl.h"
Vector::Vector() {
    std::cout << "default\n";
}
Vector::Vector(size_t size) : size_(size), capacity_(size_), vector_(new int[size_]) {
    for (size_t i = 0; i < size_; i++) {
        vector_[i] = 0;
    }
}
Vector::Vector(const Vector& other)
    : size_(other.size_), capacity_(other.capacity_), vector_(new int[size_]) {
    std::cout << "Copy constructor\n";
    std::copy(other.vector_, other.vector_ + size_, vector_);
}
Vector::~Vector() {
    std::cout << "Distructor\n";
    delete[] vector_;
    vector_ = nullptr;
}
Vector& Vector::operator=(const Vector& other) {
    if (this == &other) {
        return *this;
    }
    Vector copy(other);
    Swap(copy);
    return *this;
}

void Vector::Swap(Vector& other) {
    if (this == &other) {
        return;
    }
    std::swap(capacity_, other.capacity_);
    std::swap(size_, other.size_);
    std::swap(vector_, other.vector_);
}
int& Vector::operator[](int index) {
    if (index < 0 || static_cast<size_t>(index) >= size_) {
        throw std::out_of_range("Index is out of vector");
    }
    return vector_[index];
}
int Vector::operator[](int index) const {
    if (index < 0 || static_cast<size_t>(index) >=size_ ) {
        throw std::out_of_range("Index is out of vector");
    }
    return vector_[index];
}
int& Vector::At(int index) {
    if (index < 0 || static_cast<size_t>(index) >= size_) {
        throw std::out_of_range("Index is out of vector");
    }
    return vector_[index];
}
const int& Vector::At(int index) const {
    if (index < 0 || static_cast<size_t>(index) >= size_) {
        throw std::out_of_range("Index is out of vector");
    }
    return vector_[index];
}
size_t Vector::Size() const {
    return size_;
}
size_t Vector::Capacity() const {
    return capacity_;
}

void Vector::Clear() {
    size_ = 0;
}
void Vector::PopBack() {
    if (size_ == 0) {
       throw std::out_of_range("Your vector doesn't already have any elemenst, that's why we can't delete last element");
    }
    --size_;
}
void Vector::PushBack(int new_element) {
    if (size_ == capacity_) {
        size_t new_capacity = (capacity_ == 0 ? 1 : capacity_ * 2);
        int* new_vector_ = new int[new_capacity];
        std::copy(vector_, vector_ + size_, new_vector_);
        delete[] vector_;
        vector_ = nullptr;
        vector_ = new_vector_;
        capacity_ = new_capacity;
    }
    vector_[size_] = new_element;
    ++size_;
}
void Vector::Reserve(size_t new_capacity_) {
    if (new_capacity_ > capacity_) {
        int* new_vector_ = new int[new_capacity_];
        std::copy(vector_, vector_ + size_, new_vector_);
        delete[] vector_;
        vector_ = nullptr;
        vector_ = new_vector_;
        capacity_ = new_capacity_;
    }
}
Vector::Vector(std::initializer_list<int> list): size_(list.size()), capacity_(size_), vector_(new int[size_]) {
    std::copy(list.begin(), list.end(), vector_);
}
std::ostream& operator<<(std::ostream& out, const Vector& vec) {
    if (vec.size_ == 0) {
        out << "[]";
        return out;
    }
    out << "[";
    for (size_t i = 0; i < vec.size_; ++i) {
        out << vec.vector_[i];
        if (i < vec.size_ - 1) {
            out << ", ";
        }
    }
    out << "]";
    return out;
}
