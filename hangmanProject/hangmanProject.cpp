// hangmanProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

const int MAX_TRIES = 5;

int Fill(char, string, string&);

int main() {
	system("COLOR B0");
	string name;
	char letter;
	int wrong_guess = 0;
	string word;
	string words[] = {
		"toyota",
		"mazda",
		"honda",
		"bmw",
		"proton",
		"perodua"
	};

	//choose and copy a word from array of words randomly
	srand(time(NULL));
	int n = rand()%10;
	word = words[n];

	//initialize the secret word with the * character.
	string unknown(word.length(), '*');

	// welcome the user
	cout << "\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
	cout << "\n\nWelcome to Hangman Game...Guess a carame";
	cout << "\n\nEach letter is represented by a star.";
	cout << "\n\nYou have to type only one letter in one try";
	cout << "\n\nYou have " << MAX_TRIES << " tries to try and guess the word.";
	cout << "\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";

	// Loop until the guesses are used up
	while (wrong_guess < MAX_TRIES) {
		cout << "\n\n" << unknown;
		cout << "\n\nGuess a letter: ";
		cin >> letter;
		// Fill secret word with letter if the guess is correct
		// otherwise, add 1 to the number of wrong guesses
		if (Fill(letter, word, unknown)==0) {
			cout << endl << "Aiyo, wrong already" << endl;
			wrong_guess++;
		} else {
			cout << endl << "Yay, got something correct already" << endl;
		}
		// check if user guessed the word
		if (word == unknown) {
			cout << word << endl;
			cout << "Yeah! Wooooooo you got it!";
			break;
		}
	}

	if (wrong_guess == MAX_TRIES) {
		cout << "\nSorry, you wrong boy. You have been hanged." << endl;
		cout << "The word was : " << word << ". Stupid." << endl;
	}

	/* Take a one character guess and the secret word, and fill in the
	unfinished guessword. Returns number of characters matched.
	Also, returns zero if the character is already guessed. */

}

int Fill(char guess, string secretword, string& guessword) {
	int i;
	int matches = 0;
	int len = secretword.length();
	for (i = 0; i < len; i++) {
		//Did we already guess this letter in a previous guess?
		if (guess == guessword[i]) {
			return 0;
		}

		if (guess == secretword[i]) {
			guessword[i] = guess;
			matches++;
		}
	}
	return matches;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
