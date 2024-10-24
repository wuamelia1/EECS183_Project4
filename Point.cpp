/**
 * Point.cpp
 * Project UID 2e6ea4e086ea6a06753e819c30923369
 *
 * EECS 183
 * Project 4: CoolPics
 *
 * Blake Yates, Amelia Wu
 * bryates, wuamelia
 *
 * Definitions for class Point constructors and member fu
 */

#include "Point.h"

// for the declaration of DIMENSION
#include "utility.h"

int Point::checkRange(int val) {
    if (val >= 0 && val < DIMENSION) {
        return val;
    }
    else if (val < 0) {
        return 0;
    }
    else {
        return (DIMENSION - 1);
    }
}

Point::Point() {
    x = 0;
    y = 0;
}

Point::Point(int inX, int inY) {
    x = checkRange(inX);
    y = checkRange(inY);
}


void Point::setX(int inX) {
    x = checkRange(inX);
    return;
}

int Point::getX() {
    return x;
}

void Point::setY(int inY) {
    y = checkRange(inY);
    return;
}

int Point::getY() {
    return y;
}

void Point::read(istream& ins) {
    char junk = '/';
    ins >> junk >> x >> junk >> y >> junk;
    x = checkRange(x);
    y = checkRange(y);

    return;
}

void Point::write(ostream& outs) {
    outs << "(" << x << "," << y << ")";
    return;
}


// Your code goes above this line.
// Don't change the implementations below!

istream& operator >> (istream& ins,  Point& pt)
{
    pt.read(ins);
    return ins;
}

ostream& operator<< (ostream& outs, Point pt)
{
    pt.write(outs);
    return outs;
}
