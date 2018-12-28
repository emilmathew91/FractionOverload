#pragma once
#ifndef __Fraction__
#define __Fraction
#include <iostream>__
#include <math.h>
using namespace std;

// CLASS SPECIFICATION 

class Fraction {
private:
	// DATA MEMBERS 
	int num; 
	int den;
	int commonDenominator;

	// HELPER METHODS
	void CommonDenominator();

public:
	// CONSTRUCTOR(S) 
	Fraction();
	Fraction(int num, int den);

	//OVERLOADS
	void operator=(Fraction value) {//assignment operator overload
		this->num = value.num; //sets num and den to the value's x and y that is passed. 
		this->den = value.den;
	}
	Fraction operator+(Fraction value) { //addition operator
		value = AddFraction(value);
		value = SimplifyFraction(value);//sets value to what is returned from addFraction and returns
		return value;
	}
	Fraction operator-(Fraction value) { //subraction operator 
		value = SubtractFraction(value); //sets value to what is returned from subtractFraction and returns
		value = SimplifyFraction(value);
		return value;
	}
	Fraction operator*(Fraction value) { //multiplication operator 
		value = MultiplyFraction(value); //sets value to what is returned from multiplyFraction and returns
		value = SimplifyFraction(value);
		return value;
	}
	Fraction operator/(Fraction value) { //division operator 
		value = DivideFraction(value); //sets value to what is returned from divideFraction and returns
		value = SimplifyFraction(value);
		return value;
	}
	friend ostream& operator<<(ostream& outputStream, Fraction& value) { //output
		outputStream << value.num << ", " << value.den;
		return outputStream;
	}

	friend istream& operator>>(istream& inputStream, Fraction& value) { //input
	int validDen = 0; //denominator above 0 validator store
	cout << "Please enter a numerator: ";
	inputStream >> value.num;
	cout << "Please enter a denominator: ";
	inputStream >> validDen;
	while (validDen == 0) { //checks for valid denominator
		cout << "Please enter a denominator greater than 0: ";
		inputStream >> validDen;
	}
	if (validDen != 0) {
		value.den = validDen; //assigns valid denominator to value
	}
	cout << endl;
	return inputStream;
	}

	

	// SETTERS

	void SetNum(int num);
	void SetDen(int den);

	// GETTERS 
	int GetNum();
	int GetDen();
	int GetCommonDenominator();

	// OPERATIONS 
	Fraction AddFraction(Fraction addMe);
	Fraction SubtractFraction(Fraction subtractMe);
	Fraction MultiplyFraction(Fraction multiplyMe);
	Fraction DivideFraction(Fraction divideMe);
	Fraction SimplifyFraction(Fraction simplifyMe);

	// DISPLAY METHODS 
	void Display();
};


#endif