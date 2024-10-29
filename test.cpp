
/**
 * test.cpp
 * Project UID 2e6ea4e086ea6a06753e819c30923369
 *
 * EECS 183
 * Project 4: CoolPics
 *
 * Blake Yates, Amelia Wu
 * bryates, wuamelia
 *
 * Contains functions for testing classes in the project.
 */

#include "Graphics.h"
#include "Circle.h"
#include "Color.h"
#include "Line.h"
#include "Point.h"
#include "Rectangle.h"
#include "Shape.h"
#include "Triangle.h"

#include <iostream>
#include <fstream>

using namespace std;


void test_Circle();
void test_Color();
void test_Line();
void test_Point();
void test_Rectangle();
void test_Triangle();
void test_Graphics();
void file_check();

void startTests() {
    test_Point();
    test_Color();
    test_Graphics();
    test_Line();
    test_Triangle();
    file_check();
    test_Circle();
    test_Rectangle();
    // call other test functions here

    return;
}

void test_Point() {
    cout << "Now testing class Point" << endl;

    // test of default constructor
    Point p1;
    cout << "Expected: (0,0), actual: " << p1 << endl;

    // test of the non-default constructor
    Point p2(3, 9);
    cout << "Expected: (3,9), actual: " << p2 << endl;

    // test of member function: setX()
    p1.setX(5);
    // test of member function: setY()
    p1.setY(3);

    // test of member functions getX() and getY()
    cout << "Expected: (5,3), actual: ";
    cout << "(" << p1.getX()
        << "," << p1.getY()
        << ")" << endl;

    //test of member function checkRange (and non-default constructor)
    Point p3(-70, 200);
    cout << "Expected, (0,99), actual: " << p3 << endl;


    return;
}

void test_Color() {
    cout << endl << "Now testing class Color" << endl;

    // test of default constructor
    Color c1;
    cout << "Expected: 0  0  0, actual: " << c1 << endl;

    // test of non-default constructor
    Color c2(10, 20, 30);
    cout << "Expected: 10  20  30, actual: " << c2 << endl;

    //test of member functions setRed and getRed
    c1.setRed(175);
    cout << "Expected: 175, actual: " << c1.getRed() << endl;

    //test of member functions setGreen and getGreen
    c1.setGreen(12);
    cout << "Expected: 12, actual: " << c1.getGreen() << endl;

    //test of member functions setBlue and getBlue
    c1.setBlue(201);
    cout << "Expected: 201, actual: " << c1.getBlue() << endl;

    //test of member function checkRange (and non-default constructor)
    Color c3(-2, 100, 300);
    cout << "Expected: 0  100  255, actual: " << c3 << endl;
    return;
}

void test_Graphics() {
    cout << endl << "Now testing class Graphics" << endl;
    Color c1(0, 0, 0);
    //test of default constructor
    Graphics graphic1;
    graphic1.writeFile("TextFile1.txt");
    //test of non-default constructor
    graphic1.setPixel(0, 0, c1);

    //
    return;
}

void test_Line() {
    cout << endl << "Now testing class Line" << endl;

    //Default constructor test
    Line line1;
    cout << "Expected: (0,0) (0,0) 0 0 0, Actual: " << line1 << endl;

    //Non-default constructor test
    Point pt1(0, 0);
    Point pt2(0, 5);
    Color c1;
    Line line2(pt1, pt2, c1);
    cout << "Expected: (0,0) (0,5) 0 0 0, Actual: " << line2 << endl;

    //test of function set start and get start
    line1.setStart(pt2);
    cout << "Expected: (0,5), Actual: " << line1.getStart() << endl;

    //test of function set end and get end
    Point p3(6, 7);
    line2.setEnd(p3);
    cout << "Expected: (6, 7), Actual : " << line2.getEnd() << endl;

    //test of function set color and get color
    Color c2(3, 4, 5);
    line1.setColor(c2);
    cout << "Expected: 3 4 5, Actual: " << line1.getColor() << endl;

    //test write
    ofstream output_file;
    output_file.open("data2.txt");
    line2.write(output_file);

}

