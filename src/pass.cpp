#include <iostream>
#include <time.h>
#include <string>

using namespace std;

string userInput();

int main() {
    srand(time(0)); // Seed the random number generator
    
    string phrase = userInput(); // Get user input for the password generation

    char map[7][3] = {
        {'q', 'a', 'z'},
        {'w', 's', 'x'},
        {'e', 'd', 'c'},
        {'r', 'f', 'v'},
        {'t', 'g', 'b'},
        {'y', 'h', 'n'},
        {'u', 'j', 'm'}
    };

    return 0; // End of the program
}

string userInput() {
    string phrase;
    cout << "Enter phrase for password generation (letters only): ";
    cin >> phrase;

    // Validate input and convert to uppercase
    for (size_t i = 0; i < phrase.size(); ++i) {
        if (!isalpha(phrase[i])) {
            cout << "Invalid input. Please enter letters only." << endl;
            return userInput(); // Recursively ask for valid input
        }
        phrase[i] = toupper(phrase[i]); // Convert to uppercase
    }
    return phrase; // Return the validated and converted input
}