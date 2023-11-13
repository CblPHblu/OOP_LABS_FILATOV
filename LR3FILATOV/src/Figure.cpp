#include <iostream>
#include "../include/Figure.h"

std::istream& operator>>(std::istream& is, Figure& figure) {
    for (int i = 0; i < figure.n; i++) {
        is >> figure.p[i];
    }
    return is;
}

std::ostream& operator<<(std::ostream& os, Figure *figure) {
    for (int i = 0; i < figure->n; i++) {
        os << i + 1 << ": " << figure->p[i] << std::endl;
    }
    return os;
}

Point Figure::center() const {
    double x_sum = 0, y_sum = 0;
    for (int i = 0; i < n; i++) {
        x_sum += p[i].x;
        y_sum += p[i].y;
    }
    return Point(x_sum / n, y_sum / n);
}

bool Figure::is_correct() {
    if (n != 4) {
        return false;
    }
    return true;
}