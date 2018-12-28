#pragma once
#include "FractionOverloadHeader.h" 

// METHOD IMPLEMENTATIONS 
// helper methods 
void Fraction::CommonDenominator() {
	this->commonDenominator = num * den;
}

// constructors
Fraction::Fraction() {
	this->num = 0;
	this->den = 1;
	CommonDenominator();
}

Fraction::Fraction(int num, int den) {
	this->num = num;
	this->den = den;
	CommonDenominator();
}


// setters 
void Fraction::SetNum(int num) {
	this->num = num;
	CommonDenominator();
}
void Fraction::SetDen(int den) {
	this->den = den;
	CommonDenominator();
}

// getters 
int Fraction::GetNum() {
	return this->num;
}

int Fraction::GetDen() {
	return this->den;
}

int Fraction::GetCommonDenominator() {
	return this->commonDenominator;
}

// operations 
Fraction Fraction::AddFraction(Fraction addMe) {
	// create a temp Fraction 
	Fraction returnMe;
	// add corresponding Fraction components
	if (this->den == addMe.GetDen()) { //checks for same denominator
		returnMe.SetNum(this->num + addMe.GetNum());
		returnMe.SetDen(this->den);
	}
	else { //or else finds gcf and multiplies numerators
		returnMe.SetNum((this->num * addMe.GetDen()) + (addMe.GetNum() * this->den));
		returnMe.SetDen(this->den * addMe.GetDen());
	}
	// return the tempFraction 
	return returnMe;
}

Fraction Fraction::SubtractFraction(Fraction subtractMe) {
	// create a temp Fraction 
	Fraction returnMe;
	// subtract corresponding Fraction components
	if (this->den == subtractMe.GetDen()) {//checks for same denominator
		returnMe.SetNum(this->num - subtractMe.GetNum());
		returnMe.SetDen(this->den);
	}
	else { //or else finds gcf and multiplies numerators
		returnMe.SetNum((this->num * subtractMe.GetDen()) - (subtractMe.GetNum() * this->den));
		returnMe.SetDen(this->den * subtractMe.GetDen());
	}
	// return the tempFraction 
	return returnMe;
}
Fraction Fraction::MultiplyFraction(Fraction multiplyMe) {
	// create a temp Fraction 
	Fraction returnMe;
	// multiply corresponding Fraction components
		returnMe.SetNum(this->num * multiplyMe.GetNum());
		returnMe.SetDen(this->den * multiplyMe.GetDen());
	
	// return the tempFraction 
	return returnMe;
}
Fraction Fraction::DivideFraction(Fraction divideMe) {
	// create a temp Fraction 
	Fraction returnMe;
	// inverses and multiplies corresponding Fraction components
	returnMe.SetNum(this->num * divideMe.GetDen());
	returnMe.SetDen(this->den * divideMe.GetNum());

	// return the tempFraction 
	return returnMe;
}
Fraction Fraction::SimplifyFraction(Fraction simplifyMe) { //simplification
	// create a temp Fraction 
	Fraction returnMe; 
	int num = simplifyMe.GetNum();//holds numerator
	int den = simplifyMe.GetDen();//holds denominator
	int commonFactor1 = 0;
	int commonFactor2 = 0;
	
	// find common factor for numerator and denominator
	if (num > den) { //checks if num is greator than denominator
		for (int i = 2; i <= num; i++) {
			if (num % i == 0 && den % i == 0) {//modulus iterates through to find common factor
				commonFactor1 = i;
				if (commonFactor1 > commonFactor2) {//checks if factor is greatest
					commonFactor2 = commonFactor1;//assigns factor
				}
			}
		}
	}
	else if (den > num) { //checks if den is greator than numerator
		for (int i = 2; i <= den; i++) {
			if (num % i == 0 && den % i == 0) {//modulus iterates through to find common factor
				commonFactor1 = i;
				if (commonFactor1 > commonFactor2) {//checks if factor is greatest
					commonFactor2 = commonFactor1;//assigns factor
				}
			}
		}
	}
	else {
		returnMe.SetNum(simplifyMe.GetNum());//if no common factors, returns simplifyMe as returnMe
		returnMe.SetDen(simplifyMe.GetDen());
		return returnMe;
	}
	if (commonFactor2 != 0) {//ensures denominator is not 0
		returnMe.SetNum(simplifyMe.GetNum() / commonFactor2);//divides num by GCF and sets it
		returnMe.SetDen(simplifyMe.GetDen() / commonFactor2);//divides den by GCF and sets it
	}
	else {
		returnMe.SetNum(simplifyMe.GetNum());
		returnMe.SetDen(simplifyMe.GetDen());
		return returnMe;
	}
}
// display methods 
void Fraction::Display() {
	cout << "<" << this->num << ", " << this->den << ">";
}

//EXTERNAL FUNCTIONS