void test_Triangle() {
    cout << endl << "Now testing class Triangle" << endl;

    //points and colors to use in test cases
    Point p1(0, 0);
    Point p2(1, 5);
    Point p3(6, 7);
    Color c1(1, 2, 3);
    Color c2(0, 0, 0);
    Color c3(4, 5, 5);

    //test of default constructor
    Triangle t1;
    cout << "Expected: (0,0) 0 0 0 (0,0) 0 0 0 (0,0) 0 0 0, Actual: " <<
        t1 << endl;

    //test of non-default constructor
    Triangle t2(p1, c1, p2, c2, p3, c3);
    cout << "Expected: (0,0) 1 2 3 (1,5) 0 0 0 (6,7) 4 5 5, Actual: " <<
        t2 << endl;

    //test of function getVertexOne() and setVertexOne()
    t2.setVertexOne(p3);
    cout << "Expected: (6,7), Actual: " << t2.getVertexOne() << endl;

    //test of function getVertexOneColor() and setVertexOneColor()
    t2.setVertexOneColor(c2);
    cout << "Expected: 0 0 0, Actual: " << t2.getVertexOneColor() << endl;

    //test of function getVertexTwo() and setVertexTwo()
    t2.setVertexTwo(p3);
    cout << "Expected: (6,7), Actual: " << t2.getVertexTwo() << endl;

    //test of function getVertexTwoColor() and setVertexTwoColor()
    t2.setVertexTwoColor(c1);
    cout << "Expected: 1 2 3, Actual: " << t2.getVertexTwoColor() << endl;

    //test of function getVertexThree() and setVertexThree()
    t2.setVertexThree(p1);
    cout << "Expected: (0,0), Actual: " << t2.getVertexThree() << endl;

    //test of function getVertexThreeColor() and setVertexThreeColor()
    t2.setVertexThreeColor(c1);
    cout << "Expected: 1 2 3, Actual: " << t2.getVertexThreeColor() << endl;
}

void test_Circle() {
    cout << endl << "Now testing class Circle" << endl;

    //test of default constructor
    Circle c1;
    cout << "Expected: (0,0) 0 0  0  0, actual: " << c1 << endl;

    //test of non-default constructor
    Point initCenter(10, 71);
    Color red(255, 0, 0);

    Circle c2(initCenter, 4, red);
    cout << "Expected: (10,71) 4 255  0  0, actual: " << c2 << endl;

    //test member functions set and get center
    Point newCenter(12, 3);
    c1.setCenter(newCenter);
    cout << "Expected: (12, 3), actual: " << c1.getCenter() << endl;

    //test member functions set and get radius
    c1.setRadius(-74);
    cout << "Expected: 74, actual: " << c1.getRadius() << endl;

    //test member functions set and get color
    Color blue(0, 0, 255);
    c1.setColor(blue);
    cout << "Expected: 0  0  255, actual: " << c1.getColor() << endl;
}

void file_check() {

    // open one of the text files that are part of the starter code
    ifstream ins;
    ins.open("TextFile1");

    // if the file was not in the correct directory, the stream state is fail
    if (ins.fail()) {
        cout << "Could not open TextFile1" << endl;
    }
    else {
        cout << "Success! Text files are in the right directory." << endl;
    }
    ins.close();

    return;
}

void test_Rectangle() {
    cout << endl << "Now testing class Rectangle" << endl;
    //points and colors to use in tests
    Point p1(10, 10);
    Point p2(20, 30);
    Point p3(9, 9);
    Color c1(0, 1, 2);
    Color c2(3, 4, 5);
    Color c3(10, 10, 10);
    Color c4(5, 6, 7);
    Color c5(2, 3, 4);

    //test of default constructor
    Rectangle r1;
    cout << "Expected: (0,0)  (0,0)  0  0  0  0  0  0  0  0  0  0  0  0, Actual: " << r1 << endl;

    //test of non-default constructor
    Rectangle r2(p1, p2, c1, c2, c3, c4);
    cout << "Expected (10,10)  (20,30)  0  1  2  3  4  5  10  10  10  5  6  7, Actual: " << r2 << endl;

    //test of function setStart and getStart
    r1.setStart(p3);
    cout << "Expected: (9,9), Actual: " << r1.getStart() << endl;

    //test of function setEnd and getEnd
    r1.setEnd(p3);
    cout << "Expected: (9,9), Actual: " << r2.getEnd() << endl;

    //test of function setColorTopLeft and getColorTopLeft
    r1.setColorTopLeft(c5);
    cout << "Expected: 2  3  4, Actual: " << r1.getColorTopLeft() << endl;

    //test of function setColorTopRight and getColorTopRight
    r1.setColorTopRight(c5);
    cout << "Expected: 2  3  4, Actual: " << r1.getColorTopRight() << endl;

    //test of function setColorBottomRight and getColorBottomRight
    r1.setColorBottomRight(c5);
    cout << "Expected: 2  3  4, Actual: " << r1.getColorBottomRight() << endl;

    //test of function setColorBottomLeft and getColorBottomLeft
    r1.setColorBottomLeft(c5);
    cout << "Expected 2  3  4, Actual: " << r1.getColorBottomLeft() << endl;

    return;
}
