#pragma once

#include <iostream>
#include <math.h>

template <typename T>

class Point {
    template <class F>
    friend std::istream& operator>>(std::istream& is, Point<F>& p);
    template <class F>
    friend std::ostream& operator<<(std::ostream& os, Point<F>& p);
    template <class F>
    friend Point<F> operator+(const Point<F>& l, const Point<F>& r);
    template <class F>
    friend Point<F> operator-(const Point<F>& l, const Point<F>& r);

public:
    Point();
    Point<T> (T x, T y);
    Point(const Point<T>& other);
    bool Is_Equal(const Point<T>& other);
    Point<T>& operator=(const Point<T>& other);
    double length(const Point<T>& other);
    T x;
    T y;
};

template <class T>
Point<T>::Point () {
    this->x = 0;
    this->y = 0;
}

template <class T>
Point<T>::Point(T x, T y) {
    this->x = x;
    this->y = y;
}

template <class T>
Point<T>::Point(const Point<T>& other) {
    this->x = other.x;
    this->y = other.y;
}
template <class T>
std::istream& operator>>(std::istream& is, Point<T>& p) {
    T x, y;
    std::cout << "'X' and 'Y':" << std::endl;
    is >> x >> y;
    p.x = x;
    p.y = y;
    return is;
}

template <class T>
std::ostream& operator<<(std::ostream& os, Point<T>& p) {
    os << "(X: " << p.x << "; Y: " << p.y << ")";
    return os;
}

template <class T>
bool Point<T>:: Is_Equal(const Point<T>& other) {
    if (this->x == other.x && this->y == other.y) {
        return true;
    }
    return false;
}

template <class T>
Point<T> operator+(const Point<T>& l, const Point<T>& r) {
    return Point<T>(l.x + r.x, l.x + r.y);
}

template <class T>
Point<T> operator-(const Point<T>& l, const Point<T>& r) {
    return Point(l.x - r.x, l.x - r.y);
}

template <class T>
Point<T>& Point<T>::operator=(const Point<T>& other) {
    if (!(this->Is_Equal(other))) {
        this->x = other.x;
        this->y = other.y;
    }
    return *this;
}

template <class T>
double Point<T>::length(const Point<T>& other) {
    return sqrt((other.x - this->x) * (other.x - this->x) + (other.y - this->y) * (other.y - this->y));
}
