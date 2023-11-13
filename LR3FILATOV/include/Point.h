#pragma once

#include <iostream>
#include <math.h>

class Point {
    friend std::istream& operator>>(std::istream& is, Point& p);
    friend std::ostream& operator<<(std::ostream& os, Point& p);
    friend Point operator+(const Point& l, const Point& r);
    friend Point operator-(const Point& l, const Point& r);

public:
    Point();
    Point(double x, double y);
    Point(const Point& other);
    bool Is_Equal(const Point& other);
    Point& operator=(const Point& other);
    double x;
    double y;

    double length(const Point& other);

    
};