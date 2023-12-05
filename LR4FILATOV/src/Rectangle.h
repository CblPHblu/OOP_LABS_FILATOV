#include "./Figure.h"

template <class T>
class Rectangle : public Figure<T> {
public:
    Rectangle();
    Rectangle(Point<T>& p_1, Point<T>& p_2, Point<T>& p_3, Point<T>& p_4);

    virtual T getArea() const override;
    virtual operator double() const override;

    Rectangle<T>& operator=(Rectangle<T>& other);
    Rectangle<T>& operator=(Rectangle<T>&& other);
    bool operator==(const Rectangle<T>& other);

    ~Rectangle(){
        this->n = 0;
        delete [] this->p;
        this->p = nullptr;
    }
private:
    double side_1, side_2;
};

template <class T>
Rectangle<T>::Rectangle () {
    this->n = 4;
    this->p = new Point<T>[this->n];
    side_1 = 0;
    side_2 = 0;
}

template <class T>
Rectangle<T>::Rectangle(Point<T>& p_1, Point<T>& p_2, Point<T>& p_3, Point<T>& p_4) {
    if (p_1.Is_Equal(p_2)|| p_1.Is_Equal(p_3) || p_1.Is_Equal(p_4) || p_2.Is_Equal(p_3) || p_2.Is_Equal(p_4) || p_3.Is_Equal(p_4)) {
        throw std::logic_error("Points can't be simular!\n");
    }
    if (!((p_1.length(p_2) == p_3.length(p_4)) && (p_1.length(p_3) == p_2.length(p_4)))) {
        throw std::logic_error("This is not Rectangle!\n");
    }
    this->n = 4;
    side_1 = p_1.length(p_2);
    side_2 = p_1.length(p_4);
    this->p = new Point<T>[this->n];
    this->p[0] = p_1;
    this->p[1] = p_2;
    this->p[2] = p_3;
    this->p[3] = p_4;
}

template <class T>
T Rectangle<T>::getArea() const {
    return side_1 * side_2;
}

template <class T>
bool Rectangle<T>::operator==(const Rectangle<T>& other) {
    return static_cast<T>(*this) == static_cast<T>(other);
}

template <class T>
Rectangle<T>& Rectangle<T>::operator=(Rectangle<T>& other) {
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

template <class T>
Rectangle<T>& Rectangle<T>::operator=(Rectangle<T>&& other) {
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

template <class T>
Rectangle<T>::operator double() const {
    return getArea();
}