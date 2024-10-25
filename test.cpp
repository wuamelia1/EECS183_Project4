
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
    file_check();
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
    Line line2 (pt1, pt2, c1);
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
