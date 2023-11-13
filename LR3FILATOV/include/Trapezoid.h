#include "Figure.h"

class Trapezoid : public Figure {
public:
    Trapezoid();
    Trapezoid(Point& p_1, Point& p_2, Point& p_3, Point& p_4);

    virtual double getArea() const override;
    virtual operator double() const override;

    Trapezoid& operator=(Trapezoid& other);
    Trapezoid& operator=(Trapezoid&& other);
    bool operator==(const Trapezoid& other);

    ~Trapezoid(){
        n = 0;
        delete [] p;
        p = nullptr;
    }
private:
    double side_1, side_2, h;
};