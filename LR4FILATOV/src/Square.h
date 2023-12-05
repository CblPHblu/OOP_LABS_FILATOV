#include "./Figure.h"

template <class T>
class Square : public Figure<T> {
public:
    Square();
    Square(Point<T>& p_1, Point<T>& p_2, Point<T>& p_3, Point<T>& p_4);

    virtual T getArea() const override;
    virtual operator double() const override;

    Square<T>& operator=(Square<T>& other);
    Square<T>& operator=(Square<T>&& other);
    bool operator==(const Square<T>& other);

    ~Square(){
        this->n = 0;
        delete [] this->p;
        this->p = nullptr;
    }
private:
    double side;
};

template <class T>
Square<T>::Square () {
    this->n = 4;
    this->p = new Point<T>[this->n];
    side = 0;
}

template <class T>
Square<T>::Square(Point<T>& p_1, Point<T>& p_2, Point<T>& p_3, Point<T>& p_4) {
    if (p_1.Is_Equal(p_2)|| p_1.Is_Equal(p_3) || p_1.Is_Equal(p_4) || p_2.Is_Equal(p_3) || p_2.Is_Equal(p_4) || p_3.Is_Equal(p_4)) {
        throw std::logic_error("Points can't be simular!\n");
    }
    if (!((p_1.length(p_2) == p_1.length(p_4)) && (p_1.length(p_3) == p_2.length(p_4)))) {
        throw std::logic_error("This is not square!\n");
    }
    this->n = 4;
    side = p_1.length(p_2);
    this->p = new Point<T>[this->n];
    this->p[0] = p_1;
    this->p[1] = p_2;
    this->p[2] = p_3;
    this->p[3] = p_4;
}

template <class T>
T Square<T>::getArea() const {
    return side * side;
}

template <class T>
bool Square<T>::operator==(const Square<T>& other) {
    return this->side == other.side;
}

template <class T>
Square<T>& Square<T>::operator=(Square<T>& other) {
    if (!(this == &other)) {
        for (int i = 0; i < 4; i++) {
            this->p[i] = other.p[i];
        }
        this->n = other.n;
        this->side = other.side;
    }
    return *this;                      
}

template <class T>
Square<T>& Square<T>::operator=(Square<T>&& other) {
    if (!(this == &other)) {
        for (int i = 0; i < 4; i++) {
            this->p[i] = std::move(other.p[i]);
        }
        this->n = other.n;
        this->side = other.side;
    }
    return *this;
}

template <class T>
Square<T>::operator double() const {
    return getArea();
}