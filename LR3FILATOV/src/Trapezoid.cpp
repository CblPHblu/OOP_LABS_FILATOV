#include "../include/Trapezoid.h"

Trapezoid::Trapezoid () {
    n = 4;
    p = new Point[n];
    side_1 = 0;
    side_2 = 0;
    h = 0;
}

Trapezoid::Trapezoid(Point& p_1, Point& p_2, Point& p_3, Point& p_4) {
    if (p_1.Is_Equal(p_2)|| p_1.Is_Equal(p_3) || p_1.Is_Equal(p_4) || p_2.Is_Equal(p_3) || p_2.Is_Equal(p_4) || p_3.Is_Equal(p_4)) {
        throw std::logic_error("Points can't be simular!\n");
    }
    if (!(p_1.y == p_2.y) && (p_3.y == p_4.y)) {
        throw std::logic_error("This is not Trapezoid!\n");
    }
    n = 4;
    side_1 = p_1.length(p_2);
    side_2 = p_3.length(p_4);
    h = abs(p_1.y - p_4.y);
    p = new Point[n];
    p[0] = p_1;
    p[1] = p_2;
    p[2] = p_3;
    p[3] = p_4;
}

double Trapezoid::getArea() const {
    return (side_1 + side_2) * 0.5 * h;
}

bool Trapezoid::operator==(const Trapezoid& other) {
    return static_cast<double>(*this) == static_cast<double>(other);
}

Trapezoid& Trapezoid::operator=(Trapezoid& other) {
    if (!(this == &other)) {
        for (int i = 0; i < 4; i++) {
            this->p[i] = other.p[i];
        }
        this->n = other.n;
        this->side_1 = other.side_1;
        this->side_2 = other.side_2;
        this->h = other.h;
    }
    return *this;                      
}

Trapezoid& Trapezoid::operator=(Trapezoid&& other) {
    if (!(this == &other)) {
        for (int i = 0; i < 4; i++) {
            this->p[i] = std::move(other.p[i]);
        }
        this->n = other.n;
        this->side_1 = other.side_1;
        this->side_2 = other.side_2;
        this->h = other.h;
    }
    return *this;
}

Trapezoid::operator double() const {
    return getArea();
}