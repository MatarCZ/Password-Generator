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

    size_t phraseSize = phrase.size(); // Get the size of the input phrase
    int mapIndex = 0; // Initialize the map index

    for (size_t i = 0; i < phraseSize; i++) {
        phrase.insert(i + mapIndex + 1, string(map[mapIndex / 3 % 7], 3)); // Insert a random character from the map
        mapIndex += 3;
    }

    for (size_t i = 0; i < phrase.size(); i += 4) {
        for (size_t j = 0; j < 7; j++) {
            for (size_t k = 0; k < 3; k++) {
                if (phrase[i] == toupper(map[j][k])) {
                    phrase += to_string(k + 1); // Append the row index of the character
                }
            }
        }
    }

    cout << "Generated password: " << phrase << endl; // Output the generated password

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