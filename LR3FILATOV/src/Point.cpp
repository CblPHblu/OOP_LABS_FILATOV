#include "../include/Point.h"

Point::Point () {
    this->x = 0;
    this->y = 0;
}

Point::Point(double x, double y) {
    this->x = x;
    this->y = y;
}

Point::Point(const Point& other) {
    this->x = other.x;
    this->y = other.y;
}

std::istream& operator>>(std::istream& is, Point& p) {
    double x, y;
    std::cout << "X and Y:" << std::endl;
    is >> x >> y;
    p.x = x;
    p.y = y;
    return is;
}

std::ostream& operator<<(std::ostream& os, Point& p) {
    os << "(X: " << p.x << "; Y: " << p.y << ")";
    return os;
}

bool Point::Is_Equal(const Point& other) {
    return (this->x == other.x && this->y == other.y);
}

Point operator+(const Point& l, const Point& r) {
    return Point(l.x + r.x, l.x + l.y);
}

Point operator-(const Point& l, const Point& r) {
    return Point(l.x - r.x, l.x - l.y);
}

Point& Point::operator=(const Point& other) {
    if (this->Is_Equal(other) == false) {
        this->x = other.x;
        this->y = other.y;
    }
    return *this;
}

double Point::length(const Point& other) {
    return sqrt((other.x - this->x) * (other.x - this->x) + (other.y - this->y) * (other.y - this->y));
}