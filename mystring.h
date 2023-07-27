/*
* Program: mystring.cpp (Assignment 12P: Classes with DM 2)
* Author: Matt Aaron Magnaye
* Instructor: Professor David Harden
* Date: 07/27/2023
* Description: Refinements to the last class that I wrote (Assignment 11P)
*/
#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>

namespace cs_mystring {

    class MyString {
    public:
        static const int MAX_INPUT_SIZE = 128;

        // Constructors
        MyString();
        MyString(const char* str);
        MyString(const MyString& other);

        // Destructor
        ~MyString();

        // Assignment operator
        MyString& operator=(const MyString& other);

        // Accessors
        int length() const;
        const char* c_str() const;

        // Read function
        void read(std::istream& in, char delimiter);

        // Concatenation operators
        friend MyString operator+(const MyString& lhs, const MyString& rhs);
        MyString& operator+=(const MyString& rhs);

        // Extraction operator
        friend std::istream& operator>>(std::istream& in, MyString& obj);

        // Comparison operators
        friend bool operator==(const MyString& lhs, const MyString& rhs);
        friend bool operator!=(const MyString& lhs, const MyString& rhs);
        friend bool operator<(const MyString& lhs, const MyString& rhs);
        friend bool operator<=(const MyString& lhs, const MyString& rhs);
        friend bool operator>(const MyString& lhs, const MyString& rhs);
        friend bool operator>=(const MyString& lhs, const MyString& rhs);

        // Overloaded subscript operator
        char& operator[](int index);
        const char& operator[](int index) const;

    private:
        char* str_;
        int size_;
    };

    // Overload for the << operator to print MyString
    std::ostream& operator<<(std::ostream& out, const MyString& obj);

} // namespace cs_mystring

#endif // MYSTRING_H
