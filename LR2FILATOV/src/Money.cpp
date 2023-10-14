#include "../include/Money.h"

Money::Money(){
    _size = 2;
    _array = new unsigned char[_size];
    rub = new unsigned char[_size - 1];
    _array[0] = '0';
    _array[1] = '0';
    _array[2] = '0';
    rub[0] = '0';
    cop[0] = '0';
    cop[1] = '0';
}
Money::Money(const std::string &t)
{
    if ((t.size() > 3) && (t[t.size() - 3] == ',')){
        
        _array = new unsigned char[t.size() - 1]; // -1 т.к. мне не нужна запятая
        rub = new unsigned char[t.size() - 3]; // -3 т.к. мне не нужна запятая и две копейки
        _size  = t.size() - 2;
        size_t i = 0;
        _array[0] = t[_size + 1];
        _array[1] = t[_size];
        cop[0] = t[_size];
        cop[1] = t[_size + 1];
        while (t[i] != ',')
        {
            _array[i+2] = t[_size - (i+2)];
            rub[i] = t[i];
            i++;
        }
        for(size_t i{0}; i <= _size; ++i) {
            if (_array[i] < '0' || _array[i] > '9') {
                throw std::logic_error("Wrong sum (Invalid symbols)!");
            }
        } 
    }
    else {
        throw std::logic_error("Wrong sum (check ',' or number amount)!");
    }
}

Money::Money(const Money &other) 
{
    _size = other._size;
    _array = new unsigned char[_size + 1];
    rub = new unsigned char[_size - 1];
    cop[0] = other.cop[0];
    cop[1] = other.cop[1];

    for(size_t i{0}; i <= _size; ++i) {
        _array[i] = other._array[i];
    }
    for(size_t j{0}; j <= (_size - 2); ++j) {
        rub[j] = other.rub[j];
    }
}

Money::Money(Money &&other) noexcept
{
    _size = other._size;
    rub = other.rub;
    cop[0] = other.cop[0];
    cop[1] = other.cop[1];
    _array = other._array;
    other._size = 0;
    other._array = nullptr;
    other.rub = nullptr;
}



Money Money::add(const Money &other)
{
    if (this->_size != 0 && other._size != 0){
        int rub1 = atoi(reinterpret_cast<const char*>(rub));
        int cop1 = atoi(reinterpret_cast<const char*>(cop));
        int rub2 = atoi(reinterpret_cast<const char*>(other.rub));
        int cop2 = atoi(reinterpret_cast<const char*>(other.cop));
        int add_rub = rub1 + rub2;
        int add_cop = cop1 + cop2;
        if (add_cop >= 100){
            add_rub += add_cop / 100;
            add_cop %= 100;
        }
        std::stringstream ss;
        if (add_cop < 10){
            ss << add_rub << ",0" << add_cop;
        }
        else {
            ss << add_rub << "," << add_cop;
        }
        std::string result = ss.str();
        return Money(result);
    }
    else {
        throw std::logic_error("NO MONEY!");
    }
}

Money Money::remove(const Money &other)
{   
    if (this->_size != 0 && other._size != 0)
    {
        int rub1 = atoi(reinterpret_cast<const char*>(rub));
        int cop1 = atoi(reinterpret_cast<const char*>(cop));
        int rub2 = atoi(reinterpret_cast<const char*>(other.rub));
        int cop2 = atoi(reinterpret_cast<const char*>(other.cop));
        if (rub1 < rub2){
            throw std::logic_error("Money can't be negative!\n");
        }
        else if (rub1 == rub2 && cop1 < cop2){
            throw std::logic_error("Money can't be negative!\n");
        }
        int rem_rub = rub1 - rub2;
        if (cop1 < cop2){
            cop1 += 100;
            rem_rub--;
        }
        int rem_cop = cop1 - cop2;
        std::stringstream ss;
        if (rem_cop < 10){
            ss << rem_rub << ",0" << rem_cop;
        }
        else {
            ss << rem_rub << "," << rem_cop;
        }
        std::string result = ss.str();
        return Money(result);
    }
    else {
        throw std::logic_error("NO MONEY!");
    }
}

Money Money::copy(const Money & other)
{
    if (this->_size != 0 && other._size != 0)
    {
        this->_size = other._size;
        this->_array = new unsigned char[_size + 1];
        this->rub = new unsigned char[_size - 1];
        this->cop[0] = other.cop[0];
        this->cop[1] = other.cop[1];
        for(size_t i{0}; i <= _size; ++i) {
            this->_array[i] = other._array[i];
        }
        for(size_t j{0}; j <= (_size - 2); ++j) {
            this->rub[j] = other.rub[j];
        }
        
        return *this;
    }
    else {
        throw std::logic_error("NO MONEY!");
    }
}

bool Money::is_equals(const Money & other) const
{   
    if (this->_size != 0 && other._size != 0)
    {
        int rub1 = atoi(reinterpret_cast<const char*>(rub));
        int cop1 = atoi(reinterpret_cast<const char*>(cop));
        int rub2 = atoi(reinterpret_cast<const char*>(other.rub));
        int cop2 = atoi(reinterpret_cast<const char*>(other.cop)); 
        
        if (rub1 == rub2 && cop1 == cop2){
            return true;
        }
        else {
            return false;
        }
    }
    else {
        throw std::logic_error("NO MONEY!");
    }
}

bool Money::is_larger(const Money & other) const
{
    
    if (this->_size != 0 && other._size != 0)
    {
        int rub1 = atoi(reinterpret_cast<const char*>(rub));
        int cop1 = atoi(reinterpret_cast<const char*>(cop));
        int rub2 = atoi(reinterpret_cast<const char*>(other.rub));
        int cop2 = atoi(reinterpret_cast<const char*>(other.cop)); 
        if (rub1 > rub2){
            return true;
        }
        else if (rub1 == rub2 && cop1 > cop2){
            return true;
        }
        else {
            return false;
        }
    }
    else {
        throw std::logic_error("NO MONEY!");
    }
}

bool Money::is_smaller(const Money & other) const
{
    if (this->_size != 0 && other._size != 0){
        int rub1 = atoi(reinterpret_cast<const char*>(rub));
        int cop1 = atoi(reinterpret_cast<const char*>(cop));
        int rub2 = atoi(reinterpret_cast<const char*>(other.rub));
        int cop2 = atoi(reinterpret_cast<const char*>(other.cop)); 
        if (rub2 > rub1){
            return true;
        }
        else if (rub1 == rub2 && cop2 > cop1){
            return true;
        }
        else {
            return false;
        }
    }
    else {
        throw std::logic_error("NO MONEY!");
    }
}

std::ostream &Money::print(std::ostream &os)
{
    if (_size > 0){
        for (size_t i = _size; i > 0; i--)
            os << _array[i];
        os << _array[0];
        return os;
    }
    else {
        throw std::logic_error("NO MONEY!");
    }
}

Money::~Money() noexcept
{
    if (_size > 0)
    {
        _size = 0;
        delete[] _array;
        delete[] rub;
        _array = nullptr;
        rub = nullptr;
    }
}