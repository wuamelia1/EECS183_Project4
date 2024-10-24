/**
 * Color.cpp
 * Project UID 2e6ea4e086ea6a06753e819c30923369
 *
 * EECS 183
 * Project 4: CoolPics
 *
 * Blake Yates, Amelia Wu
 * bryates, wuamelia
 *
 * Definitions for class Color constructors and member fu
 */

#include "Color.h"

// TODO: implement first checkRange, then two constructors, setRed, getRed,
//       setGreen, getGreen, setBlue, getBlue, read, write.

int checkRange(int val) {
	//to do- implement

	//to do- replace with correct return statement
	return 0;
}

//default constructor
Color::Color() {
	//to do- implement
}

Color::Color(int redVal, int greenVal, int blueVal) {
	//to do- implement
}

void Color::setRed(int redVal) {
	//to do- implement
}

int Color::getRed() {
	//to do- implement

	//to do- replace with correct return statement
	return 0;
}

void Color::setGreen(int greenVal) {
	//to do- implement
}

int Color::getGreen() {
	//to do- implement

	//to do- replace with correct return statement
	return 0;
}

void Color:: setBlue(int blueVal) {
	//to do- implement
}

int Color::getBlue() {
	//to do- implement

	//to do- replace with correct return statement
	return 0;
}

void Color::read(istream& ins) {
	//to do- implement
}

void Color::write(ostream& outs) {
	//to do- implement
}


// Your code goes above this line.
// Don't change the implementations below!

istream& operator >> (istream& ins, Color& color)
{
   color.read(ins);
   return ins;
}

ostream& operator << (ostream& outs, Color color)
{
   color.write(outs);
   return outs;
}

