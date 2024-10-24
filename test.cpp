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

void startTests() {
    test_Point();
    test_Color();
    
    // call other test functions here
    
    return;
}

void test_Point() {
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
}




