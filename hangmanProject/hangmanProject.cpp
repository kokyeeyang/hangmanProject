// hangmanProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

const int MAX_TRIES = 5;

int Fill(char, string, string&) {

}

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
	int n = rand() % 10;
	word = words[n];

	//initialize the secret word with the * character.
	string unknown(word.length(), '*');
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
