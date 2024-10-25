/**
 * Triangle.cpp
 * Project UID 2e6ea4e086ea6a06753e819c30923369
 *
 * EECS 183
 * Project 4: CoolPics
 *
 * Blake Yates, Amelia Wu
 * bryates, wuamelia
 *
 * Definitions for class Triangle constructors and member fu
 */

#include "Triangle.h"
#include "Graphics.h"
#include "Shape.h"
#include <cmath>
using namespace std;

// TODO: implement two constructors, setColor, setVertexOne, getVertexOne,
//       setVertexTwo, getVertexTwo, setVertexThree, getVertexThree,
//       setVertexOneColor, getVertexOneColor, setVertexTwoColor,
//       getVertexTwoColor, setVertexThreeColor, getVertexThreeColor,
//       read, write.

//default constructor
Triangle::Triangle() {
    
}

Triangle::Triangle(Point pt1, Color color1, Point pt2, Color color2,
    Point pt3, Color color3) {
    vertexOne = pt1;
    vertexOneColor = color1;
    vertexTwo = pt2;
    vertexTwoColor = color2;
    vertexThree = pt3;
    vertexThreeColor = color3;
}

void Triangle::setColor(Color color) {
    vertexOneColor = color;
    vertexTwoColor = color;
    vertexThreeColor = color;
}

void Triangle::setVertexOne(Point pt) {
    vertexOne = pt;
}

Point Triangle::getVertexOne() {
    return vertexOne;
}

void Triangle::setVertexOneColor(Color color) {
    vertexOneColor = color;
}

Color Triangle::getVertexOneColor() {
    return vertexOneColor;
}

void Triangle::setVertexTwo(Point pt) {
    vertexTwo = pt;
}

Point Triangle::getVertexTwo() {
    return vertexTwo;
}

void Triangle::setVertexTwoColor(Color color) {
    vertexTwoColor = color;
}

Color Triangle::getVertexTwoColor() {
    return vertexTwoColor;
}

void Triangle::setVertexThree(Point pt) {
    vertexThree = pt;
}

Point Triangle::getVertexThree() {
    return vertexThree;
}

void Triangle::setVertexThreeColor(Color color) {
    vertexThreeColor = color;
}

Color Triangle::getVertexThreeColor() {
    return vertexThreeColor;
}

void Triangle::read(istream& ins) {
    char junk;
    ins >> vertexOne >> junk >> vertexOneColor >> junk >> vertexTwo >> junk >> vertexTwoColor
        >> junk >> vertexThree >> junk >> vertexThreeColor;
}

void Triangle::write(ostream& outs) {
    outs << vertexOne << " " << vertexOneColor << " " << vertexTwo << " " << vertexTwoColor
        << " " << vertexThree << " " << vertexThreeColor;
}


// Your code goes above this line.
// Don't change the implementations below!

istream& operator >> (istream& ins, Triangle& tri)
{
    tri.read(ins);
    return ins;
}

ostream& operator << (ostream& outs, Triangle tri)
{
    tri.write(outs);
    return outs;
}

