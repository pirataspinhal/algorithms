#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
using namespace std;

void printInfo();
int getScore(int);
double calcAverage(int, int, int);
void printOutput(int, int, int, double);

int main() {
	printInfo();
	int score1, score2, score3;
	double average;
	
	score1 = getScore(1);
	score2 = getScore(2);
	score3 = getScore(3);
	
	average = calcAverage(score1, score2, score3);
	
	printOutput(score1, score2, score3, average);
	
	return 0;
}

void printInfo() {
	cout << "This program prompt the user to enter three Integer score\n";
	cout << "from three different exam within a range of 0 to 50.\n";
	cout << "It will them calculate the average and display it.\n";
}

int getScore(int num) {
	int score;

	while (true) {
		cout << "\nEnter Score" << num << " : ";		
		string scoreStr;
		cin >> scoreStr;		
		
	    bool valid = true;		
		for(int i = 0; i < scoreStr.length(); i++){
			if(!isdigit(scoreStr[i])){
				valid = false;
				break;
			}
		}
		
		if (!valid) {
			cout << "Error: Enter numbers only";
			continue;
		}
		
		stringstream sstream;
		sstream << scoreStr;
		sstream >> score;		
		if (score < 0 || score > 50) {
			cout << "Error: entered test score out of range";
			continue;
		}
		
		break;
	}
	return score;	
}

double calcAverage(int score1, int score2, int score3) {
	double average;
	
	average = (score1 + score2 + score3) / 3;
	
	return average;
}

void printOutput(int score1, int score2, int score3, double average) {
	cout << "Score1  : " << score1 << endl;
	cout << "Score2  : " << score2 << endl;
	cout << "Score3  : " << score3 << endl;
	cout << "Average : " << setprecision(2) << fixed <<  average << endl;
}