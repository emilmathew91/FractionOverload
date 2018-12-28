#include <FractionOverloadHeader.h>
using namespace std;

int main() {
	Fraction myFraction;  //default constructor, points to Fraction::Fraction() in imp
	Fraction myFirstFraction(0, 1);//First Fraction, random data, points to Fraction::Fraction(int, int) in imp
	Fraction mySecondFraction(0, 1);//Second Fraction, random data , points to Fraction::Fraction(int, int) in imp
	Fraction resultFraction;//result Fraction points to Fraction::Fraction() in imp

	cout << "Please enter the first fraction." << endl;
	cin >> myFirstFraction; //input operator

	cout << "Please enter the second fraction." << endl;
	cin >> mySecondFraction; //input operator

	resultFraction = myFirstFraction + mySecondFraction; //addition and assignment operator

	cout << "The first Fraction is < " << myFirstFraction << ">" << endl; //cout
	cout << "The second Fraction is < " << mySecondFraction << ">" << endl; //cout 
	cout << "Fraction one + Fraction two = " << resultFraction << ">" << endl;//cout addition
	cout << endl;
	resultFraction = myFirstFraction - mySecondFraction; //subtraction and assingment operator

	cout << "The first Fraction is < " << myFirstFraction << ">" << endl; //cout
	cout << "The second Fraction is < " << mySecondFraction << ">" << endl;//cout
	cout << "Fraction one - Fraction two = " << resultFraction << ">" << endl;//cout
	cout << endl;
	resultFraction = myFirstFraction * mySecondFraction; //multiplication and assingment operator

	cout << "The first Fraction is < " << myFirstFraction << ">" << endl; //cout
	cout << "The second Fraction is < " << mySecondFraction << ">" << endl;//cout
	cout << "Fraction one * Fraction two = " << resultFraction << ">" << endl;//cout
	cout << endl;
	resultFraction = myFirstFraction / mySecondFraction; //division and assingment operator

	cout << "The first Fraction is < " << myFirstFraction << ">" << endl; //cout
	cout << "The second Fraction is < " << mySecondFraction << ">" << endl;//cout
	cout << "Fraction one / Fraction two = " << resultFraction << ">" << endl;//cout
	cout << endl;

}