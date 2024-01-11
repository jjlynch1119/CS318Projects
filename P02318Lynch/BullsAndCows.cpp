//Jeremy Lynch, CS318, P02 Bulls and Cows - This program lets you play a guessing game with a 4 digit number

#include <cmath>
#include <ctype.h>
#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

vector<int> generateAnswer(int maxDigits);
void getValidGuess(int maxDigits, vector<int>&);
void getGuesses(vector<int>& answerVec, int maxDigits);
bool hasOnlyDigits(const string s);
bool isUnique(const vector<int>& v);

int main() {
	srand(time(0));
	const int MAX_INT = 4;
	string cont = "";
	vector<int> answerVec;

	cout << "*** P02 Bulls and Cows ***\n\n";

	do {
		cout << "*************New Game*************\n\n";

		cout << "Number to Guess: ";

		answerVec = generateAnswer(MAX_INT);

		for (int i : answerVec)
			cout << i;

		getGuesses(answerVec, MAX_INT);

		cout << "Enter Y to play again (anything else to end): ";
		cin >> cont;
		cout << "\n";

		if (cont != "Y" && cont != "y")

			break;

	} while (true);

	exit(0);
}

vector<int> generateAnswer(int maxDigits) {
	vector<int> answer;
	bool check[10] = { false };
	int random = rand() % 10;

	answer.push_back(random);
	check[random] = true;

	for (int i = 1; i < maxDigits; i++) {
		do {
			random = rand() % 10;
			
		} while (check[random] == true);

		answer.push_back(random);
		check[random] = true;
	}

	return answer;
}

void getValidGuess(int maxDigits, vector<int>& guessVec) {
	string guess;
	bool isValid;
	bool unique;
	bool onlyDigits;
	bool correctLength;
	int count = 0;

	do {
		guessVec.clear();
		isValid = false;
		unique = false;
		onlyDigits = false;
		correctLength = false;

		cout << "\tEnter Guess: ";
		cin >> guess;

		if (!hasOnlyDigits(guess)) {
			cout << "\t\tError: Guess can only contain digits -- try again!\n\n";
			isValid = false;
		}
		else {
			onlyDigits = true;
		}

		if (guess.length() != maxDigits) {
			cout << "\t\tError: Guess must be 4 digits -- try again!\n\n";
			isValid = false;
		}
		else {
			correctLength = true;
		}

		for (int i : guess) {
			guessVec.push_back(i - '0');
		}

		if (!isUnique(guessVec)) {
			cout << "\t\tError: Digits can not be repeated -- try again!\n\n"; 
			isValid = false;
		}
		else {
			unique = true;
		}

		if (onlyDigits && correctLength && unique == true)
			isValid = true;

	} while (!isValid);

}

void getGuesses(vector<int>& answerVec, int maxDigits) {
	bool isValid;
	vector<int> guessVec;

	cout << "\n\n";

	cout << "\tGuesses entered must be digits 0 - 9, 4 digits long, no repetition.\n\n";

	do {
		getValidGuess(maxDigits, guessVec);

		int guessCount = 0;;
		int cows = 0;
		int bulls = 0;
		int answerCheck[10] = { false };
		int guessCheck[10] = { false };
		isValid = false;

		for (int i = 0; i < maxDigits; i++) {
			answerCheck[answerVec.at(i)] = true;
			guessCheck[guessVec.at(i)] = true;
		}

		for (int j = 0; j <= 10; j++) {
			if (answerCheck[j] && guessCheck[j] == true) {
				cows++;
			}
		}

		for (int i = 0; i < maxDigits; i++) {
			if (guessVec.at(i) == answerVec.at(i)) {
					bulls++;
					cows--;
			}
		}
			
		guessCount++;

		cout << "\t\tGuess #" << guessCount << ": Bulls " << bulls << " Cows " << cows << "\n\n";

		if (bulls == maxDigits) {
			cout << "\t*** YOU WIN! ***\n\n";
			isValid = true;
		}

	} while (!isValid);
	
}

bool hasOnlyDigits(const string s) {
	for (char c : s) {
		if (!isdigit(c))
			return false;
	}

	return true;
}

bool isUnique(const vector<int>& v) {
	bool check[10] = { false };

	for (int i : v) {
		if (check[i] == true)
			return false;

		check[i] = true;
	}
	
	return true;
}