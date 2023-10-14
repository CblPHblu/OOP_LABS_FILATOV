#pragma once

#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>

class Money 
{
    public:
        Money();
        Money(const std::string &t);
        Money(const Money& other);
        Money(Money && other) noexcept;

        Money add(const Money & other);
        Money remove(const Money & other);
        Money copy(const Money & other);
        bool is_equals(const Money & other) const;
        bool is_larger(const Money & other) const;
        bool is_smaller(const Money & other) const;
        std::ostream & print(std::ostream& os);

        virtual ~Money() noexcept;

    private:
        size_t _size;
        unsigned char *_array;
        unsigned char *rub;
        unsigned char cop[2];

};