#include "Figure.h"

class Rectangle : public Figure {
public:
    Rectangle();
    Rectangle(Point& p_1, Point& p_2, Point& p_3, Point& p_4);

    virtual double getArea() const override;
    virtual operator double() const override;

    Rectangle& operator=(Rectangle& other);
    Rectangle& operator=(Rectangle&& other);
    bool operator==(const Rectangle& other);

    ~Rectangle(){
        n = 0;
        delete [] p;
        p = nullptr;
    }
private:
    double side_1, side_2;
};