#pragma once
#include <iostream>
#include <algorithm>
#include <exception>
#include <initializer_list>
class Vector {
private:
    size_t size_ = 0;
    size_t capacity_ = 0;
    int* vector_ = nullptr;
public:
    Vector();
    Vector(size_t size);
    Vector(const Vector& other);
    ~Vector();
    void Swap(Vector& other);
    int& operator[](int index);
    int operator[](int index) const;
    Vector& operator=(const Vector& other);
    int& At(int index);
    const int& At(int index) const;
    size_t Size() const;
    size_t Capacity() const;
    void Clear();
    void PopBack();
    void PushBack(int new_element);
    void Reserve(size_t newcapacity_);
    Vector(std::initializer_list<int> list);
    friend std::ostream& operator<<(std::ostream& out, const Vector& vec);
};
