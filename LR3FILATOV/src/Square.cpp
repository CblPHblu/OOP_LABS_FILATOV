#include "../include/Square.h"

Square::Square () {
    n = 4;
    p = new Point[n];
    side = 0;
}

Square::Square(Point& p_1, Point& p_2, Point& p_3, Point& p_4) {
    if (p_1.Is_Equal(p_2)|| p_1.Is_Equal(p_3) || p_1.Is_Equal(p_4) || p_2.Is_Equal(p_3) || p_2.Is_Equal(p_4) || p_3.Is_Equal(p_4)) {
        throw std::logic_error("Points can't be simular!\n");
    }
    if (!((p_1.length(p_2) == p_1.length(p_4)) && (p_1.length(p_3) == p_2.length(p_4)))) {
        throw std::logic_error("This is not square!\n");
    }
    n = 4;
    side = p_1.length(p_2);
    p = new Point[n];
    p[0] = p_1;
    p[1] = p_2;
    p[2] = p_3;
    p[3] = p_4;
}

double Square::getArea() const {
    return side * side;
}

bool Square::operator==(const Square& other) {
    return this->side == other.side;
}

Square& Square::operator=(Square& other) {
    if (!(this == &other)) {
        for (int i = 0; i < 4; i++) {
            this->p[i] = other.p[i];
        }
        this->n = other.n;
        this->side = other.side;
    }
    return *this;                      
}

Square& Square::operator=(Square&& other) {
    if (!(this == &other)) {
        for (int i = 0; i < 4; i++) {
            this->p[i] = std::move(other.p[i]);
        }
        this->n = other.n;
        this->side = other.side;
    }
    return *this;
}

Square::operator double() const {
    return getArea();
}