void Triangle::draw(Graphics& drawer) {

    int xa = getVertexOne().getX();
    int ya = getVertexOne().getY();
    int xb = getVertexTwo().getX();
    int yb = getVertexTwo().getY();
    int xc = getVertexThree().getX();
    int yc = getVertexThree().getY();
    float red1 = (float)(getVertexOneColor().getRed() / 255.0);
    float green1 = (float)(getVertexOneColor().getGreen() / 255.0);
    float blue1 = (float)(getVertexOneColor().getBlue() / 255.0);
    float red2 = (float)(getVertexTwoColor().getRed() / 255.0);
    float green2 = (float)(getVertexTwoColor().getGreen() / 255.0);
    float blue2 = (float)(getVertexTwoColor().getBlue() / 255.0);
    float red3 = (float)(getVertexThreeColor().getRed() / 255.0);
    float green3 = (float)(getVertexThreeColor().getGreen() / 255.0);
    float blue3 = (float)(getVertexThreeColor().getBlue() / 255.0);

    float a01, a02, a03, b01, b02, b03, c01, c02, c03, beta1, beta2, beta3;
    float lowX = 0, lowY = 0, highX = 0, highY = 0, i, j, R, G, B, t1, t2, t3;
    float triangleArea = 0;

    a01 = (float)(ya - yb);
    a02 = (float)(ya - yc);
    a03 = (float)(yb - yc);
    b01 = (float)(xb - xa);
    b02 = (float)(xc - xa);
    b03 = (float)(xc - xb);
    c01 = -(a01 * (xa + xb) + b01 * (ya + yb)) / 2;
    c02 = -(a02 * (xa + xc) + b02 * (ya + yc)) / 2;
    c03 = -(a03 * (xb + xc) + b03 * (yb + yc)) / 2;

    if (evalFunc(xc, yc, (int)a01, (int)b01, (int)c01) < 0) {
        a01 = a01 * (-1);
        b01 = b01 * (-1);
        c01 = c01 * (-1);
    }
    if (evalFunc(xb, yb, (int)a02, (int)b02, (int)c02) < 0) {
        a02 = a02 * (-1);
        b02 = b02 * (-1);
        c02 = c02 * (-1);
    }
    if (evalFunc(xa, ya, (int)a03, (int)b03, (int)c03) < 0) {
        a03 = a03 * (-1);
        b03 = b03 * (-1);
        c03 = c03 * (-1);
    }
    if (xa > xb) { highX = (float)xa; }
    else { highX = (float)xb; }
    if (xc > highX) { highX = (float)xc; }
    if (ya > yb) { highY = (float)ya; }
    else { highY = (float)yb; }
    if (yc > highY) { highY = (float)yc; }
    if (xa < xb) { lowX = (float)xa; }
    else { lowX = (float)xb; }
    if (xc < lowX) { lowX = (float)xc; }
    if (ya < yb) { lowY = (float)ya; }
    else { lowY = (float)yb; }
    if (yc < lowY) { lowY = (float)yc; }

    triangleArea = triArea(xa, ya, xb, yb, xc, yc);

    for (i = lowX; i < (highX + 1); i++) {
        for (j = lowY; j < (highY + 1); j++) {
            t1 = (float)evalFunc((int)i, (int)j, (int)a01, (int)b01, (int)c01);
            t2 = (float)evalFunc((int)i, (int)j, (int)a02, (int)b02, (int)c02);
            t3 = (float)evalFunc((int)i, (int)j, (int)a03, (int)b03, (int)c03);
            if ((t1 >= 0) && (t2 >= 0) && (t3 >= 0)) {
                t1 = triArea(xb, yb, xc, yc, (int)i, (int)j);
                t2 = triArea(xc, yc, xa, ya, (int)i, (int)j);
                t3 = triArea(xa, ya, xb, yb, (int)i, (int)j);
                beta1 = triArea(xb, yb, xc, yc, (int)i, (int)j) / triangleArea;
                beta2 = triArea(xc, yc, xa, ya, (int)i, (int)j) / triangleArea;
                beta3 = triArea(xa, ya, xb, yb, (int)i, (int)j) / triangleArea;
                R = (beta1 * red1 + beta2 * red2 + beta3 * red3) * 255;
                G = (beta1 * green1 + beta2 * green2 + beta3 * green3) * 255;
                B = (beta1 * blue1 + beta2 * blue2 + beta3 * blue3) * 255;
                drawer.setPixel((int)i, (int)j, Color((int)R, (int)G, int(B)));
            }
        }
    }
}

int Triangle::evalFunc(int x, int y, int a, int b, int c) {
    int e = a * x + b * y + c;
    return(e);
}

float Triangle::triArea(int xa, int ya, int xb, int yb, int xref, int yref) {
    xa -= xref;
    xb -= xref;
    ya -= yref;
    yb -= yref;
    return((float)(sqrt(pow((double)(yb * xa) - (xb * ya), (double)2)) * 0.5));
}
