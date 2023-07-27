/*
* Program: mystring.cpp (Assignment 12P: Classes with DM 2)
* Author: Matt Aaron Magnaye
* Instructor: Professor David Harden
* Date: 07/27/2023
* Description: Refinements to the last class that I wrote (Assignment 11P)
*/
#include "mystring.h"
#include <cstring>

namespace cs_mystring {

    // Constructors
    MyString::MyString() : str_(nullptr), size_(0) {}

    MyString::MyString(const char* str) {
        size_ = strlen(str);
        str_ = new char[size_ + 1];
        strcpy(str_, str);
    }

    MyString::MyString(const MyString& other) {
        size_ = other.size_;
        str_ = new char[size_ + 1];
        strcpy(str_, other.str_);
    }

    // Destructor
    MyString::~MyString() {
        delete[] str_;
    }

    // Assignment operator
    MyString& MyString::operator=(const MyString& other) {
        if (this != &other) {
            delete[] str_;
            size_ = other.size_;
            str_ = new char[size_ + 1];
            strcpy(str_, other.str_);
        }
        return *this;
    }

    // Accessors
    int MyString::length() const {
        return size_;
    }

    const char* MyString::c_str() const {
        return str_;
    }

    // Read function
    void MyString::read(std::istream& in, char delimiter) {
        char buffer[MAX_INPUT_SIZE];
        in.getline(buffer, MAX_INPUT_SIZE, delimiter);
        *this = buffer;
    }

    // Concatenation operators
    MyString operator+(const MyString& lhs, const MyString& rhs) {
        MyString result;
        result.size_ = lhs.size_ + rhs.size_;
        result.str_ = new char[result.size_ + 1];
        strcpy(result.str_, lhs.str_);
        strcat(result.str_, rhs.str_);
        return result;
    }

    MyString& MyString::operator+=(const MyString& rhs) {
        *this = *this + rhs;
        return *this;
    }

    // Extraction operator
    std::istream& operator>>(std::istream& in, MyString& obj) {
        char buffer[MyString::MAX_INPUT_SIZE];
        in >> buffer;
        obj = buffer;
        return in;
    }

    // Comparison operators
    bool operator==(const MyString& lhs, const MyString& rhs) {
        return strcmp(lhs.str_, rhs.str_) == 0;
    }

    bool operator!=(const MyString& lhs, const MyString& rhs) {
        return !(lhs == rhs);
    }

    bool operator<(const MyString& lhs, const MyString& rhs) {
        return strcmp(lhs.str_, rhs.str_) < 0;
    }

    bool operator<=(const MyString& lhs, const MyString& rhs) {
        return !(rhs < lhs);
    }

    bool operator>(const MyString& lhs, const MyString& rhs) {
        return rhs < lhs;
    }

    bool operator>=(const MyString& lhs, const MyString& rhs) {
        return !(lhs < rhs);
    }

    // Overloaded subscript operator
    char& MyString::operator[](int index) {
        return str_[index];
    }

    const char& MyString::operator[](int index) const {
        return str_[index];
    }

    // Overload for the << operator to print MyString
    std::ostream& operator<<(std::ostream& out, const MyString& obj) {
        out << obj.c_str();
        return out;
    }

} // namespace cs_mystring
