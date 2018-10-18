#include <iostream>
#include <sstream>
#include <string>
using namespace std;

void printFraction(const struct Fraction, int);
Fraction getFraction();
Fraction multiply(struct Fraction, struct Fraction);
int validateInt(string);

struct Fraction {
	int num;
	int den;
};

int main() {
	Fraction f1, f2, f3;
	
	f1 = getFraction();
	f2 = getFraction();
	f3 = multiply(f1, f2);
	
	printFraction(f1, 1);
	printFraction(f2, 2);
	
	cout << "\n\nFraction1 * Fraction2 = Fraction3\n";
	printFraction(f3, 3);
	cout << endl << endl;
	
	return 0;
}

void printFraction(const struct Fraction f, int x) {
	cout << "\nFraction" << x << " : " ;
	cout << f.num << "/" << f.den;
}

Fraction getFraction() {
	Fraction f;
	
	f.num = validateInt("Numerator");
	f.den = validateInt("Denominator");
	while (f.den == 0) {
		cout << "Error Denominator cannot be zero" << endl;
		f.den = validateInt("Denominator");

	}
	
	return f;
}

Fraction multiply(struct Fraction f1, struct Fraction f2) {
	Fraction f3;
	
	f3.den = f1.den * f2.den;
	f3.num = f1.num * f2.num;
	
	return f3;
}

int validateInt(string name) {
	int num;
	
	while (true) {
		cout << "\nEnter the " << name << " : ";		
		string numStr;
		cin >> numStr;		
		
	  bool valid = true;		
		for(int i = 0; i < numStr.length(); i++){
			if(!isdigit(numStr[i])){
				valid = false;
				break;
			}
		}
		
		if (!valid) {
			cout << "Error: Enter positive numbers only";
			continue;
		}
		
		stringstream sstream;
		sstream << numStr;
		sstream >> num;		
		if (num < 0 || num > 40000) {
			cout << "Error: number entered is out of range";
			continue;
		}
		
		break;
	}
	
	return num;
}