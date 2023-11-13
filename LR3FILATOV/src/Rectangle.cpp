#include "../include/Rectangle.h"

Rectangle::Rectangle () {
    n = 4;
    p = new Point[n];
    side_1 = 0;
    side_2 = 0;
}

Rectangle::Rectangle(Point& p_1, Point& p_2, Point& p_3, Point& p_4) {
    if (p_1.Is_Equal(p_2)|| p_1.Is_Equal(p_3) || p_1.Is_Equal(p_4) || p_2.Is_Equal(p_3) || p_2.Is_Equal(p_4) || p_3.Is_Equal(p_4)) {
        throw std::logic_error("Points can't be simular!\n");
    }
    if (!((p_1.length(p_2) == p_3.length(p_4)) && (p_1.length(p_3) == p_2.length(p_4)))) {
        throw std::logic_error("This is not Rectangle!\n");
    }
    n = 4;
    side_1 = p_1.length(p_2);
    side_2 = p_1.length(p_4);
    p = new Point[n];
    p[0] = p_1;
    p[1] = p_2;
    p[2] = p_3;
    p[3] = p_4;
}

double Rectangle::getArea() const {
    return side_1 * side_2;
}

bool Rectangle::operator==(const Rectangle& other) {
    return static_cast<double>(*this) == static_cast<double>(other);
}

Rectangle& Rectangle::operator=(Rectangle& other) {
    if (!(this == &other)) {
        for (int i = 0; i < 4; i++) {
            this->p[i] = other.p[i];
        }
        this->n = other.n;
        this->side_1 = other.side_1;
        this->side_2 = other.side_2;
    }
    return *this;                      
}

Rectangle& Rectangle::operator=(Rectangle&& other) {
    if (!(this == &other)) {
        for (int i = 0; i < 4; i++) {
            this->p[i] = std::move(other.p[i]);
        }
        this->n = other.n;
        this->side_1 = other.side_1;
        this->side_2 = other.side_2;
    }
    return *this;
}

Rectangle::operator double() const {
    return getArea();
}