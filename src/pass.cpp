#include <iostream>
#include <time.h>
#include <string>

using namespace std;

string userInput();

int main() {
    srand(time(0)); // Seed the random number generator
    
    string phrase = userInput(); // Get user input for the password generation

    return 0; // End of the program
}

string userInput() {
    string phrase;
    cout << "Enter phrase for password generation: ";
    cin >> phrase;
    return phrase; // Return the user input
}