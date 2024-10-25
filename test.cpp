/**
 * test.cpp
 *
 * Project UID 2e6ea4e086ea6a06753e819c30923369
 *
 * EECS 183
 * Lab 7
 * Taken from Project 4: CoolPics
 *
 * <#Amelia Wu#>
 * <#wuamelia#>
 *
 * <#Implements tests for Point.cpp#>
 */

#include <iostream>
#include <fstream>
using namespace std;

#include "Point.h"

void test_Point();
void file_check();

void startTests() {
    test_Point();
    file_check();

    return;
}

void test_Point() {
    Point pt1;
    pt1.setX(15);
    cout << "Expected: (15,0), actual :" << pt1 << endl;

    Point pt2;
    pt2.setX(-42);
    pt2.setY(100);
    cout << "Expected: (0,99), actual :" << pt2 << endl;

    Point pt3(-15, 102);
    cout << "Expected: (0,99), actual :" << pt3 << endl;
        
    ifstream input_file;
    input_file.open("data1.txt");
    pt1.read(input_file);
    cout << "Expected: (42,7), actual :" << pt1 << endl;
  
    return;
}

void file_check() {

    // open one of the text files that are part of the starter code
    ifstream ins;
    ins.open("data1.txt");

    // if the file was not in the correct directory, the stream state is fail
    if (ins.fail()) {
        cout << "Could not open data1.txt" << endl;
    }
    else {
        cout << "Success! Text files are in the right directory." << endl;
    }
    ins.close();

    return;
}
