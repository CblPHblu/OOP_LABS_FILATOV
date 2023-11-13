#include "Figure.h"

class Square : public Figure {
public:
    Square();
    Square(Point& p_1, Point& p_2, Point& p_3, Point& p_4);

    virtual double getArea() const override;
    virtual operator double() const override;

    Square& operator=(Square& other);
    Square& operator=(Square&& other);
    bool operator==(const Square& other);

    ~Square(){
        n = 0;
        delete [] p;
        p = nullptr;
    }
private:
    double side;
};